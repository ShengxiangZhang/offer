#include<iostream>

using namespace std;

/*
给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 大写 ：

如果单词的长度为 1 或者 2 ，所有字母变成小写。
否则，将单词首字母大写，剩余字母变成小写。
请你返回 大写后 的 title 。 
*/
class Solution {
public:
    string capitalizeTitle(string title) {
        int len = title.size();
        int slowIndex = 0;
        int fastIndex = 0;
        while(fastIndex < len)
        {
            if(title[fastIndex] == ' ' || fastIndex == len-1){
                if(fastIndex-slowIndex > 2 || (fastIndex == len-1 && fastIndex-slowIndex ==2 ))
                {   //'A'-'Z'：65-90，'a'-'z':97-122
                    if(title[slowIndex] >= 'a' && title[slowIndex] <= 'z')
                        title[slowIndex] -= 32;
                    slowIndex++;
                }
                while(slowIndex < fastIndex || slowIndex == len-1){
                        if(title[slowIndex] >= 'A' && title[slowIndex] <= 'Z')
                            title[slowIndex] += 32;
                        slowIndex++;
                }
                slowIndex++;
            }
            fastIndex++;
        }
        return title;
    }
};

int m2129n(){
    Solution s;
    string str = "l hV";
    string ans = s.capitalizeTitle(str);
    cout << str;
    system("pause");
    return 0;
}