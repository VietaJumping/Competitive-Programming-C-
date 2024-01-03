#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

int has_cycle = 0, in_deg[maxn], state[maxn];

//directed edges
vector < int > g[maxn], ans;

void DFS(int v){

    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];

        if(!state[u]){
            state[u] = 1;
            DFS(u);
        }

        else if(state[u] == 1){
            has_cycle = 1;
        }
    }

    ans.push_back(v);
    state[v] = 2;
}

//call DFS for each node with in_deg == 0

int main() {

    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;

        cin >> a >> b;

        g[a].push_back(b);
        in_deg[b]++;
    }

    for(int i = 0; i < n; i++){
        if(in_deg[i] == 0) DFS(i);
    }

    if(has_cycle) cout << -1 << endl;

    else{
        reverse(ans.begin(), ans.end());

        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
    }
}

