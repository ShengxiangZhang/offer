#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/*
最大二进制奇数  
给你一个 二进制 字符串 s ，其中至少包含一个 '1' 。
你必须按某种方式 重新排列 字符串中的位，使得到的二进制数字是可以由该组合生成的 最大二进制奇数 。
以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。
注意 返回的结果字符串 可以 含前导零
*/

// 遍历两遍字符串
/*class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int len = s.size();
        //1的个数
        int count = 0;
        for(int i = 0; i<len;i++){
            if(s[i] == '1')
                count++;
        }
        int i = 0;
        while(i<len){
            //保正1放在最高位
            if(i < count-1)
                s[i] = '1';
            else{
                //最后一位是1
                if(i == len-1)
                    s[i] = '1';
                else
                    s[i] = '0';
            }
            i++;
        }
        return s;
    }
};*/
//如果只遍历一遍呢
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        //直接构造字符串
        int cnt = count(s.begin(),s.end(),'1');
        return string(cnt-1, '1') + string(s.size()-cnt,'0') + '1';
    }
};