// https://leetcode.com/problems/binary-tree-right-side-view/
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
class Solution {
public:
  int getDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return max(getDepth(root->left), getDepth(root->right)) + 1;
  }

  void levelOrderTraversal(TreeNode* root, vector<int>& nodes, int level) {
    if(root == NULL) return;
    
    level++;
    nodes[level-1] = root->val;
    levelOrderTraversal(root->left, nodes, level);
    levelOrderTraversal(root->right, nodes, level);
  }

  vector<int> rightSideView(TreeNode* root) {
    int depth = getDepth(root);
    vector<int> nodes(depth);
    levelOrderTraversal(root, nodes, 0);
    return nodes;
  }
};