#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_): val(val_), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int res;
    int traversal(TreeNode* cur){

    }


    int minCameraCover(TreeNode* root) {
        res = 0;
        traversal(root);
    }
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {

    }
};