#include "./shortest_path.h"

int main(){
  GRAPH * G = create_graph();
  G = read(G,"./adjacencylist.txt");
  dijkstra(G,G->number_of_vertices);
  return 0;
}