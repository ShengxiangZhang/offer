#include<iostream>
#include<vector>

/**718. 最长重复子数组**/
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j]表示以nums1中第i个元素和nums2中第j个元素结尾的最长子数组长度
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size()));
        int maxLen = 0;

        // 初始化
        for(int j = 0; j < nums2.size();j++){
            if(nums1[0] == nums2[j])
                dp[0][j] = 1;
        }

        for(int i = 0; i < nums1.size();i++){
            if(nums2[0] == nums1[i])
                dp[i][0] = 1;
        }

        // 递推
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    if(i>0 && j>0)
                        dp[i][j] = dp[i-1][j-1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};   

int main(){
    Solution s;
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2  = {3,2,1,4,7};
    int res = s.findLength(nums1, nums2);
    cout << "ss";
    return 0;
}