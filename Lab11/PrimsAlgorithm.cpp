#include<iostream>
using namespace std;

#define V 6

// find the vertex with minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool visited[]){
    int min = INT_MAX;
    int min_index;

    // find the vertex with minimum key value
    for(int i = 0; i < V; i++){
        if(visited[i] == false && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    
    return min_index;
}

// prim's algorithm
void prims(int G[V][V], int s){
    int key[V];
    bool visited[V];
    int parent[V];

    // initialize key and visited arrays
    for(int i = 0; i < V; i++){
        key[i] = INT_MAX;
        visited[i] = false;
    }

    // set the source vertex key to 0
    key[s] = 0;
    // set the parent of source vertex to -1(because it is the root)
    parent[s] = -1; 

    // prim's algorithm
    for(int i = 0; i < V-1; i++){
        int u = minKey(key, visited);
        visited[u] = true;
        for(int v = 0; v < V; v++){
            // if there is an edge from u to v and v is not visited and the weight of the edge is less than the key of v
            if(G[u][v] && visited[v] == false && G[u][v] < key[v]){
                parent[v] = u;
                key[v] = G[u][v];
            }
        }
    }

    // print the MST
    for(int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << " => " << G[i][parent[i]] << endl;
    }

}

int main(){
    int graph[V][V] = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    prims(graph, 0);

    return 0;
}