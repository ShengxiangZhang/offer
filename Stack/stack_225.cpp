#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//LeetCode225
/*
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
*/
//用两个队列实现一个栈
/*

class MyStack {
public:

    queue<int> que1;
    queue<int> que2;

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int len = que1.size();
        len--;
        while(len--){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();

        while(!que2.empty()){
            que1.push(que2.front());
            que2.pop();
        }
        return result;
    }
    
    int top() {
        int result = this->pop();
        que1.push(result);
        return result;
    }
    
    bool empty() {
        return que1.empty();
    }
};
*/

class MyStack {
public:
    //用一个队列模拟栈
    queue<int> que;

    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int len = que.size();
        len--;
        //每次将出队元素再添加到队列尾部
        while(len--){
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        int result = this->pop();
        que.push(result);
        return result;
    }
    
    bool empty() {
        return que.empty();
    }
};