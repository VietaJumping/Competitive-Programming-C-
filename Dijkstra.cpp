//Dijkstra's Algorithm is used to determine the shortest path from a given node A to every other node of the graph
//The Algorithm basically keeps a priority queue updating the minimum distance between a pair of vertices, whenever
//the new path between the current node (v) and A gives a smaller distance "d" than the one stored in an array, the pair
//(-d, v) is put into the priority queue, because we must update the distance for all the nodes connected to v and
//-d as we want to prioritize the smaller distance, as the priority queue prioritizes the larger first element.
//Time Complexity: O(n + m.log m) where m = #edges, n = #nodes.

#include <bits/stdc++.h>
#define inf 1e9
#define maxn 100100

using namespace std;

int dist[maxn];

typedef pair < int, int > pii;

vector < pii > neighbors[maxn];

void Dijkstra(int v){

    priority_queue < pii > pq;

    for(int i = 0; i < maxn; i++) dist[i] = inf;

    dist[v] = 0;

    pq.push(make_pair(0, v));

    while(!pq.empty()){
        
        int d = -pq.top().first;
        int u = pq.top().second;

        pq.pop();

        for(int i = 0; i < neighbors[u].size(); i++){

            int w = neighbors[u][i].first;
            int D = neighbors[u][i].second;

            if(D+dist[u] < dist[w]){

                dist[w] = D+dist[u];
                pq.push(make_pair(-dist[w], w));
            }
        }
    }
}

int main() {

    int m, n;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        
        cin >> a >> b >> c;

        neighbors[a].push_back(make_pair(b, c));
        neighbors[b].push_back(make_pair(a, c));
    }

    int node1, node2;

    cin >> node1 >> node2;

    Dijkstra(node1);

    cout << dist[node2] << endl;

    return 0;
}