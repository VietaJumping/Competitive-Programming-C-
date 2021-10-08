//Binary Search is an algorithm used to determine whether an element is in a sorted array or not
//it has a fairly small time complexity, and it can come in handy in other situations, making it
//a must-learn tool for competitive programmers.
//Time Complexity: O(log n), where n = array.size()

//Since the array is already sorted, we can do the following: Keep 2 points l and r
//let k be the element we are currently analyzing, so we want to find i in [0, n-1]
//such that k = a[i]. Let (l+r)/2 = mid, if k > a[mid] we now set l = mid, so we have
//decreased the size of the interval we're looking for by half and we know that i is
//inside [mid, r] by Hypothesis. Similarly, if k < a[mid], set r = mid so i is inside
//[l, mid] therefore we do at most (log n) iterations, until we find i s.t. k = a[i]
//or we "prove" that there's no such i.

//Another way to solve this problem is using Coordenate Compression (since a[i] could 
//be larger than 10^9 or something like that) and using an array to register every 
//integer inside the array.

#include <bits/stdc++.h>
#define maxn 100100

using namespace std;

int a[maxn], n, d[maxn];

int BinarySearch(int k){

    int l = 1, r = n;

    while(l <= r){

        int mid = (l+r)/2;

        if(r-l == 1){ //if you have [l, l+1] then mid = l so we keep the same interval, and that's a loop we want to avoid
            if(a[r] == k) return r;
            if(a[l] == k) return l;

            return -1;
            
        }
    
        if(a[mid] < k) l = mid;

        else if(k < a[mid]) r = mid;

        else return mid;

        if(l == r) return -1; //in case there's no such i satisfying a[i] = k;
    }
}
