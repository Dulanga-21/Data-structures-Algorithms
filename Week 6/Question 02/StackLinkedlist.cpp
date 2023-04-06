#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Stack{
public:
    Node* top;
    int size,currentSize = 0;

    Stack(int size){
        top = nullptr;
        this->size = size;
    }
    void push(int data);
    void pop();
    int isEmpty();
    int isFull();
    void peek();
    void display();
};

void Stack::push(int data) {
    if(isFull()){
        cout<<"Stack overflow"<<endl;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        currentSize++;
    }
}

void Stack::pop() {
    if(isEmpty())
        cout<<"Stack underflow"<<endl;
    else {
        Node *temp = top;
        top = top->next;
        temp->next = nullptr;
        cout << "Popped item : " << temp->data << endl;
        currentSize--;
    }
}

int Stack::isEmpty() {
    if(top== nullptr){
        return 1;
    }else{
        return 0;
    }
}

int Stack::isFull() {
    if(currentSize == size){
        return 1;
    }else{
        return 0;
    }
}

void Stack::peek() {
    if(!isEmpty()){
        cout<<"Top is : "<<top->data<<endl;
    }else{
        cout<<"Stack underflow"<<endl;
    }
}

void Stack::display() {
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
    }else{
        Node* temp = top;
        cout<<"Stack : ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }cout<<"\n";
    }
}

int main(){
    int size;
    cout<<"Enter stack size :";
    cin>>size;

    auto start1 = high_resolution_clock::now();
    Stack s(size);
    s.push(8);
    s.push(10);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.push(40);
    s.push(25);
    s.peek();
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();

    auto stop1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout<<"Time :"<<duration1.count()<<endl;
    return 0;
}