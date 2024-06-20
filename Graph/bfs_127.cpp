#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>

using namespace std;

/**单词接龙**/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> que;
        unordered_map<string, int> visitMap;

        // wordList里不存在endWord
        if(wordSet.find(endWord) == wordSet.end())
            return 0;
        
        que.push(beginWord);

        visitMap.insert(pair<string, int>(beginWord, 1));

        while(!que.empty()){
            string word = que.front();
            que.pop();
            int path = visitMap[word];

            for(int i = 0; i < word.size(); i++){
                string newWord = word;
                for(int j = 0; i < 26; j++){
                    newWord[i] = j + 'a';
                    if(newWord == endWord)
                        return path + 1;
                    if(wordSet.find(newWord) != wordSet.end() && visitMap.find(newWord) == visitMap.end()){
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    } 
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    s.ladderLength("hit", "cog", wordList);
    return 0;
}