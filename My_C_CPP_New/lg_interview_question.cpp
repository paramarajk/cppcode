#include <iostream>
#include <vector>
#include <string>
//#define MAX 10

using namespace std;

template <typename T>
class myvec {
    vector<T> mv;
public:
    myvec(int size, T val) {
        mv = vector<T>(size, val);
        cout << "myvec const" << endl;
    }    
    
    ~myvec() {
        cout << "myvec dest" << endl;
    }
    
    void print() {
        for(auto i : mv) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    myvec<int> mv(5, 0);
    mv.print();
    myvec<string> mv1(5, "hello");
    mv1.print();
    return 0;
}





