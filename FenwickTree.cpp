#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

int tree[maxn], n;

//adds t to the k-th element of the array
//O(log n)

void add(int k, int t){

    while(t < n){
        tree[t] += k;
        t += t&-t;
    }
}

//query for the sum of the k first elements of the array
//O(log n)

int sum(int t){

    int s = 0;

    while(t >= 0){
        s += tree[t];
        t -= t&-t;
    }

    return s;
}
