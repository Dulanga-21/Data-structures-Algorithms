#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Stack{
public:
    int size;
    int *stackArray;
    int top;

public:
    Stack(int size){
        this->top = -1;
        this->size = size;
        stackArray = new int[size];
    }
};

int isEmpty(Stack* s){
    if(s->top == -1){
      return 1;
    }else{
        return 0;
    }
}

int isFull(Stack* s){
    if(s->top == s->size - 1){
        return 1;
    }else{
        return 0;
    }
}

void push(Stack* s, int value){
    if (isFull(s)){
        cout<<"Stack overflow"<<endl;
    }else {
        s->top++;
        s->stackArray[s->top] = value;
    }
}

void pop(Stack* s){
    if (isEmpty(s)){
        cout<<"Stack underflow"<<endl;
    }else{
        int value = s->stackArray[s->top];
        s->top--;
        cout<<"Popped item :"<<value<<endl;
    }
}

void stackTop(Stack* s){
    if(isEmpty(s)){
        cout<<"Stack underflow"<<endl;
    }else{
        cout<<"Top item : "<<s->stackArray[s->top]<<endl;
    }
}

void display(Stack* s){
    if(isEmpty(s)){
        cout<<"Stack underflow"<<endl;
    }else{
        cout<<"Stack :";
        for(int i=0;i <= s->top;i++){
            cout<<s->stackArray[i]<<" ";
        }
    }cout<<"\n";
}

int main(){
    int size;
    cout<<"Enter stack size :";
    cin>>size;

    auto start1 = high_resolution_clock::now();

    Stack stack1(size);
    push(&stack1, 8);
    push(&stack1, 10);
    push(&stack1, 11);
    push(&stack1, 15);
    push(&stack1, 23);
    push(&stack1, 6);
    push(&stack1, 18);
    push(&stack1, 20);
    push(&stack1, 17);
    push(&stack1, 40);
    push(&stack1, 25);
    stackTop(&stack1);
    display(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    display(&stack1);
    push(&stack1, 4);
    push(&stack1, 30);
    push(&stack1, 3);
    push(&stack1, 1);
    display(&stack1);

    auto stop1 = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout<<"Time :"<<duration1.count()<<endl;
    return 0;
}
