#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution{
    public:

     int  minimumDeletions(string word, int k){
        // tao 1 cai map de dem so lan xuat hien phan tu 
        unordered_map<char, int> freqMap;
        for(char x : word){
            freqMap[x]++;
        }
        vector<int> freq;
        for(auto &c : freqMap){
            freq.push_back(c.second);
        }
        sort(freq.begin(), freq.end());
        // khoi tao gia tri nho nhat la gia tri lon nhat co the cua chuoi 
        int minDel = word.size();
        for(int i = 0; i < freq.size(); i++){
            // lay gia tri nho nhat la gia tri dau tien neu nho qua xoa bo 
            int min_key = freq[i];
            int max_key = min_key + k;
            int deletion = 0; // ban dau chua xoa cai gi 
            for (auto &f : freq){
                if(f < min_key){
                    deletion += f;
                }
                else if(f > max_key){
                    deletion += f - max_key;  // ⚠ Bạn bị thiếu dấu chấm phẩy ở đây
                }
            }
            minDel = min(minDel, deletion);
        }
        return minDel;
     }
};

int main(){
    int t; 
    cout << "Nhap vao so luong test case: " << endl;
    cin >> t;
    cin.ignore(); // bỏ dòng enter sau khi nhập t

    while(t--){
        string word;
        cout << "Nhap vao chuoi: " << endl;
        getline(cin, word);

        int k;
        cout << "Nhap vao gia tri k: " << endl;
        cin >> k;
        cin.ignore(); // bỏ dòng enter sau khi nhập k

        Solution sol;
        int key = sol.minDeletions(word, k);
        cout << "So ky tu can xoa it nhat la: " << key << endl;
    }
    return 0;
}
