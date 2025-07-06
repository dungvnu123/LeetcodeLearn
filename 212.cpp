#include<bits/stdc++.h>
using namespace std;
using ll =long long;
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& word) {
        int m = board.size();
        int n = board[0].size();
        vector<string>result;
        for(string &x : word){
            bool found = false; // memset cho phan tu ban dau danh dau la false
            vector<vector<bool>>visited(m , vector<bool>(n , false));
            for(int i = 0; i < m &&  !found; i++){
                for(int j = 0 ; j < n && !found; j++){
                    if(dfs(board, visited, i , j, x , 0)){
                        result.push_back(x);
                        found = true;
                    }
                }
            }
        }      
        return result;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,
             int i, int j, string& word, int idx) {
                if(idx == word.size()){
                    return true;
                } 
                int m = board.size();
                int n = board[0].size();
                if( i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[idx]){
                    return false;  
                }
                // bat visit = true
                visited[i][j] = true;
                bool found = dfs(board, visited, i+1, j, word, idx+1) ||
                     dfs(board, visited, i-1, j, word, idx+1) ||
                     dfs(board, visited, i, j+1, word, idx+1) ||
                     dfs(board, visited, i, j-1, word, idx+1);

                     // bat thang vsited = ffalse de backrack 
                     visited[i][j] = false;

                return found;    

             }

};
int main() {
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};

    Solution sol;
    vector<string> result = sol.findWords(board, words);

    cout << "Cac tu tim thay trong board:\n";
    for (const string& word : result) {
        cout << "- " << word << '\n';
    }

    return 0;
}