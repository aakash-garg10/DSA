// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=1
//RECURSIVE + MEMOIZATION

// Time Complexity: O(N*T)
// Space Complexity: O(N*T) + O(N)
#include <bits/stdc++.h>
using namespace std;

int minimumElementsUtil(vector<int>& arr, int ind, int Target, vector<vector<int>>& dp){

    if(ind == 0){
        if(Target%arr[0] == 0) return Target/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][Target]!=-1)
        return dp[ind][Target];
        
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,Target,dp);
    
    int taken = 1e9;
    if(arr[ind] <= Target)
        taken = 1 + minimumElementsUtil(arr,ind,Target-arr[ind],dp);
        
    return dp[ind][Target] = min(notTaken,taken);
}


int minimumElements(vector<int>& arr, int Target){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(Target+1,-1));
    int ans =  minimumElementsUtil(arr, n-1, Target, dp);
    if(ans >= 1e9) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3};
  int Target=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,Target);
}


//TABULATION METHOD

// Time Complexity: O(N*T)
// Space Complexity: O(N*T)
#include <bits/stdc++.h>

using namespace std;

int minimumElements(vector<int>& arr, int T){
    
    int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
    
    for(int i=0; i<=T; i++){
        if(i%arr[0] == 0)  
            dp[0][i] = i/arr[0];
        else dp[0][i] = 1e9;
    }
    
    for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=T; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(arr[ind]<=target)
                take = 1 + dp[ind][target - arr[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][T];
    if(ans >=1e9) return -1;
    return ans;
}

int main() {

  vector<int> arr ={1,2,3};
  int T=7;
                                 
  cout<<"The minimum number of coins required to form the target sum is " 
  <<minimumElements(arr,T);
}





