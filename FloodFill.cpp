#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

bool visited[maxn], processed[maxn];

vector < int > neighbors[maxn];

int vertices, edges;

//The time complexity of both algorithms is O(vertices + edges)

//Depth First Search:

void DFS(int u){

    visited[u] = 1;

    for(int i = 0; i < neighbors[u].size(); i++){
        int v = neighbors[u][i];

        if(!visited[v]){
            DFS(v);
        }
    }
}

//Breadth First Search:

void BFS(int v){

    queue < int > q;

    q.push(v);

    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int i = 0; i < neighbors[u]; i++){
           int w = neighbors[u][i];

           if(!processed[u]){
                processed[u] = 1;
                q.push(u);
           }
        }
    }
}
