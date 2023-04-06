#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};


class Stack{
    private:
        Node* top;

    public:
        Stack(){
            top = nullptr;
        }

        bool isEmpty(){
            return(top == nullptr);
        }
        
        void push(int x){
            Node* temp = new Node;
            temp->data = x;
            temp->next = top;
            top = temp;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow!";
                return -1;
            }
            Node* temp = top;
            top = top->next;
            return temp->data;
        }

        int stackTop(){
            if(isEmpty()){
                cout << "Stack is Empty!";
                return -1;
            }
            return top->data;
        }

        void display(){

            if(isEmpty()){
                cout << "Stack is Empty!";
                return;
            }

            Node* temp = top;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    Stack myStack;

    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);
    myStack.display();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.display();
    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);
    myStack.display();

    return 0;
}