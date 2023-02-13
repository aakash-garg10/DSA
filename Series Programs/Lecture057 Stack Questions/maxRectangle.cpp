class Solution {
public:
  int maxAreaHistogram(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
          //i==n is used to check the last element
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())   width = i;
          else  width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
  }
    //DRIVER FUNCTION
    int maximalRectangle(vector<vector<char>>& grid) {
         int m = grid.size(), n = grid[0].size(), res = 0;
    vector<int> histogram(n, 0);
    for(int i=0; i<m; i++){
        //we are stacking up '1's to make histogram
        for(int j=0; j<n; j++){
            if(grid[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }
        //check area each time, cuz you need area even at smaller 1x blocks
        res = max(res, maxAreaHistogram(histogram));
    }
    return res;   
    }
};