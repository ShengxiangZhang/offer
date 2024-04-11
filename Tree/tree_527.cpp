#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

/*给你两棵二叉树root和subRoot。检验root中是否包含和subRoot具有相同结构和节点值的子树。如果存在，返回true；否则，返回false 。*/

class Solution {
public:
    bool isornot(TreeNode* root, TreeNode* subroot){
        queue<TreeNode*> que;
        que.push(root);
        que.push(subroot);
        while(!que.empty()){
            TreeNode* cur1 = que.front();
            que.pop();
            TreeNode* cur2 = que.front();
            que.pop();
            // 两个节点都为空，继续
            if(!cur1 && !cur2)
                continue;
            
            // 一个为空,或者两个值不相同
            if(!cur1 || !cur2 || (cur1->val != cur2->val))
                return false;
            
            //按比较顺序入队
            que.push(cur1->left);
            que.push(cur2->left);
            que.push(cur1->right);
            que.push(cur2->right);
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* cur = que.front();
                que.pop();
                if(isornot(cur,subRoot))
                    return true;
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
        }
        return false;
    }
};