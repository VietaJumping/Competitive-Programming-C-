//Data Structure used to calculate Q queries and C value changes where its given that Q+C = K <= 10^5
//Given that the array has n elements, also considering that on a Fenwick Tree we can perform both operations
//in O(log n) (since we always divide the current integer by a power of 2) the general time complexity is O(K.log n)

//During the explanation of the structure, let v2(k) denote the largest power of 2 that divides k, note that
//v2(k) = k&-k as k = x1x2...xt1000...000 -> v2(k) zeros and -k = 2^31 - k = ((1-x1)(1-x2)...(1-xt)0111...111) =  
//= (1-x1)(1-x2)...(1-xt)with v2(k) zeros.

//To build the tree we basically let every segment of the tree (tree[i]) be the sum of array[i-v2(i)] to array[i]

#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

int tree[maxn], n, a;

//add(k, t) Adds k to the t-th element of the array, in other
//words we add k to tree[t] then tree[t+v2(t)] and so on

void add(int k, int t){

    while(t < n){
        tree[t] += k;
        t += t&-t;
    }
}

//In this specific case, we calculate the sum of the t first elements of the array
//sum(t) = tree[t]+tree[t-v2(t)]+...+tree[0]

int sum(int t){

    int s = 0;

    while(t >= 0){
        s += tree[t];
        t -= t&-t;
    }

    return s;
}
