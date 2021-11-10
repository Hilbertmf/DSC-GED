// https://leetcode.com/problems/k-closest-points-to-origin/
// solution using heap(priority_queue)
class Solution {
 public:
  
  struct comparator {
    double calcDist(vector<int>& point) {
      double x = double(point[0]);
      double y = double(point[1]);
      return sqrt(x*x + y*y);
    }

    bool operator()(vector<int>& p1, vector<int>& p2) {
      return calcDist(p1) > calcDist(p2);
    }
  };
  
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> KClosestPoints(k);
    priority_queue<vector<int>, vector<vector<int>>, comparator> pointsByDist;
    
    for(int i = 0; i< points.size(); i++) {
      pointsByDist.push(points[i]);
    }
    
    int i = 0;
    while(!pointsByDist.empty() && k--) {
      KClosestPoints[i] = (pointsByDist.top());
      pointsByDist.pop();
      i++;
    }
    return KClosestPoints;
  }
};