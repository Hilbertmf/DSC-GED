// https://leetcode.com/problems/shuffle-string/
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = s;
        int length = s.length();
        for(int i=0;i<length;i++)
        {
            result[indices[i]] = s[i];
        }
        return result;
    }
};