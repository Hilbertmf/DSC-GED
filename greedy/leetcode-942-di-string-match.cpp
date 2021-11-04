// https://leetcode.com/problems/di-string-match/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> diStringMatch(string s) {
    int n = s.size(); 
    s += s[n-1]; // add to indicate last element
    int asc = 0, desc = n;
    vector<int> perm;

    for(int i = 0; i <= n; i++) {
      if(s[i] == 'I')  
        perm.push_back(asc++);
      else 
        perm.push_back(desc--);
    }
    
    return perm;
  }
};