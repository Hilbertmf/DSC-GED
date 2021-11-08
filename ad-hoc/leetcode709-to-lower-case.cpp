// https://leetcode.com/problems/to-lower-case/
class Solution {
public:
  string toLowerCase(string s) {
    string lowerStr = s;
    int diff = 'a' - 'A';
    for(int i = 0; i < s.length(); i++) {
      
      if(s[i] >= 'A' && s[i] <= 'Z')
        lowerStr[i] = s[i] + diff;
    }
    
    return lowerStr;
  }
};