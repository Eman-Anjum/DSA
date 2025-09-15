#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
};
class Stack{
private:
Node* head;
public:
    Stack() : head(NULL){}
    void push(int x){
        Node* newNode=new Node(x);
        newNode->next=head;
        head=newNode;
        cout<<x<<" pushed onto stack"<<endl;
    }
    ~Stack(){
        while(head){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    int pop(){
        if(head==NULL){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        int topValue=head->val;
        Node* temp=head;
        head=head->next;
        delete temp;
        return topValue;
    }
    int peek() {
        if(head==NULL){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    bool isEmpty(){
        return head==NULL;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Top element is: "<<s.peek()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Popped: "<<s.pop()<<endl;
    cout<<"Top element is: "<<s.peek()<<endl;
    if(s.isEmpty())
        cout<<"Stack is empty"<<endl;
    else
        cout<<"Stack is not empty"<<endl;
    return 0;
}
