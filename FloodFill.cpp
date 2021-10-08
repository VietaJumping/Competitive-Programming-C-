//BFS: Prioritizes Breadth with respect to the root when processing the nodes
//DFS: Prioritizes Depth with respect to the root when processing the nodes
//The time complexity of both algorithms is O(n+m) where n = #nodes and m = #edges

#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

bool visited[maxn], processed[maxn];

vector < int > neighbors[maxn];

//Depth First Search:

//The array visited basically register when a node is visited, if the current node's
//child hasn't been visited, we do the DFS for the child, if the graph is connected
//it's easy to see that we'll eventually visit all nodes, and we always go straight to
//the deepest node. 

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

//Similarly, the array processed register whether or not a node has been processed during
//the algorithm. If the current node's child hasn't been processed, we push it into the queue, 
//so that we go through all the node's children first, unlike the DFS, showing that the BFS 
//algorithm is indeed a Breadth First Search.

void BFS(int v){

    queue < int > q;

    q.push(v);

    while(!q.empty()){

        int u = q.front();
        q.pop();

        for(int i = 0; i < neighbors[u].size(); i++){
           int w = neighbors[u][i];

           if(!processed[u]){
                processed[u] = 1;
                q.push(u);
           }
        }
    }
}
