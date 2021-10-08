//Kruskal's Algorithm to find the Minimum Spanning Tree of any Graph
//Basically we sort the edges prioritizing the smallest weight, if the current smallest 
//edge connects 2 nodes that are already linked, i.e. there's a path connecting them,
//then we must skip this edge. We can easily prove that this is the optimal set of choices
//as follows: suppose we don't add the smallest edge to the MST, then take the MST we created
//without that edge, now if we add that edge, we create a cycle, remove any edge (except for the
//smallest edge) from the cycle, the new tree is connected and its total weight is smaller than
//the MST's weight, contradiction. Obviously, we've only proven that the smallest edge must be
//in the MST, but it's easy to note that with a simple induction, one can prove that Kruskal's
//Algorithm in fact works. To check if 2 nodes are connected we use Union-Find.

//Time Complexity: O(m.log n) where m = #edges, n = #nodes

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

void join(int a, int b){

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

    //Since we want the Minimum Spanning TREE it must have exactly (n-1) edges

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
