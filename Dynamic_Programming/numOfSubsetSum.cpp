#include<bits/stdc++.h>
using namespace std;

int main(){
  int sum = 11 ;
  int n = 5;
  int arr[5] = {1,3,5,7,10};
  int dp[100][100];

  for(int i = 0; i <= n ; i++){
    dp[0][i] = 0;
  }
  for(int i = 0; i <= n ; i++){
    dp[i][0] = 1;
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= sum ; j++){
      if(arr[i-1] <= j){
        dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << "number of subsets with sum " << sum << " : " << dp[n][sum];
}