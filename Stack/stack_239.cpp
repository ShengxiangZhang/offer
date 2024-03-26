#include<iostream>
#include<vector>
#include<queue>
#include<deque>
/****** 滑动窗口最大值*******/
/*给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值*/
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //使用双端队列
        deque<int> q;
        vector<int> res;
        // 构建单调递减的队列
        for(int i = 0; i< k;i++){
            // 如果当前要入队的元素比队尾元素大，则将队尾元素出队，直到队列为空或者队尾元素大于当前元素，这样构建一个单调递减的队列
            while(!q.empty() && nums[i] > q.back())
                q.pop_back();
            q.push_back(nums[i]);
        }

        int count = k;
        while(count <nums.size()){
            res.push_back(q.front());
            // 如果窗口滑动后，从窗口中移除的元素值和队列的出口元素相同，则出队列
            if(nums[count-k] == q.front())
                q.pop_front();
            while(!q.empty() && nums[count] > q.back())
                q.pop_back();
            q.push_back(nums[count]);
            count++;
        }
        res.push_back(q.front());     
        return res;
    }
};
int m239n(){
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums,k);
    for(int i = 0 ; i< res.size();i++){
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}