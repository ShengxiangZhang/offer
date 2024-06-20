#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>

/**美丽下标对的数目**/
using namespace std;

/*
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            string stri = to_string(nums[i]);
            for(int j = i +1; j < nums.size(); j++){
                string strj = to_string(nums[j]);
                if(gcd(stri[0]-'0', strj[strj.size()-1]-'0') == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};*/


// 优化，思想：最高位取值1-9，遍历i∈[1-9]，如果i和nums[j]的最后一位互质
// 则把nums[0~j-1]最高位出现过几次i，加到最终结果上
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        vector<int> cnt(10, 0);
        for(int x : nums){
            for( int y = 1; y < 10; y++){
                // 如果之前最高位出现过y，并且y和x%10互质，则累加出现y的次数
                if(cnt[y] > 0 && gcd(y, x % 10) == 1)
                    ans += cnt[y];
            }

            // 记录最高位出现的次数
            while(x >= 10)
                x = x/10;
            cnt[x]++;
        }
        return ans;
    }
};


int main(){
    vector<int> nums = {2,5,1,4};
    Solution s;
    s.countBeautifulPairs(nums);

    return 0;
}