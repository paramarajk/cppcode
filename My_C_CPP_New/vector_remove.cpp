#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

void remove(vector<int> &v)
{
    auto end_val = v.end();
    cout << *end_val << endl;
    for (auto it = v.begin(); it != end_val; ++it) {
        cout << "before : " << *end_val << endl;
        end_val = remove(it + 1, end_val, *it);
        cout << "after : " << *end_val << endl;
    }
 
    v.erase(end_val, v.end());
}
 
int main()
{
    //std::vector<int> v = { 5, 2, 1, 3, 4, 2, 2, 4, 5, 5, 6 };
    vector<int> v = {1,2,2,3,4,5,5,3};
 
    remove(v);
 
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        cout << *it << ' ';
    }
 
    return 0;
}
