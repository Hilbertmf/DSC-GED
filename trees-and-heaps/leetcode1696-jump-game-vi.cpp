// https://leetcode.com/problems/jump-game-vi/
#define INF (int)1e9;
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    if(nums.size() == 1)
      return nums[0];
    int dp[100001] = {0};
    dp[0] = nums[0];
    dp[1] = dp[0] + nums[1];
    multiset<int, greater<int>> window;
    window.insert(dp[1]);
    // building my window
    for(int i= 2; i <= k && i < nums.size(); i++) {
      dp[i] = nums[i] + max(dp[0], *window.begin());
      window.insert(dp[i]);
    }
    
    for(int i = k + 1; i < nums.size(); i++) {
      dp[i] = nums[i] + *window.begin(); // max value in window
      // erase only one element
      window.erase(window.find(dp[i - k]));
      window.insert(dp[i]); // sliding window forward
    }
    
    return dp[nums.size()-1];
  }
};