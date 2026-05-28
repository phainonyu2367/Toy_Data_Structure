#include <iostream>
#include <vector>

// Node: will only focus on tree build and traverse
class BinaryTree {
    private:
        struct TreeNode {
            int value;
            TreeNode* left;
            TreeNode* right;
            TreeNode(int val, TreeNode* l=nullptr, TreeNode* r=nullptr): value(val), left(l), right(r) {};
        };
        TreeNode* root;

        void preOrderTraverseHelper(TreeNode* curNode) {
            if (curNode == nullptr) {
                return;
            }
            std::cout << curNode->value << ' ';
            preOrderTraverseHelper(curNode->left);
            preOrderTraverseHelper(curNode->right);
        }

        void postOrderTraverseHelper(TreeNode* curNode) {
            if (curNode == nullptr) {
                return;
            }
            postOrderTraverseHelper(curNode->left);
            postOrderTraverseHelper(curNode->right);
            std::cout << curNode->value << ' ';
        }

        void inOrderTraverseHelper(TreeNode* curNode) {
            if (curNode == nullptr) {
                return;
            }
            inOrderTraverseHelper(curNode->left);
            std::cout << curNode->value << ' ';
            inOrderTraverseHelper(curNode->right);
        }

    public:
        BinaryTree() {
            int size;
            std::cin >> size;
            if (size <= 0) {
                root = nullptr;
                return;
            }

            std::vector<TreeNode*> treeBuildVec(size);
            for (int i = 0; i < size; ++i) {
                treeBuildVec[i] = new TreeNode(0);
            }

            int value, left, right;
            for (int i = 0; i < size; ++i) {
                std::cin >> value >> left >> right;
                treeBuildVec[i]->value = value;

                if (left != -1) {
                    treeBuildVec[i]->left = treeBuildVec[left];
                }

                if (right != -1) {
                    treeBuildVec[i]->right = treeBuildVec[right];
                }
            }

            root = treeBuildVec[0];
        }

        void preOrderTraverse() {
            preOrderTraverseHelper(root);
        }

        void postOrderTraverse() {
            postOrderTraverseHelper(root);
        }

        void inOrderTraverse() {
            inOrderTraverseHelper(root);
        }
};