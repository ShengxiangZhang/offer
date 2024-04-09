#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*给你一棵完全二叉树的根节点root，求出该树的节点个数。*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 按照普通二叉树的层次遍历做法，时间复杂度O(n)
/*class Solution {
public:
    int countNodes(TreeNode* root) {
        int num = 0;
        queue<TreeNode*> que;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()){
            int size = que.size();
            num += size;
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
        }
        return num;
    }
};*/

// 递归，利用完全二叉树的特性，完全二叉树和满二叉树关系
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        // 定义两个变量代表最左侧深度和最右侧深度
        int LD = 0;
        int RD = 0;

        //计算最左侧和最右侧深度
        while(leftNode != nullptr){
            LD++;
            leftNode = leftNode->left;
        }
        while(rightNode != nullptr){
            RD++;
            rightNode = rightNode->right;
        }

        // 如果LD和RD相等,说明是当前子树是满二叉树
        if(LD == RD)
            return pow(2, LD + 1) - 1; 
        
        // 递归遍历
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};