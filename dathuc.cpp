#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Polytime{
    private:
     vector<int>coffe; // bac cua da thuc
    public:
     Polytime() {}; // khoi tao construtor mac dinh 
     Polytime(vector<int>c) : coffe(c) {};

     void nhap(){
        int degree; cin >> degree;
        coffe.resize(degree + 1); // cap phat dong cho mang
        cout << "Nhap thong tin cau da thuc :" << endl;
        for(int i = 0; i< degree; i++){
            cin >> coffe[i];
        }
     }

     void print() const {
        int n =coffe.size();
        for (int i = n - 1; i >= 0; --i) {
            if (coffe[i] == 0) continue;

            if (i != n - 1 &&coffe[i] > 0)
                cout << "+";

            if (i == 0 || coffe[i] != 1)
                cout << coffe[i];

            if (i > 0) {
                cout << "x";
                if (i > 1) cout << "^" << i;
            }
        }
        cout << "\n";
     }

     Polytime operator+(const Polytime&other) const{
        int max_deg = max(coffe.size(), other.coffe.size());
        vector<double>res(max_deg, 0.0);
        for(size_t i = 0; i < max_deg; i++){
            if(i < coffe.size()){
                res[i] += coffe[i];
            }
            if( i < other.coffe.size()){
                res[i] += other.coffe[i];
            }
        }
        return Polytime(other);
     }

    Polytime operator-(const Polytime&other) const{
        int max_deg = max(coffe.size(), other.coffe.size());
        vector<double>res(max_deg, 0.0);
        for(size_t i = 0; i < max_deg; i++){
            if(i < coffe.size()){
                res[i] -= coffe[i];
            }
            if( i < other.coffe.size()){
                res[i] -= other.coffe[i];
            }
         }
        return Polytime(other);
    }

    Polytime hello() const{
        if(coffe.size() == 1){
            return Polytime({0});
        }

        vector<int> dict(coffe.size() - 1);
        for(size_t i = 1; i < dict.size() ;i++){
            dict[i-1] = i * coffe[i];
        }
        return Polytime({dict});
    }
};

int main(){
    Polytime p1;
    p1.nhap();
    Polytime p2;
    p2.nhap();
    p1.print();
    p1.hello();
    p1.print();
    return 0;
}