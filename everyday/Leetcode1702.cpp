#include<iostream>
#include<string>

using namespace std;


/****修改后的最大二进制字符串****/
class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.size();
        for(int i = 0; i < len; i++){
            int j = i+1;
            if(binary[i] == '0'){
                if(binary[j] == '0'){
                    binary[i] = '1';
                    continue;
                }
                else{
                    int k = len-1;
                    while(k>j){
                        if(binary[k]=='0'&& binary[k-1] == '1'){
                            binary[k] = '1';
                            binary[k-1] = '0';
                        }
                        k--;
                    }
                if(binary[j] == '0'){
                    binary[i] = '1'; 
                }
            }    
        }
    }
    return binary;
    }
};

int main(){
    string str = "000110";
    Solution s;
    string res = s.maximumBinaryString(str);
    return 0;
}