#include <iostream>
using namespace std;

int max_num(int arr[],int n){
    int max = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int* counting_sort(int arr[],int n){
    int max_el = max_num(arr,n);
    int new_arr[max_el++];
    for(int i=0;i < max_el; i++){
        new_arr[i] = 0;
    }
    for(int i=0;i<n;i++){
        new_arr[arr[i]] += 1;
    }

    int j = 0;

    for(int i=0;i < max_el; i++){
        if(new_arr[i] != 0) {
            while(new_arr[i] != 0){
               arr[j] = i;
               new_arr[i] -= 1;
               j++;
            }
        }
    }
    return arr;
}

int main() {
    int arr[] = {3,1,9,7,1,2,4};
    int n = 7;
    cout<<"Unsorted Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    counting_sort(arr,n);
    cout<<endl;
    cout<<"Sorted Array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
