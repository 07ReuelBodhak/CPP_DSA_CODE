#include <iostream>
using namespace std;

int partition(int arr[],int low,int high) {
    int pivot = arr[high];
    int i = low-1;
    int j = low;
    int temp;

    while(j < high) {
        if(arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp; 
        }
        j++;
    }
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quick_sort(int arr[],int low,int high) {
    if(low < high) {
        int pi = partition(arr,low,high);
        quick_sort(arr,low,pi-1);//left sub array
        quick_sort(arr,pi+1,high);//right sub array
    }
}

int main() {
    int arr[7] = {1,5,2,3,6,7,4};
    int n = 7;
    cout<<"unsorted array"<<endl;
        for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quick_sort(arr,0,n-1);
    cout<<"sorted array"<<endl;
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}