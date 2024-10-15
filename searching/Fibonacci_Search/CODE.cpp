#include <iostream>
using namespace std;

int min(int a,int b) {
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int Fibonacci_Search(int arr[],int target,int n){
    int fib1 = 0, fib2 = 1;
    int fib3 = fib1 + fib2;

    while(fib3 < n){
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }

    int offset = -1;
    int i = 0;
    while (fib3 > 1) {
        i = min(offset + fib2,n - 1);

        if(arr[i] < target){
            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib3 - fib2;
            offset = i;
        }else if(arr[i] > target) {
            fib3 = fib1;
            fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }else{
            return i;
        }
    }

    if(fib2 == 1 && arr[offset + 1] == target){
        return offset;
    }else{
        return -1;
    }
}

int main() {
    int arr[11] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int target = 100;
    int result = Fibonacci_Search(arr,target,11);
    if(result){
        cout<<"element found at position : "<<result;
    }else{
        cout<<"Element not found";
    }
}