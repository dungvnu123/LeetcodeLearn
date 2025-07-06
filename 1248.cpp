#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> visited(n, false);  // Hộp đã mở chưa
        vector<bool> hasFind(n, false);  // Hộp đã tìm thấy chưa
        vector<bool> hasKey(n, false);   // Có chìa khóa mở hộp chưa
        queue<int> q;

        // Đánh dấu và đẩy các hộp ban đầu vào
        for (int box : initialBoxes) {
            hasFind[box] = true;
            if (status[box] == 1) {
                q.push(box);
                visited[box] = true;
            }
        }

        int total_candy = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            total_candy += candies[box];

            // Lấy chìa khóa từ hộp này
            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    // Nếu đã tìm thấy hộp nhưng chưa mở được vì chưa có chìa
                    if (hasFind[key] && !visited[key] && status[key] == 0) {
                        q.push(key);
                        visited[key] = true;
                    }
                }
            }

            // Lấy hộp bên trong
            for (int newBox : containedBoxes[box]) {
                if (!hasFind[newBox]) {
                    hasFind[newBox] = true;
                    // Nếu hộp mở sẵn hoặc có chìa thì mở luôn
                    if ((status[newBox] == 1 || hasKey[newBox]) && !visited[newBox]) {
                        q.push(newBox);
                        visited[newBox] = true;
                    }
                }
            }
        }

        return total_candy;
    }
};

int main() {
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};

    Solution sol;
    cout << "Tong so keo lay duoc la: " << sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;
    return 0;
}
