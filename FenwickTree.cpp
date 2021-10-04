//Data Structure used to calculate Q queries and C value changes where its given that Q+C = K <= 10^5
//Given that the array has n elements, also considering that on a Fenwick Tree we can perform both operations
//in O(log n) (since we always divide the current integer by a power of 2) the general time complexity is O(K.log n)

#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

int tree[maxn], n;

//Adds t to the k-th element of the array

void add(int k, int t){

    while(t < n){
        tree[t] += k;
        t += t&-t;
    }
}

//In this specific case, we calculate the sum of the k first elements of the array

int sum(int t){

    int s = 0;

    while(t >= 0){
        s += tree[t];
        t -= t&-t;
    }

    return s;
}
