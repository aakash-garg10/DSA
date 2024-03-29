// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//RECURSIVE + MEMOIZATION
// Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N)
#include <bits/stdc++.h>

using namespace std;

int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp){

    if(ind == 0)    return N*price[0];
        
    if(dp[ind][N]!=-1)  return dp[ind][N];
        
    int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
    
    int taken = INT_MIN;
    int rodLength = ind+1;
    if(rodLength <= N)
        taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
        
    return dp[ind][N] = max(notTaken,taken);
}

int cutRod(vector<int>& price,int N) {
    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    return cutRodUtil(price,N-1,N,dp);
}

int main() {
  vector<int> price = {2,5,7,8,10};
  int n = price.size();
  cout<<"The Maximum price generated is "<<cutRod(price,n);
}


//TABULATION SOLUTION
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)

#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int>& price,int N) {

    vector<vector<int>> dp(N,vector<int>(N+1,-1));
    
    for(int i=0; i<=N; i++){
        dp[0][i] = i*price[0];
    }
    
    for(int ind=1; ind<N; ind++){
        for(int length =0; length<=N; length++){
        
             int notTaken = 0 + dp[ind-1][length];
    
             int taken = INT_MIN;
             int rodLength = ind+1;
             if(rodLength <= length)
                taken = price[ind] + dp[ind][length-rodLength];
        
             dp[ind][length] = max(notTaken,taken);   
        }
    }
    
    return dp[N-1][N];
}


int main() {

  vector<int> price = {2,5,7,8,10};
  
  int n = price.size();
                                 
  cout<<"The Maximum price generated is "<<cutRod(price,n);
}
