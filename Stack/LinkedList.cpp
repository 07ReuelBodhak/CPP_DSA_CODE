#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* top = NULL;

class stack {
    public:
    void push();
    void pop();
    void display();
};

void stack::push(){
    node* nn = new node;
    cout << "enter element" << endl;
    cin >> nn->data;
    nn -> next = NULL;

    if(top == NULL) {
        top = nn;
    }else {
        nn -> next = top;
        top = nn;
    }
}
void stack::pop(){
    if(top == NULL) {
        cout << "List is empty";
    }else{
        node* temp = top;
        cout << "element that is deleted is " << temp->data << endl;
        top = temp->next;
    }
}

void stack::display() {
    if(top == NULL) {
        cout << "List is empty";
    }else{
        node* temp = temp;
        while (temp != NULL)
        {
            cout << temp -> data;
            temp = temp->next;
        }
        
    }
}

int main() { 
    stack s;
    s.push();
    s.display();
    s.pop();
    s.display();
}