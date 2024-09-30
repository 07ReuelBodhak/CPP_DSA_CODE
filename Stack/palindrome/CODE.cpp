#include <iostream>
#include <cstring>

using namespace std;
#define size 30

class Stack {
    int top;
    char stk[size];
    public:
    Stack() {
        top = -1;
    }
    void push(char c);
    void pop();
    char peek();
    int isFull();
    int isEmpty(); 
};

int Stack::isEmpty() {
    return (top==-1);
}

int Stack::isFull() {
    return (top==size-1);
}

void Stack::push(char c){
    if(isFull()){
        cout<<"stack is full";
        return;
    }else{
        top++;
        stk[top] = c;
    }
}

void Stack::pop(){
    if(isEmpty()){
        cout<<"stack is Empty";
        return;
    }else{
        top--;
    }
}

char Stack::peek() {
    if(isEmpty()){
        return '\0';
    }else{
        return stk[top];
    }
}

void isPalindrome(char c[],int n,Stack& s){
    for(int i=0;i<n;i++){
        s.push(c[i]);
    }

    for(int i=0;i<n;i++){
        if(c[i] == s.peek()){
            s.pop();
        }else{
            cout<<"string is not polindrome";
            return;
        }
    }
    cout<<"string is palindrome";
}

int main(){
    Stack s;
    char c[40];
    cout<<"Enter string : ";
    cin>>c;
    int length = strlen(c);
    isPalindrome(c,length,s);
}
