#include "./shortest_path.h"

GRAPH * create_graph(){
  GRAPH * Graph = (GRAPH*)malloc(sizeof(GRAPH));
  Graph->graph = NULL;
  Graph->number_of_vertices = 0;
  return Graph;
}

NODE * create_node(int vertex){
  NODE * new = NULL;
  new = (NODE*)malloc(sizeof(NODE));
  new->vertex = vertex;
  new->connections = NULL;
  new->next_vertex = NULL;
  return new;
}

LIST_NODE * create_connection(int vertex, int weight){
  LIST_NODE * new = (LIST_NODE*)malloc(sizeof(LIST_NODE));
  new->vertex = vertex;
  new->weights = weight;
  new->next_vertex = NULL;
  return new;
}

GRAPH * add_vertex(GRAPH * G,int vertex){
  NODE * temp = G->graph;
  NODE * prev = NULL;

  if(temp==NULL){
    G->graph = create_node(vertex);
  }
  else{
    while(temp!=NULL){
      prev = temp;
      if(temp->vertex==vertex) return G;
      temp = temp->next_vertex;
    }
    NODE * new = create_node(vertex);
    prev->next_vertex = new;  
  }
  return G;
}

GRAPH * add_connection(GRAPH * G,int vertex,int * connection){
  NODE * temp = G->graph;
  NODE * prev1 = NULL;
  
  while(temp!=NULL){
    prev1 = temp;
    if(temp->vertex==connection[0]){
      break;
    }
    temp = temp->next_vertex;
  }
  
  if(temp==NULL){
    G = add_vertex(G,connection[0]);
    temp = prev1->next_vertex;
  }
  
  LIST_NODE * ptr = temp->connections;
  LIST_NODE * prev = NULL;
  
  if(ptr==NULL){
    temp->connections = create_connection(vertex,connection[1]);
    return G;
  }
  
  while(ptr!=NULL){
    prev = ptr;
    ptr = ptr->next_vertex;
  }
  prev->next_vertex = create_connection(vertex,connection[1]);
  return G;
}

void printGraph(GRAPH * G){
  NODE * temp = G->graph;
  while(temp!=NULL){
    LIST_NODE * ptr = temp->connections;
    printf("Vertex : %d :- ",temp->vertex);
    if(ptr==NULL){
      printf("\n");
    }
    while(ptr!=NULL){
      if(ptr->next_vertex!=NULL)
        printf("(v:%d,w:%d)->",ptr->vertex,ptr->weights);
      else
        printf("(v:%d,w:%d)\n",ptr->vertex,ptr->weights);
      ptr = ptr->next_vertex;
    }
    temp = temp->next_vertex;
  }
}

GRAPH * read(GRAPH * G, char * filename){
  if(filename==NULL){
    printf("File Name not specified!.\n");
    exit(EXIT_FAILURE);
  }

  FILE * fp = NULL;
  fp = fopen(filename,"r");
  
  if(fp==NULL){
    exit(EXIT_FAILURE);
  }
  
  int number_of_vertices = 0;
  fscanf(fp,"%d\n",&number_of_vertices);

  G->number_of_vertices = number_of_vertices;
  
  char * cp_labels[number_of_vertices];
  char buffer[1024];

  int num_actual_vertices = 0;
  for (int i = 0; i < number_of_vertices && fgets(buffer, sizeof(buffer), fp) != 0; i++){
    buffer[strcspn(buffer, "\n")] = '\0';
    cp_labels[i] = strdup(buffer);
    num_actual_vertices += 1;
  }
  
  fclose(fp);
  fp=NULL;

  for (int i = 0; i < num_actual_vertices; i++){
    char * ptr = strtok(cp_labels[i]," ");
    int flag = 0;
    int args[2];
    int index = 0;
    int parent_vertex = 0;
    
    while(ptr!=NULL){
      if(!flag){
        int vertex = atoi(ptr);
        G = add_vertex(G,vertex);
        parent_vertex = vertex;
        flag=1;
        ptr = strtok(NULL," ");
        continue;
      }
      if(ptr!=NULL)
        args[index++] = atoi(ptr);
      ptr = strtok(NULL," ");
      if(index%2==0){
        G = add_connection(G,parent_vertex,args);
        index = 0;
      }
    }
  }
  //freeup memory as graph has been stored in memory as adj list
  for (int i = 0; i < num_actual_vertices; i++){
    free(cp_labels[i]);
    cp_labels[i] = NULL;
  }
  return G;
}

HEAP * create_heap(int length){
  HEAP * new = (HEAP*)malloc(sizeof(HEAP));
  new->Array = (HEAP_NODE**)malloc(sizeof(HEAP_NODE*)*length);
  for(int i=0;i<length;i++) new->Array[i] = NULL;
  new->number_of_elements = 0;
  new->size = length;
  return new;
}

HEAP_NODE * create_heap_node(int vertex,int distance,int predecessor){
  HEAP_NODE * new = (HEAP_NODE*)malloc(sizeof(HEAP_NODE));
  new->vertex = vertex;
  new->d = distance;
  new->p = predecessor;
  return new;
}

