#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> map;
        // 记录元素出现的位置，map<num,{p1,p2,p3}>
        // num表示元素的值，p1,p2,p3表示元素出现的位置
        for(int i = 0; i < nums.size(); i++)
            map[nums[i]].emplace_back(i);
        
        int max_ans = INT_MIN;
        int ans = 0;
        for(auto& pair : map){
            int j = 0;
            for(int i = 0; i < pair.second.size(); i++){
                while(pair.second[i]-pair.second[j]-(i-j) > k)
                    j++;//左指针右移
                ans = max(ans, i - j + 1);
            }
        }
        return ans;
    }
};


int main(){
    Solution s;
    vector<int> nums = {1,1,2,2,1,1};
    int res = s.longestEqualSubarray(nums, 2);
    cout << res << endl;
    system("pause");
    return 0;
}