#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using ll =long long;
using namespace std;

int maxDifference(string s, int k) {
    int n = s.length();
    int max_diff = INT_MIN;

    for (int length = k; length <= n; ++length) {
        unordered_map<char, int> freq;


        for (int i = 0; i < length; ++i) {
            freq[s[i]]++;
        }

        for (unordered_map<char, int>::iterator it1 = freq.begin(); it1 != freq.end(); ++it1) {
            char a = it1->first;
            int freq_a = it1->second;

            if (freq_a % 2 == 1) { // tần số lẻ
                for (unordered_map<char, int>::iterator it2 = freq.begin(); it2 != freq.end(); ++it2) {
                    char b = it2->first;
                    int freq_b = it2->second;

                    if (a != b && freq_b % 2 == 0) { // tần số chẵn
                        int diff = freq_a - freq_b;
                        if (diff > max_diff) {
                            max_diff = diff;
                        }
                    }
                }
            }
        }

        for (int i = length; i < n; ++i) {
            char out_char = s[i - length]; 
            char in_char = s[i];           

            freq[out_char]--;
            if (freq[out_char] == 0) {
                freq.erase(out_char); 
            }

            freq[in_char]++;

            
            for (unordered_map<char, int>::iterator it1 = freq.begin(); it1 != freq.end(); ++it1) {
                char a = it1->first;
                int freq_a = it1->second;

                if (freq_a % 2 == 1) { 
                    for (unordered_map<char, int>::iterator it2 = freq.begin(); it2 != freq.end(); ++it2) {
                        char b = it2->first;
                        int freq_b = it2->second;

                        if (a != b && freq_b % 2 == 0) { 
                            int diff = freq_a - freq_b;
                            if (diff > max_diff) {
                                max_diff = diff;
                            }
                        }
                    }
                }
            }
        }
    }

    if (max_diff == INT_MIN) {
        return -1; 
    }

    return max_diff;
}

int main() {
    string s ;
    cin >> s;
    int k = 3;
    
    int result = maxDifference(s, k);
    cout << "Out put la :" << result << endl;

    return 0;
}
