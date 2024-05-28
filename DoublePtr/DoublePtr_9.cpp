#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**回文数**/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        // 转化为string类型
        string str = to_string(x);
        // 双指针一前一后移动
        int left = 0;
        int right = str.size()-1;
        while(left < right){
            if(str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};