// https://leetcode.com/problems/longest-increasing-subsequence/

// USING BINARY SEARCH
// Time Complexity: O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}


//RECURSIVE + MEMOIZATION GIVES TLE BECAUSE OF 10^5 SIZE CONSTRAINTS
// Time Complexity: O(n^2)

#include <bits/stdc++.h>
int f(int ind, int prev_ind, int arr[], int n,
      vector<vector<int>> &dp)
{
    if (ind == n) return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
        
    int len = 0 + f(ind + 1, prev_ind, arr, n, dp);
    if (prev_ind == -1 || arr[ind] > arr[prev_ind])
    {
        len = max(len, 1 + f(ind + 1, ind, arr, n, dp));
    }
    return dp[ind][prev_ind + 1] = len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, arr, n, dp);
}