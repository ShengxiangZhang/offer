#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
/*637.二叉树的层平均值
给定一个非空二叉树的根节点root,以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受。
*/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            double layer = 0;
            for(int i = 0; i< size; i++){
                TreeNode* cur = que.front();
                que.pop();
                layer += cur->val;
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
            res.push_back(layer/size);
        }
        return res;
    }
};