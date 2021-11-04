// https://leetcode.com/problems/count-items-matching-a-rule/
#include <bits/stdc++.h> 
using namespace std;
#define DEBUG(x) cout << #x << " >>>> " << x << endl 
class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int count = 0;
		int keyIdx;
		if(ruleKey == "type")
			keyIdx = 0;
		else if(ruleKey == "color")
			keyIdx = 1;
		else if(ruleKey == "name")
			keyIdx = 2;
		
		for(int i = 0; i < items.size(); i++)
			if(items[i][keyIdx] == ruleValue)
				count++;

		return count;
	}
};