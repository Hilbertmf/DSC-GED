// in this solution we sort as if it's bubble sort. We use the pancake flips to get the greater elements to the end of the vector. It takes 3 flips to put each number in its correct order
#define MID(l, r) (l + (r - l) / 2)
class Solution {
public:
	void flip(vector<int>& arr, int idx) {
		int aux;
		for(int left = 0, right = idx; left <= right; left++, right--) {
			aux = arr[right];
			arr[right] = arr[left];
			arr[left] = aux;
		}
	}

	vector<int> pancakeSort(vector<int>& arr) {
		int greater, mid, greaterIdx, flipIdx, lastIdx;
		
		mid = MID(0, arr.size());
		lastIdx = arr.size() - 1;

		vector<int> sortedArr = arr;
		vector<int> flips;
		
		sort(sortedArr.begin(), sortedArr.end());
		greater = *sortedArr.rbegin();

		while(arr != sortedArr) {
			greaterIdx = find(arr.begin(), arr.end(), greater) - arr.begin();
			
			// flip all besides sorted positions and update greater and last index
      if(greaterIdx == 0) { 
				flipIdx = arr.size() - (arr.size() - lastIdx); // -1
				lastIdx--;
				greater--;
			}
			// flip all besides sorted positions
      else if(greaterIdx > mid) { 
				flipIdx = arr.size() - (arr.size() - lastIdx); // -1
			}
			// flip until greaterIdx
      else {
				flipIdx = greaterIdx;
			}
			flip(arr, flipIdx);
			flips.push_back(flipIdx+1);
		}

		return flips;
	}
};
