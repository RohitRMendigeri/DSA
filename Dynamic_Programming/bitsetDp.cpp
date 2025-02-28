#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main(){
  int n;
  cin >> n;
  vector<vector<int>> cost(n,vector<int> (n));
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      cin >> cost[i][j];
    }
  }
  vector<int> dp((1 << n),INF);
  dp[0] = 0;

  for(int mask = 0; mask < 1 << n ; mask++){
    int no = __builtin_popcount(mask);
    for(int bit = 0 ; bit < n ; bit++){
      if((mask & (1 << bit)) == 0){
        // if the bit is 0
        int newMask = (mask | (1 << bit));
        dp[newMask] = min(dp[newMask],dp[mask]+cost[no][bit]);
      }
    }
  }

  int ans = dp[(1 << n) - 1];
  cout << ans << endl;
}