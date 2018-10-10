#include <bits/stdc++.h>
using namespace std;

struct edges{
    int v1;
    int v2;
    int w;
};

bool compare(edges e1, edges e2){
    return e1.w < e2.w;
}

int parentof(int * vertex, int v1){
    if(v1 != vertex[v1]){
        v1 = parentof(vertex, vertex[v1]);
    }
    return v1;
}

bool hasCycle(int * vertex, int v1, int v2){
    int parentOfv1 = parentof(vertex, v1);
    int parentOfv2 = parentof(vertex, v2);

    return (parentOfv1 == parentOfv2);
}

edges * dijkastra(edges * edge, int v, int e){
    edges * arr = new edges[v-1];

    int count = 0;
    int * parents = new int[v];

    for(int i=0;i<v;i++){
        parents[i] = i;
    }

    int i=0;
    while(count != v-1){
        if(!hasCycle(parents, edge[i].v1, edge[i].v2)){
            arr[count] = edge[i];
            parents[parentof(parents, edge[i].v1)] = parentof(parents, edge[i].v2);
            count++;
        }
        i++;
    }
    return arr;
}

int main() {      
    int v, e;
    cin >> v >> e;

    edges * edge = new edges[e];
    for(int i=0;i<e;i++){
        cin >> edge[i].v1 >> edge[i].v2 >> edge[i].w;
    }
    sort(edge, edge+e, compare);

    edges * tree = dijkastra(edge, v, e);
    cout << endl;
    for(int i=0;i<v-1;i++){
        cout << tree[i].v1 <<" "<< tree[i].v2 <<" "<< tree[i].w << endl;
    }
}

