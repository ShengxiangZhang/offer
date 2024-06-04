#include<iostream>
#include<vector>

/*分糖果Ⅱ*/
using namespace std;

// 模拟分糖果过程
/*
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {       
        vector<int> res(num_people, 0); 
        int i = 0;
        while(candies > 0){
            if(candies >= (i+1)){
                res[i%num_people] += i+1;
                candies  = candies - (i+1);
            } 
            else{
                res[i%num_people] += candies;
                candies = 0;
            }
            i++;
        }
        return res;
    }
};*/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {       
        vector<int> res(num_people, 0); 
        int i = 0;
        while(candies > 0){
            if(candies >= (i+1)){
                res[i%num_people] += i+1;
                candies  = candies - (i+1);
            } 
            else{
                res[i%num_people] += candies;
                candies = 0;
            }
            i++;
        }
        return res;
    }
};