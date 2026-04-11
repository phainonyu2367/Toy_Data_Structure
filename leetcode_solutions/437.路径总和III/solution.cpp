#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int count(TreeNode* node, int sum) {
        if (node == nullptr) {
            return 0;
        }
        return (node->val == sum) + count(node->left, sum - node->val) +
                count(node->right, sum - node->val);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        /*Return the amount of paths which sum of the 
          values of the nodes equals to targetSum
          @Parameter:
            - TreeNode* root: root of the tree,
            - int targetSum: expected sum of the path
          @Return:
            - int pathNum: the amount of paths which sum of the 
                           values of the nodes equals to targetSum */
        if (root == nullptr) {
            return 0;
        }
        return count(root, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};
