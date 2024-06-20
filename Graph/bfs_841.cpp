#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // 记录门是否被打开过
        vector<bool> opened(rooms.size(), false);
        opened[0] = true;

        // 房间0没有上锁，将房间0里面的key取出
        queue<int> que;
        if(rooms[0].size() == 0)
            return false;
        for(int key : rooms[0])
            que.push(key);

        while(!que.empty()){
            // 逐个取出key
            int key = que.front();
            que.pop();
            // 如果门已经被打开过，忽略
            if(opened[key] == true)
                continue;
            // 开门，取出钥匙
            opened[key] = true;
            for(int newKey : rooms[key])
                que.push(newKey);
        }
        for(bool open : opened){
            if(open == false)
                return false;
        }
        return true;
    }
};