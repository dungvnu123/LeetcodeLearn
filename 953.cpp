#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>max_heap(26, 0);
        for(const string&word : words2){
            vector<int>freg(26, 0);
            for(char c : word){
                freg[c - 'a']++;
            }
           
            for(int i = 0 ; i <  26; i++){
                max_heap[i] =  max(max_heap[i], freg[i]);
            }
        } 
        vector<string>res;
        bool ok = true;
        for(const string & word : words1){
            vector<int>freg(16, 0);
            for(char c : word){
                freg[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(freg[i] < max_heap[i]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                res.push_back(word);
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};

    vector<string> result = sol.wordSubsets(words1, words2);
    for (const string& word : result) {
        cout << word << endl;
    }
    return 0;
}