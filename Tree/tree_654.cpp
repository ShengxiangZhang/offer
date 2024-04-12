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

// 这题和两种遍历确定一个树的方法一致
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        int max = INT_MIN;
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }

        // 创建节点
        TreeNode* root = new TreeNode(max);
        if(nums.size() == 1)
            return root;
        // 切割
        vector<int> leftNums(nums.begin(), nums.begin() + index);
        vector<int> rightNums(nums.begin() + index + 1, nums.end());

        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};