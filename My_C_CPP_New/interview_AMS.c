//1,2,2,3,4,5,5,3

/*#include <stdio.h>

void func(int *arr, int size) {
    
    int temp = arr[0], j = 0, flag = 0;
    int temp_arr[size];
    printf("size : %d\n", size);
    
    for (int i = 0; i < size; i++) {
        printf("debug -->\n");
        if (i == 0) {
            temp_arr[j] = arr[0];
        }
        printf("Arr[%d] , %d\n", i, arr[i]);
        printf("temp %d\n", temp);
        if (temp == arr[i]) {
            flag++;
        } else {
            printf("flag = %d\n", flag);
            if (flag == 1) {
                if (temp != arr[i]) {
                    temp_arr[++j] = arr[i];
                    printf("debug2 : %d\n", arr[i]);
                    flag = 0;    
                }
            }
        }
        temp = arr[i];
    }
    
    for(int i = 0; i < sizeof(temp_arr)/sizeof(temp_arr[0]); i++) {
        printf("Array [%d] : %d\n", i, temp_arr[i]);    
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 5, 5, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    func(arr, size);
    
    return 0;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
 
void remove(std::vector<int> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
 
    v.erase(end, v.end());
}
 
int main()
{
    std::vector<int> v = { 5, 2, 1, 3, 4, 2, 2, 4, 5, 5, 6 };
 
    remove(v);
 
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << ' ';
    }
 
    return 0;
}

