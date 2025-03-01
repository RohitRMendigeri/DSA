#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main(){
  int n = 7;
  vector<int> values = {0,9,3,5,8,2,4,7}; // using 1 based indexing 
  vector<int> dp(n+1,0);
  
  dp[0] = 0;
  dp[1] = values[1];

  for(int i = 2 ; i <= n ; i++){
    dp[i] = max(dp[i-1],dp[i-2] + values[i]);
  }

  for(auto it:dp)
  cout << it << " ";
  cout << "\nmaximum value : " << dp[n] << endl;
}