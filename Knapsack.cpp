//The classical Knapsack problem, you are a thief, and during a robbery, you found N <= 10^4 objects each one having a different value
//but you brought a bag that can only support a weight of W <= 10^4 so you want to find out the largest amount you can make off of this robbery
//Note that the solution isn't as straightforward as a greedy algorithm, for example, sorting by the value of each object and picking the
//most valuable objects won't work with: N = 3, W = 4; (the pairs are given by (weight_i, value_i) where 0 <= i <= N-1) (4, 3) (2 ,2) (2, 2)
//the greedy algorithm would leave us with the pair (4, 3) a total value of 3, but the correct solution would be picking (2, 2) and (2, 2)
//which would give us a total value of 4.
//The quite short yet tricky solution hereby presented requires Dynamic Programming and has a time complexity of O(N*W)

#include <bits/stdc++.h>
#define maxn 10010

using namespace std;

int dp[maxn][maxn], N, W, w[maxn], v[maxn];

int knapsack(int obj, int weight){

    if(obj == N-1){ //if the next object is not on our list and the bag can support the current object's weight, we pick it.

        if(w[obj] <= weight) return dp[obj][weight] = v[obj];

        return dp[obj][weight] = 0;
    }

    if(dp[obj][weight] != -1) return 0;

    //Now we split the problem into two cases:
    //If we pick the i-th object, and if we don't.
    //If we can actually pick it, we just return the maximum between both values,
    //otherwise we return the maximum value we can obtain if we don't pick it.

    int dont_pick = knapsack(obj+1, weight);

    if(w[obj] <= weight){
        int pick = knapsack(obj+1, (weight-w[obj]))+v[obj];

        return dp[obj][weight] = max(dont_pick, pick);
    }

    return dp[obj][weight] = dont_pick;
}

int main() {

    //to prevent our recursive function from calculating the same thing twice and therefore doing more recursive calls,
    //we simply let every value of the matrix be a constant that can't be obtained as a result of random choices
    //for example, in this specific case it's impossible to have any set of items whose values add up to -1

    memset(dp, -1, sizeof(dp));

    cin >> N >> W;

    for(int i = 0; i < N; i++){
        cin >> w[i] >> v[i];
    }

    //We start analyzing the first object and initially we have an empty bag,
    //so the amount of weight the bag can still support is W.

    cout << knapsack(0, W) << "\n";

    return 0;
}
