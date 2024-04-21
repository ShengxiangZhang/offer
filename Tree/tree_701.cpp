#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*给定二叉搜索树（BST）的根节点root和要插入树中的值value，将值插入二叉搜索树。返回插入后二叉搜索树的根节点。 输入数据保证，新值和原始二叉搜索树中的任意节点值都不同。*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

// 迭代法
/*
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode *cur = new TreeNode(val);
            return cur;
        }
        TreeNode* cur = root;
        // 记录前一个节点
        TreeNode* pre = root;
        int dir = -1;
        while(true){
            if(cur == nullptr){
                TreeNode* newNode = new TreeNode(val);
                if(dir == 0)
                    pre->left = newNode;
                if(dir == 1)
                    pre->right = newNode;
                break;
            }
            else if(val < cur->val){
                pre = cur;
                cur = cur->left;
                dir = 0;
            }
            // if else，不能偷懒都写if,否则会出问题
            else if(val > cur->val){
                pre = cur;
                cur = cur->right;
                dir = 1;
            }        
        }
        return root;
    }
};*/

// 递归法

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            TreeNode* cur = new TreeNode(val);
            return cur;
         }
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        else if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};