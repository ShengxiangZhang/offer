#include<iostream>
#include<vector>
#include<queue>

using namespace std;
/*二叉树的最大深度*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

/*class Solution {
public:

    TreeNode* traversal(vector<int>& nums, int left, int right){
        
        if(left > right)
            return nullptr;
        
        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = traversal(nums, left, mid-1);
        root->right = traversal(nums, mid+1, right);

        return root;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size()-1);
        return root;
    }
};*/

// 迭代法
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        queue<TreeNode*> queNode;
        queue<int> leftPos;
        queue<int> rightPos;
        TreeNode* root = new TreeNode(0);
        queNode.push(root);
        leftPos.push(0);
        rightPos.push(nums.size()-1);
    
        while(!queNode.empty()){
            TreeNode* cur = queNode.front();
            int left = leftPos.front();
            int right = rightPos.front();
            int mid = left + ((right - left) / 2);;
            cur->val = nums[mid];
            queNode.pop();
            leftPos.pop();
            rightPos.pop();
            cur->val = nums[mid];

            if(left <= mid -1){
                cur->left = new TreeNode(0); 
                queNode.push(cur->left);
                leftPos.push(left);
                rightPos.push(mid-1);
            }

            if(mid+1 <= right){
                cur->right = new TreeNode(0);
                queNode.push(cur->right);
                leftPos.push(mid+1);
                rightPos.push(right);
            }
        }
        return root;
    }
};