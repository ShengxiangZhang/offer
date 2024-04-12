#include<iostream>
#include<vector>
using namespace std;
/*二叉树的最大深度*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        // 如果后序数组大小为0，返回空
        if(postorder.size() == 0)
            return nullptr;

        // 利用后序的最后一个元素构建节点
        int rootvalue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootvalue);

        // 如果后序数组大小为1，则只有一个节点，直接返回
        if(postorder.size() == 1)
            return root;
        
        // 找切割点，切割中序数组
        int index = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[index] == rootvalue);
                break;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        // 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size() + 1, postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};