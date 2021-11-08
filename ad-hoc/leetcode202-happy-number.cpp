// https://leetcode.com/problems/happy-number/
class Solution {
public:
  int getSumSquareDigits(int n) {
    int noDigits;
    int power10[10];
    power10[0] = 1;
    for(int i = 1; i < 10; i++)
      power10[i] = power10[i-1]*10;
    
    // discover how many digits
    for(int i = 9; i >= 0; i--) {
      if(n / power10[i] > 0) {
        noDigits = i+1;
        break;
      }
    }
    int digit;
    int sum = 0;
    for(int i = 0; i < noDigits; i++) {
      digit = n % 10;
      sum += digit*digit;
      n /= 10;
    }
    
    return sum; 
  }
  
  bool wasCalculated(vector<int>& nums, int n) {
    for(auto it = nums.begin(); it != nums.end(); it++)
      if(*it == n)
        return true;
    
    return false;
  }
  
  bool isHappy(int n) {
    vector<int> nums;
    
    while(n != 1) {
      nums.push_back(n);
      n = getSumSquareDigits(n);
      if(wasCalculated(nums, n))
        return false;
    }
    return true;
  }
};