#include <bits/stdc++.h>
#define inf 100100

using namespace std;

int a[100100];

int main() {

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector < int > d(n+1, inf);

    d[0] = -inf;

    for(int i = 0; i < n; i++) {

        int j = upper_bound(d.begin(), d.end(), a[i])-d.begin();

        if(d[j-1] < a[i] && a[i] < d[j]){
            d[j] = a[i];
        }
    }

    for(int i = 0; i <= n; i++){
        if(d[i] == inf){

            cout << (i-1) << "\n";

            return 0;
        }
    }
}
