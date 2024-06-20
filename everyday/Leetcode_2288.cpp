#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<sstream>
#include<iomanip>

using namespace std;


class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res;
        string str;
        stringstream ss(sentence);
        double d = 1.0 - (discount/100.0);

        // stringstream以空格分隔字符串
        while(ss >> str){
            if(!res.empty())
                res += " ";

            // all_of C++11新特性
            if(str.size() > 1 && str[0] == '$' && all_of(str.begin()+1, str.end(), isdigit)){
                    stringstream s;
                    // fixed << setprecision(2)控制两位小数
                    s << fixed << setprecision(2) << 's' << stoll(str.substr(1)) * d;
                    res += '$' + s.str();
            }
            else{
                res += str;
            }
                
        }
        return res;
    }
};

int main(){
    string sentence = "there are $1 $2 and 5$ candies in the shop";
    Solution s;
    s.discountPrices(sentence, 50);
    system("pause");
    return 0;
}