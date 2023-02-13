// https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
// BERY SHORT SOLUTION
// https://leetcode.com/problems/coin-change-2/

//RECURSION + MEMOIZATION
// Time Complexity: O(N*T)
// Space Complexity: O(N*T) + O(N)
#include <bits/stdc++.h>

using namespace std;

long countWaysToMakeChangeUtil(vector<int>& arr,int ind, int T, vector<vector<long>>& dp){

    if(ind == 0){
        return (T%arr[0]==0);
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    long notTaken = countWaysToMakeChangeUtil(arr,ind-1,T,dp);
    
    long taken = 0;
    if(arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken + taken;
}


long countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<vector<long>> dp(n,vector<long>(T+1,-1));
    return countWaysToMakeChangeUtil(arr,n-1, T, dp);
}

int main() {

  vector<int> arr ={1,2,3};
  int target=4;
  
  int n =arr.size();
                                 
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
}


//TABULATION

// Time Complexity: O(N*T)
// Space Complexity: O(N*T)
#include <bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(vector<int>& arr, int n, int T){
    
    vector<vector<long>> dp(n,vector<long>(T+1,0));
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
}

int main() {

  vector<int> arr ={1,2,3};
  int target=4;
  
  int n =arr.size();
                                 
  cout<<"The total number of ways is " <<countWaysToMakeChange(arr,n,target);
}

//MOST EASY ANOTHER APPROACH
#include<bits/stdc++.h>

long t[11][2001];
long solve(int i, int value, int *arr, int& n)
{
    if(i >= n) return 0;
    if(value < 0) return 0;
    
    if(value == 0) return 1;
    
    if(t[i][value] != -1)
        return t[i][value];
    
    long notTake = solve(i + 1, value, arr, n);
    long Take = solve(i, value - arr[i], arr, n);
    
    return t[i][value] = (notTake + Take);
    
}
long countWaysToMakeChange(int *arr, int n, int value)
{
    //Write your code here
    memset(t, -1, sizeof(t));
    return solve(0, value, arr, n);
}
