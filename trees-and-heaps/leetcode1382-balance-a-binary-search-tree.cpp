// https://leetcode.com/problems/balance-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define MID(l, r) (l + (r - l) / 2)
class Solution {
public:
  void inOrder(TreeNode* root, vector<int>& nodes) {
    if(root == nullptr) return;
    
    inOrder(root->left, nodes);
    nodes.push_back(root->val);
    inOrder(root->right, nodes);
  }
  
  void getTree(TreeNode* root, vector<int>& nodes, int left, int right) {
    if(left > right) return;
    if(root == nullptr) return;
    
    int mid = MID(left, right);
    root->val = nodes[mid];
    if(left <= mid - 1) {
      struct TreeNode* leftNode = new TreeNode();
      root->left = leftNode;
      getTree(root->left, nodes, left, mid - 1);
    }
    if(mid + 1 <= right) {
      struct TreeNode* rightNode = new TreeNode();
      root->right = rightNode;
      getTree(root->right, nodes, mid + 1, right);
    }
  }
  
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;
    inOrder(root, nodes);
    int left = 0, right = nodes.size() - 1;
    int mid = MID(left, right);
    
    struct TreeNode* balancedTree = new TreeNode();
    balancedTree->val = nodes[mid];
    getTree(balancedTree, nodes, left, right);
    
    return balancedTree;
  }
};