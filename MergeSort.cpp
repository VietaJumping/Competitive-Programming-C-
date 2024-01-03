#include <bits/stdc++.h>
#define inf 1e9

using namespace std;

void merge_sort(vector < int > &v){

    int s = v.size();

    if(s == 1) return;

    vector < int > v1, v2;

    for(int i = 0; i < s/2; i++){
        v1.push_back(v[i]);
    }
    for(int i = s/2; i < s; i++){
        v2.push_back(v[i]);
    }

    merge_sort(v1);
    merge_sort(v2);

    v1.push_back(inf);
    v2.push_back(inf);

    int p1 = 0, p2 = 0;

    for(int i = 0; i < s; i++){
        if(v1[p1] <= v2[p2]){
            v[i] = v1[p1];
            p1++;
        }
        else{
            v[i] = v2[p2];
            p2++;
        }
    }
}

int main() {

    vector < int > u;

    int n;

    cin >> n;

     for(int i = 0; i < n; i++){
        int x;

        cin >> x;

        u.push_back(x);
     }

     merge_sort(u);

     for(int i = 0; i < n; i++){
         cout << u[i] << " ";
     }

     return 0;
}
