#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;
set<vector<string>> seen; // lưu các cách chia đã có
priority_queue<string> pq; // hàng đợi ưu tiên max-heap
void backtrack(const string& word, int pos, int numFriends, vector<string>& current) {
    if (current.size() == numFriends) {
        if (pos == word.size()) {
            if (seen.count(current) == 0) {
                seen.insert(current);
                for (const string& s : current) {
                    pq.push(s);
                }
            }
        }
        return;
    }

    for (int i = pos + 1; i <= word.size(); ++i) {
        string part = word.substr(pos, i - pos);
        current.push_back(part);
        backtrack(word, i, numFriends, current);
        current.pop_back();
    }
}

string getMaxLexString(string word, int numFriends) {
    seen.clear();
    while (!pq.empty()) pq.pop();

    vector<string> current;
    backtrack(word, 0, numFriends, current);

    if (pq.empty()) return "";

    return pq.top(); // trả về chuỗi lớn nhất theo thứ tự từ điển
}
int main() {
    string word = "abcdfesgf";
    int numFriends = 2;
    cout << getMaxLexString(word, numFriends) << endl; // Output: "c"
    return 0;
}
