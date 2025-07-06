// Cho một danh sách các số nguyên không âm nums, hãy sắp xếp chúng sao cho tạo thành số lớn nhất và trả về số đó.

// Vì kết quả có thể rất lớn nên bạn cần trả về một chuỗi thay vì một số nguyên.
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:

    static bool check(string & a , string & b){
        return a + b > b  + a;
     }
     string largestNumber(vector<int>& nums){
        // chuyen tu int ve strinjg 
        vector<string>pattern;
        for(int num : nums){
            pattern.push_back(to_string(num));
        }
        sort(pattern.begin(), pattern.end(),check);
        string result = "";
        if(pattern[0] == "0" ){
            return "0";
        }
        for(const string&s : pattern){
            result += s;
        }
        return result;

     }
};
