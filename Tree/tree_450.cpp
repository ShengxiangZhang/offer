#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

// 迭代法
/*class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int dir = -1;
        while(cur){
            if(cur->val == key)
                break;
            else if(cur->val < key){
                pre = cur;
                cur = cur->right;
                dir = 1;
            }                
            else{
                pre = cur;
                cur = cur->left;
                dir = 0;
            }                
        }
        // 五种情况

        // 1. 未找到节点
        if(!cur)
            return root;
        // 2. 要删除的节点的左右都为空
        if(!cur->left && !cur->right){
            if(!pre)
                return nullptr;
            if(dir == 0)
                pre->left = nullptr;
            else
                pre->right = nullptr;
        }
        // 3. 要删除节点的左子树为空，右子树不为空
        else if(!cur->left && cur->right){
            if(!pre)
                root = cur->right;
            else{
                if(dir == 0)
                pre->left = cur->right;
            else
                pre->right = cur->right;

            }
        }
        // 4. 要删除节点的右子树为空，左子树不为空
        else if(cur->left && !cur->right){
            if(!pre)
                root = cur->left;
            else{
                if(dir == 0)
                pre->left = cur->left;
            else
                pre->right = cur->left;
            }
        }
        // 5. 要删除节点的左右都不为空
        else{
            TreeNode* node = cur->right;
            while(true){
                if(!node->left)
                    break;
                node = node->left;
            }
            if(!pre){
                root = cur->right;
                node->left = cur->left;
            }
            else{
                if(dir == 0)
                    pre->left = cur->right;
                else
                    pre->right = cur->right;
                node->left = cur->left;
            }
        }
        return root;
   }
};*/


// 递归法
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)// 1. 没找到要删除的节点，直接返回空
            return root;
        if(root->val == key){ // 找到要删除的节点
            
            if(!root->left && !root->right){// 2. 要删除节点的左右子树都为空，返回空
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr){ // 3. 要删除节点的左子树为空，右子树不为空，返回右子树
                auto retNode = root->right;
                delete root;
                return retNode;
            }
            else if(root->right == nullptr){ // 4. 要删除节点的右子树为空，左子树不为空，返回左子树
                auto retNode = root->left;
                delete root;
                return retNode;
            }
            else{// 5. 要删除节点的左右子树都不为空
                TreeNode* cur = root->right;
                // 找到右子树最左边的节点
                while(cur->left)
                    cur = cur->left;
                // 左子树放置在右子树最左边节点的左子树下
                cur->left = root->left;
                // 返回右子树的根节点
                return root->right;
            }
        }
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        return root;

    }
};