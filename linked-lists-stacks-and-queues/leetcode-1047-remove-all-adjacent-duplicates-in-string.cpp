// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string removeDuplicates(string s) {

    stack<char> st;
    char prev = s[0];
    string res = "";
    st.push(prev);

    for (int i = 1; i < s.size(); i++) {
      st.push(s[i]);
      if(prev == s[i]) {
        st.pop();
        st.pop();
      }
      prev = (!st.empty()) ? st.top() : ' ';
    }
    
    while(!st.empty()) {
      res = st.top() + res;
      st.pop();
    }

    return res;
  }
};