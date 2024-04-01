#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*****N叉树的层次遍历*****/
struct Node{
    int val;
    vector<Node*> children;
    Node(int _x, vector<Node*> _children): val(_x),children(_children){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> que;
        if(root != nullptr)
            que.push(root);
        else
            return res;
        while(!que.empty()){
            vector<int> vec;
            int size = que.size();
            for(int i = 0; i<size; i++){
                Node* cur = que.front();
                que.pop();
                vec.push_back(cur->val);
                for(int j = 0;j<cur->children.size();j++)
                    que.push(cur->children[j]);
            }
            res.push_back(vec);
        }
        return res;
    }
};