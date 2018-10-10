#include <bits/stdc++.h>
using namespace std;

int findmin(bool * visited, int * weight, int v){
    int m = INT_MAX, idx = -1;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(m > weight[i]){
                m = weight[i];
                idx = i;
            }
        }
    }

    return idx;
}


void prims(int ** adj, bool visited[], int parent[], int weight[],  int v, int e){
    weight[0] = 0;
    parent[0] = -1;
    for(int i=1;i<v;i++){
        weight[i] = INT_MAX;
    }

    for(int i=0;i<v;i++){
        visited[i] = false;
    }


    for(int j=0;j<v;j++){
        int u = findmin(visited, weight, v);
        visited[u] = true;

        for(int i=0;i<v;i++){
            if(visited[i] || adj[u][i] == -1){
                continue;
            }
            
            if(weight[i] > adj[u][i]){
                weight[i] = adj[u][i];
                parent[i] = u;
            }
        }
    }

}

int main() {      
    int v,e;
    cin >> v >> e;

    int ** adj = new int*[v];
    bool visited[v];
    int parent[v];
    int weight[v];

    for(int i=0;i<v;i++){
        adj[i] = new int[v];

        for(int j=0;j<v;j++){
            adj[i][j] = -1;
        }
    }    

    for(int i=0;i<e;i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        adj[v1][v2] = w;
        adj[v2][v1] = w;
    }

    prims(adj, visited, parent, weight, v, e);
    for(int i=0;i<v;i++){
        cout << i << " " << parent[i] << " " << weight[i] << endl;
    }
}