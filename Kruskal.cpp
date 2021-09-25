//Kruskal's Algorithm to find the Minimum Spanning Tree of any Graph
//O(m.log n) where m = #edges, n = #nodes

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;
typedef pair < int, int > pii;

vector < pair < int, pii > > edges;

int ancestor[maxn], weight[maxn];

int get(int x){

    while(ancestor[x] != x) x = ancestor[x];

    return x;
}

int join(int a, int b){

    a = get(a);
    b = get(b);

    if(weight[a] < weight[b]) swap(a, b);

    ancestor[b] = a;
    weight[a] += weight[b];

}

int main() {

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        ancestor[i] = i;
        weight[i] = 1;
    }

    for(int i = 0; i < m; i++){
        int a, b, w;

        cin >> a >> b >> w;

        edges.push_back(make_pair(w, make_pair(a, b)));
    }

    sort(edges.begin(), edges.end());

    int added_edges = 0, index = 0, total_weight = 0;

    while(true){
        int u = edges[index].second.first;
        int v = edges[index].second.second;

        if(get(u) != get(v)){
            added_edges++;
            total_weight += edges[index].first;

            join(u, v);
        }

        index++;

        if(added_edges == n-1) break;
    }

    cout << total_weight << endl;

    return 0;
}



