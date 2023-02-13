// https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=3

// T.C.: O(n^2)

int findNumberOfLIS(vector<int> &nums)
{
	int n = nums.size();
	vector<int> dp(n, 1), count(n, 1);

	int maxi=1;
	for(int i=0;i<n;i++){
		for(int prev = 0;prev<i;prev++){
			if(dp[i]<dp[prev]+1 and nums[i]>nums[prev]){
				dp[i] = dp[prev]+1;
				count[i] = count[prev];
			}
			else if(dp[i]==dp[prev]+1 and nums[i]>nums[prev]){
				count[i]+=count[prev];
			}
		}
		maxi = max(maxi, dp[i]);
	}
	int nLIS = 0;
	for(int i=0;i<n;i++){
		if(dp[i]==maxi) nLIS += count[i];
	}
	return nLIS;
}