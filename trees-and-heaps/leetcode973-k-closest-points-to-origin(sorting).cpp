// https://leetcode.com/problems/k-closest-points-to-origin/
// solution using sorting w/ custom comparator
class Solution {
 public:
  struct comparator {
    double calcDist(vector<int>& point) {
      double x = double(point[0]);
      double y = double(point[1]);
      return sqrt(x*x + y*y);
    }

    bool operator()(vector<int>& p1, vector<int>& p2) {
      return calcDist(p1) < calcDist(p2);
    }
  };
  
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> kClosestPoints(k);
    sort(points.begin(), points.end(), comparator());
    
    for(int i = 0; i < k; i++) 
      kClosestPoints[i] = points[i];
    
    return kClosestPoints;
  }
};