#include<iostream>
#include<stack>

using namespace std;

//LeetCode
/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：
你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
*/
class MyQueue {
public:
    //这一题借助两个栈实现一个队列，帮助理解栈和队列的操作
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    
    void push(int x) {
        //将x压入栈中,不返回参数
        stIn.push(x);
    }
    
    int pop() {
        //判断stOut是否为空
        if(stOut.empty()){
            while(!stIn.empty()){
                //top()返回栈顶元素的值
                stOut.push(stIn.top());
                //pop()删除栈顶元素，不返回值
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        int res = this->pop();
        stOut.push(res);
        return res; 
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};