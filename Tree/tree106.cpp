#include<iostream>
#include<vector>

using namespace std;

/*给定两个整数数组inorder和postorder，其中inorder是二叉树的中序遍历，postorder是同一棵树的后序遍历，请你构造并返回这颗二叉树 */

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

class Solution {
public:

    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder ){
        if(postorder.size() == 0)
            return nullptr;

        // 取后序序列中最后一位，
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 如果后序序列只有一个节点，直接返回
        if(postorder.size() == 1)
            return root;
        
        // 切割中序序列
        int index = 0;
        for(index; index < inorder.size(); index++){
            if(inorder[index] == rootValue)
                break;
        }
        // 这个切割是左闭右开区间切割[0, index]
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        // 切割后序序列
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        
        return root;  
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0)
            return nullptr;
        return traversal(inorder, postorder);
    }
};