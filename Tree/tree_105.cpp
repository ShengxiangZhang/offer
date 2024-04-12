#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*给定两个整数数组 preorder和inorder，其中preorder是二叉树的先序遍历，inorder是同一棵树的中序遍历，请构造二叉树并返回其根节点。*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};


class Solution {
public:

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size() == 0)
            return nullptr;
        
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        
        if(preorder.size() == 1)
            return root;

        int index = 0;
        for(index; index < inorder.size(); index++){
            if(inorder[index] == rootValue)
                break;
        }

        // 切割中序
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        reverse(preorder.begin(), preorder.end());
        preorder.resize(preorder.size() - 1);
        reverse(preorder.begin(), preorder.end());

        // 切割前序
        vector<int> leftPreordeer(preorder.begin(), preorder.begin() + leftInorder.size());
        vector<int> rightPreordeer(preorder.begin() + leftInorder.size(), preorder.end());

        root->left = traversal(leftPreordeer, leftInorder);
        root->right = traversal(rightPreordeer, rightInorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0)
            return nullptr;
        return traversal(preorder, inorder);
    }
};  
