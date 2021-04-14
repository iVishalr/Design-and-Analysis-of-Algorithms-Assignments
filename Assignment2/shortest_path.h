#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define INF INT_MAX

typedef struct adj_list_node{
  unsigned int vertex;
  unsigned int weights;
  struct adj_list_node * next_vertex;
}LIST_NODE;

typedef struct adj_list_vnode{
  unsigned int vertex;
  LIST_NODE * connections;
  struct adj_list_vnode * next_vertex;
}NODE;

typedef struct graph{
  NODE * graph;
  int number_of_vertices;
}GRAPH;

typedef struct heap_node{
  unsigned int vertex;
  unsigned int d;
  unsigned int p;
}HEAP_NODE;

typedef struct heap{
  HEAP_NODE ** Array;
  int number_of_elements;
  int size;
}HEAP;

#ifdef __cplusplus
extern "C"{
#endif
  GRAPH * create_graph();
  GRAPH * read(GRAPH * G,char * filename);
  
  NODE * create_node(int vertex);
  LIST_NODE * create_connection(int vertex, int weight);
  
  GRAPH * add_connection(GRAPH * G,int vertex,int * connection);
  GRAPH * add_vertex(GRAPH * G,int vertex);
  
  HEAP * create_heap();
  HEAP_NODE * create_heap_node(int vertex,int distance,int predecessor);
  HEAP * heap_insert(GRAPH * G,int source_vertex);
  HEAP_NODE * heap_delete(HEAP * heap);
  void heapify(HEAP * heap, int idx);
  
  void swap_nodes(HEAP_NODE ** A, HEAP_NODE ** B);
  int isEmpty(HEAP * heap);
  int getHeapIdx(HEAP * heap, int vertex);
  
  HEAP_NODE * extract_min(HEAP * heap);
  HEAP * decrease_key(HEAP * heap,int pre_vertex, int vertex,int distance);
  HEAP * relax(HEAP * heap, HEAP_NODE * extracted_vertex, LIST_NODE * next_vertex, int dist);
  void dijkstra(GRAPH * G, int destination_vertex);
  
  void printGraph(GRAPH * G);
  void printHeap(HEAP * heap);
  void print_shortest_path(HEAP_NODE ** stack,int index);
#ifdef __cplusplus
}
#endif

#endif //SHORTEST_PATH_H