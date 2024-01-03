#include <bits/stdc++.h>
#define maxn 100100
#define zero 0

using namespace std;

int tree[4*maxn], v[maxn], lazy[4*maxn];

void update(int node, int i, int j, int idx, int val){

    if(idx < i || idx > j) return;

    if(i == j){
        tree[node] = val;
        return;
    }

    int mid = (i+j)/2;
    int l = 2*node;
    int r = 2*node+1;

    update(l, i, mid, idx, val);
    update(r, mid+1, j, idx, val);

    tree[node] = tree[l]+tree[r];
}

int query(int node, int i, int j, int l, int r){

    if(r < i || l > j) return zero;

    if(l <= i && j <= r) return tree[node];

    int mid = (i+j)/2;
    int left = 2*node;
    int right = 2*node+1;

    int al = query(left, i, mid, l, r);
    int ar = query(right, mid+1, j, l, r);

    return al+ar;
}
