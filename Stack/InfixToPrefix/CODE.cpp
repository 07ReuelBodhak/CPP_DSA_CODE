#include <iostream>
#include <cstring>
using namespace std;
#define size 20

class Stack {
    int top;
    char stk[size];

public:
    Stack() {
        top = -1;
    }
    void push(char c);
    char pop();
    char peek();
    int isEmpty();
    int isFull();
};

void Stack::push(char c) {
    if (isFull()) {
        cout << "Stack is full" << endl;
        return;
    } else {
        top += 1;
        stk[top] = c;
    }
}

int Stack::isEmpty() {
    return (top == -1);
}

int Stack::isFull() {
    return (top == size - 1);
}

char Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return '\0';
    } else {
        char c = stk[top];
        top -= 1;
        return c;
    }
}

char Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return '\0';
    } else {
        return stk[top];
    }
}

int isOperator(char o) {
    return (o == '^' || o == '*' || o == '/' || o == '+' || o == '-');
}

int precedence(char o) {
    if (o == '^') {
        return 3;
    } else if (o == '*' || o == '/') {
        return 2;
    } else if (o == '+' || o == '-') {
        return 1;
    } else {
        return 0;
    }
}

void toPostfix(char c[], int n, Stack &s, char str[]) {
    int i = 0;
    int j = 0;
    while (i < n) {
        if (c[i] == '(') {
            s.push(c[i]); 
        } else if (c[i] == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                str[j++] = s.pop(); 
            }
            s.pop(); 
        } else if (isOperator(c[i])) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c[i])) {
                str[j++] = s.pop();
            }
            s.push(c[i]); 
        } else {
            str[j++] = c[i]; 
        }
        i++;
    }
    while (!s.isEmpty()) {
        str[j++] = s.pop(); 
    }
    str[j] = '\0'; 
}

int main() {
    Stack s;
    const int n = 30;
    char exp[n];
    char res[n];
    
    cout << "Enter expression: ";
    cin >> exp;

    toPostfix(exp, strlen(exp), s, res); 
    cout << "Postfix expression: " << res << endl;
    return 0;
}
