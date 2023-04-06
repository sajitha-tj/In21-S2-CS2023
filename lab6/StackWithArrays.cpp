#include<iostream>

using namespace std;

class Stack{
    private:
        int top;
        int stackSize = 10;
        int stack_arr[10];

    public:
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            return(top == -1);
        }

        bool isFull(){
            return(top == stackSize - 1);
        }
        
        void push(int x){
            if(isFull()){
                cout << "Stack Overflow!";
                return;
            }
            top++;
            stack_arr[top] = x;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow!";
                return -1;
            }
            top = top - 1;
            return (stack_arr[top+1]);
        }

        int stackTop(){
            if(isEmpty()){
                cout << "Stack is Empty!";
                return -1;
            }
            return stack_arr[top];
        }

        void display(){

            if(isEmpty()){
                cout << "Stack is Empty!";
                return;
            }

            for (int i = top; i >= 0; i--) {
                cout << stack_arr[i] << " ";
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