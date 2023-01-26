// https://leetcode.com/problems/partition-equal-subset-sum/

// Top-Down Approach :

class Solution {
public:
    bool isPossible(vector<int> &nums,vector<vector<bool> > &dp,vector<vector<bool> >& visited,int sum,int index){
        if(index<0 || sum<0)
            return false;
        if(sum==0)
            return dp[sum][index]=true;
        if(visited[sum][index])
            return dp[sum][index];
        visited[sum][index]=true;
        return dp[sum][index]=isPossible(nums,dp,visited,sum,index-1) || isPossible(nums,dp,visited,sum-nums[index],index-1);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum & 1) //if sum is odd
            return false;
        
        //Find if there is subset with sum/2 present in the given array 'nums'
        sum=sum/2;
        vector<vector<bool> > dp(sum+1,vector<bool> (n,false));
        vector<vector<bool> > visited(sum+1,vector<bool> (n,false));
        return isPossible(nums,dp,visited,sum,n-1);
        
    }
};
