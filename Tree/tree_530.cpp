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

class Solution {
public:
    void traversal(TreeNode* root, vector<int>& res){
        if(!root)
            return;
        
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);  
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        int min = INT_MAX;
        for(int i = 1; i < res.size(); i++){
            if(abs(res[i] - res[i-1]) < min)
                min = abs(res[i] - res[i-1]);
        }
        return min;
    }
};