HEAP * heap_insert(GRAPH * G,int source_vertex){
  HEAP * heap = create_heap(G->number_of_vertices);
  NODE * temp = G->graph;
  while(temp!=NULL){
    int dist = INF;
    if(temp->vertex==source_vertex) dist = 0;
    HEAP_NODE * new = create_heap_node(temp->vertex,dist,0);
    heap->Array[(heap->number_of_elements)++] = new;
    temp = temp->next_vertex;
    new = NULL;
  }
  for(int i=(heap->number_of_elements-1)/2; i>=0; i--)  heapify(heap,i);
  return heap;
}

void swap_nodes(HEAP_NODE ** A, HEAP_NODE ** B){
  HEAP_NODE * temp = *A;
  *A = *B;
  *B = temp;
}

void heapify(HEAP * heap, int idx){
  int smallest = idx;
  int left = 2*idx + 1;
  int right = 2*idx + 2;

  if(left < heap->number_of_elements && heap->Array[left]->d < heap->Array[smallest]->d) smallest = left;
  if(right < heap->number_of_elements && heap->Array[right]->d < heap->Array[smallest]->d) smallest = right;

  if(smallest!=idx){
    swap_nodes(&(heap->Array[idx]),&(heap->Array[smallest]));
    heapify(heap,smallest);
  }
}

HEAP_NODE * heap_delete(HEAP * heap){
  HEAP_NODE * deleteNode = NULL;
  if(!isEmpty(heap)){
    deleteNode = heap->Array[0];
    heap->Array[0] = heap->Array[heap->number_of_elements-1];
    heap->number_of_elements -= 1;
    heapify(heap,0);
  }
  return deleteNode;
}

int isEmpty(HEAP * heap){
  return heap->number_of_elements==0 ? 1 : 0;
}

void printHeap(HEAP * heap){
  for(int i = 0;i<heap->number_of_elements;i++){
    printf("%d ",heap->Array[i]->vertex);
  }
  printf("\n");
}

HEAP_NODE * extract_min(HEAP * heap){
  return heap_delete(heap);
}

int getHeapIdx(HEAP * heap, int vertex){
  int i = 0;
  for(i=0;i<heap->number_of_elements;i++){
    if(heap->Array[i]->vertex==vertex){
       return i;
    }
  }
  if(i==heap->number_of_elements){
    return -1;
  }
  return 0;
}

HEAP * decrease_key(HEAP * heap,int pre_vertex, int vertex,int distance){
  int idx = getHeapIdx(heap,vertex);
  if(idx==-1) return heap;
  if(distance < heap->Array[idx]->d){
    heap->Array[idx]->d = distance;
    heap->Array[idx]->p = pre_vertex;
    int parent = (idx-1)/2;
    while(heap->Array[parent]->d > heap->Array[idx]->d) {
        swap_nodes(&(heap->Array[parent]),&(heap->Array[idx]));
        idx = parent;
        parent = (idx-1)/2;
    }
  }
  return heap;
}

HEAP * relax(HEAP * heap, HEAP_NODE * extracted_vertex, LIST_NODE * next_vertex, int dist){
  int idx = getHeapIdx(heap,next_vertex->vertex);
  if(idx==-1) return heap;
  int computed_dist = extracted_vertex->d + dist;
  if(heap->Array[idx]->d > computed_dist){
    heap = decrease_key(heap,extracted_vertex->vertex,next_vertex->vertex,computed_dist);
  }
  return heap;
}

void dijkstra(GRAPH * G, int destination_vertex){
  int size = G->number_of_vertices;
  int index = 0;
  
  HEAP_NODE * stack[1023];
  HEAP * heap = heap_insert(G,destination_vertex);

  while(!isEmpty(heap)){
    NODE * temp = G->graph;

    HEAP_NODE * extract = extract_min(heap);
    stack[index++] = extract;
    
    while(temp!=NULL){
      if(temp->vertex==extract->vertex) break;
      temp = temp->next_vertex;
    }
  
    LIST_NODE * ptr = temp->connections;
    while(ptr!=NULL){
      heap = relax(heap,extract,ptr,ptr->weights);
      ptr = ptr->next_vertex;
    }
  }
  print_shortest_path(stack,index);
}

void print_shortest_path(HEAP_NODE ** stack,int index){
  int number_of_vertices = index;
  for(int i=1;i<number_of_vertices;i++){
    HEAP_NODE * v = stack[i];
    int j = i-1;
    while(j>=0 && stack[j]->vertex > v->vertex){
      stack[j+1] = stack[j];
      j -= 1;
    }
    stack[j+1] = v;
  }

  for(int i=0;i<number_of_vertices-1;i++){
    printf("%d ",stack[i]->vertex);
    int j = i;
    int nxt_vertex = stack[i]->p;
    if(nxt_vertex==0){
      printf("NO PATH\n");
      break;
    }
    printf("%d ",stack[i]->vertex);
    while(nxt_vertex-1 < number_of_vertices && nxt_vertex!=0){
      printf("%d ",stack[nxt_vertex-1]->vertex);
      nxt_vertex = stack[nxt_vertex-1]->p;
    }
    printf("%d\n",stack[i]->d);
  }
}