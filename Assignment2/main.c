#include "./shortest_path.h"

int main(){
  GRAPH * G = create_graph();
  G = read(G,"./adjlist3.txt");
  dijkstra(G,G->number_of_vertices);
  destroy_graph(G);
  return 0;
}