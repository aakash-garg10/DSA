#include <bits/stdc++.h>
using namespace std;

// Finding Subsequence/subsets of given string
// I / P : = "abc"
// O / P : = "", a, b, c, ab, ac, bc, abc

// Bit Manipulation
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {  //this is basically all the masks of the subset in binary form like 000 ,101 ,110 ,111 etc.
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {   //agar ye waali bit set h toh ise include karenge
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);
    //printing the result
    for(auto v:res){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}