#include <iostream>
#include <cstring>
using namespace std;

#define size 10

class Stack {
    int top;
    char stk[size];

    public:
    Stack(){
        top = -1;
    }
    void push(char c);
    int isEmpty();
    int isFull();
    char pop();
};

int Stack::isEmpty() {
    return(top == -1);
}

int Stack::isFull() {
    return(top == size-1);
}

void Stack::push(char c) {
    if(isFull()){
        cout<<"Stack is full";
        return;
    }else{
        top++;
        stk[top] = c;
    }
}

char Stack::pop() {
    if(isEmpty()){
        cout<<"Stack is Empty";
        return '\0';
    }else{
        char c = stk[top];
        top--;
        return c;
    }
}

int main() {
    Stack s;
    char exp[30];
    bool flag = true;
    cout<<"enter expression : ";
    cin>>exp;

    int n = strlen(exp);
    int i=0;
    while (i < n) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (exp[i] == ')' && s.pop() != '('){
                flag = false;
                break;
            }else if (exp[i] == '}' && s.pop() != '{'){
                flag = false;
                break;
            }else if (exp[i] == ']' && s.pop() != '['){
                flag = false;
                break;
            }
        }
        i++;
    }
    if(!flag){
        cout<<"Invalid expression";
    }else{
        cout<<"Valid expression";
    }
}
