#include <iostream>
#define max 6
using namespace std;

// sssp algorithm using dijkstra's algorithm
float sssp(int G[max][max], int n, int s){
    int distances[n+1];
    bool visited[n+1];
    int prev[n+1];
    
    float avg_time = 0; // average time taken from source city to the other cities

    // initialize distances and visited arrays
    for(int i = 0; i < n; i++){
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    distances[s] = 0; // set distance of source to 0

    // dijkstra's algorithm
    for(int i = 0; i < n-1; i++){
        int min_distance = INT_MAX;
        int min_index;

        //finding the unvisited vertex with minimum distance
        for(int v = 0; v < n; v++){
            if(visited[v] == false && distances[v] <= min_distance){
                min_distance = distances[v];
                min_index = v;
            }
        }

        // mark the min_index as visited
        visited[min_index] = true;

        // update the distances and previous cities
        for(int v = 0; v < n; v++){
            if(!visited[v] && G[min_index][v]){
                if(distances[v] > distances[min_index] + G[min_index][v]){
                    distances[v] = distances[min_index] + G[min_index][v];
                    prev[v] = min_index;
                }
            }
        }

        
    }
    
    cout << "source city = " << s << endl;
    // printing the distances and previous city
    for(int i = 0; i < n; i++){

        if(i == s) continue; // skip the source city

        cout << "time taken from " << s << " to " << i << " = " << distances[i] << endl;
        
        avg_time += distances[i]; // adding the distance(time) to the average time

        // printing the path
        int prev_city = i;
        while(prev_city != s){
            cout << prev_city << " <- ";
            prev_city = prev[prev_city];
        }
        cout << s << endl;
    }

    avg_time /= (n-1); // calculating the average time

    cout << "average time = " << avg_time << endl;
    // cout << endl;

    return avg_time;
}


int main(){
    // Adjacency Matrix
    int graph[6][6] = {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };

    float minimum_avg_time = INT_MAX;
    int minimum_avg_source_city;

    // shortest distances from all cities to all cities
    for (int i = 0; i < max; i++){
        float avg = sssp(graph, 6, i);

        if(avg < minimum_avg_time){
            minimum_avg_time = avg;
            minimum_avg_source_city = i;
        }

        cout << endl;
    }

    cout << endl;
    cout << "minimum average time = " << minimum_avg_time << endl;
    cout << "city = " << minimum_avg_source_city << endl;
    
}