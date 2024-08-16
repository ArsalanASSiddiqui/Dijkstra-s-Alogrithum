#include <iostream>
#include <vector>
using namespace std;
#include <climits>
#include <set>

class graph{
  public:
  int V;
  vector<pair<int,int>>* adj;
  graph(int V){
      this->V=V;
      adj = new vector<pair<int,int>>[V];
  }
  public:
  void edg(int u , int v, int w){
      adj[u].push_back(make_pair(v, w)); 
      adj[v].push_back(make_pair(u, w)); 
      //std::cout << "source : Destination : Cost " << u << " : "<< v << " : " << w << std::endl;
  }
  public:
  void dijkfunction(int src){
    set<pair<int, int>> pq;
    vector<int> dist(V, INT_MAX); 

    pq.insert(make_pair(0, src)); 
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                pq.erase(make_pair(dist[v], v));
                dist[v] = dist[u] + weight;
                pq.insert(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << i << " is not reachable from the source." << endl;
        } else {
            cout << "Distance from source to vertex " << i << " is " << dist[i] << endl;
        }
    }

  }
};
 
int main()
{
    
    
    
    graph g(14);
    g.edg(0,1,4);
    g.edg(0,7,8);
    g.edg(1,2,8);
    g.edg(1,7,11);
    g.edg(2,3,7);
    g.edg(2,5,4);
    g.edg(2,8,2);
    g.edg(3,4,9);
    g.edg(3,5,14);
    g.edg(4,5,10);
    g.edg(5,6,2);
    g.edg(6,7,1);
    g.edg(6,8,6);
    g.edg(7,8,7);
    
    int src = 0;
    g.dijkfunction(src);
    
    //dfs(2);
    


    std::cout<<"Hello World";
 
    return 0;
}