#include<iostream>
#include<vector>
#include<queue>

/*填充每个节点的下一个右侧节点指针*/
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr){}
};

class Solution {
public:
    Node* connect(Node* root){
        vector<vector<int>> res;
        vector<int> r;
        queue<Node*> que;
        if(root != nullptr)
            que.push(root);
        while(!que.empty()){
            // 每层的节点个数
            int size = que.size();
            for(int i = 0; i<size; i++){
                Node* cur = que.front();
                que.pop();
                if(i<size-1)
                    cur->next = que.front();
                else
                    cur->next = nullptr;
                if(cur->left != nullptr)
                    que.push(cur->left);
                if(cur->right != nullptr)
                    que.push(cur->right);
            }
        }
        return root;
    }
};