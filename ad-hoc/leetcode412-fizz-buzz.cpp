// https://leetcode.com/problems/fizz-buzz/
class Solution {
public:
  bool isDivisibleBy(int num, int div) {
    return num % div == 0;
  }
  
  vector<string> fizzBuzz(int n) {
    vector<string> answer(n, "");
    
    // answer[0] = '0' + 1;
    for(int i=0; i < n; i++) {
      if(isDivisibleBy(i+1, 3) && isDivisibleBy(i+1, 5))
        answer[i] = "FizzBuzz";
      else if(isDivisibleBy(i+1, 3))
        answer[i] = "Fizz";
      else if(isDivisibleBy(i+1, 5))
        answer[i] = "Buzz";
      else
        answer[i] = to_string(i+1);
    }
    
    return answer;
  }
};