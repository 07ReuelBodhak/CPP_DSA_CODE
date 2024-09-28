#include <iostream>
using namespace std;

void merge_sort(int arr1[],int arr2[],int arr3[],int n1,int n2) {
    int i=0,j=0,k = 0;
    
    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        }else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
}

int main() {
    int arr1[4] = {1,5,3,4};
    int arr2[6] = {6,2,8,9,10,11};
    int arr3[10];
    int n1=4,n2=6;
    merge_sort(arr1,arr2,arr3,n1,n2);
    for(int i=0;i<n1+n2;i++){
        cout<<arr3[i]<<" ";
    }
    return 0;
}