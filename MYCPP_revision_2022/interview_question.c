
#include <stdio.h>

int index = 0;

int buy(int *price, int size, int day_index) {
    if (day_index < size) {
        return price[day_index]; 
    } else {
        printf("We cant buy stock\n");
        return 0;
    }
}

int min(int *price, int size) {
    int m = price[0];
    for (int i = 0; i < size; i++) {
        if(price[i+1] < m) {
            m = price[i+1];
            index = i+1;
            //printf("M : %d\n", m);
            break;
        }
    }
    return m;
}

/*int max(int *price, int size) {
    int mx = price[index];
    for (int i = index; i < size; i++) {
        if(price[i+1] < m) {
            mx = price[i+1];
            index = i+1;
            printf("M : %d\n", mx);
            break;
        }
    }
    return mx;
}*/


int main() {
    int price[] = {7,1,5,3,6,4};
    int size = sizeof(price)/sizeof(price[0]);
    int m = min(price, size);
    //printf("Min : %d\n", m);
    //printf("index : %d\n", index);
    int b_share = buy(price, size);
    printf("%d\n", b_share)
    //int s_share = sell(price, size, 5);
    
    return 0;
} 
