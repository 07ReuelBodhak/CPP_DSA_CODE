#include <iostream>
using namespace std;

void binary_search(int *arr, int size, int data) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int median = low  + ((high - low) / 2);
        if(arr[median] == data) {
            cout<<"element found";
            return;
        }else if(arr[median] < data) {  
            low = median + 1;
        }else {
            high = median - 1;
        }
    }
    cout<<"element not found" << endl;
    return;
}

int main () {
    int arr[6] = {1,2,4,5,7,10};
    binary_search(arr,6,20);
    return 0;
}