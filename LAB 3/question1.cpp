#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x) : val(x),next(NULL){}
};
class CircularQueue{
private:
    Node* front;
    Node* rear;
public:
    CircularQueue() : front(NULL),rear(NULL){}
    void enqueue(int x){
        Node* newNode=new Node(x);
        if(front==NULL){
            front=rear=newNode;
            rear->next=front;
        }else{
            rear->next=newNode;
            rear=newNode;
            rear->next=front;
        }
        cout<<x<<" enqueued"<<endl;
    }
    ~CircularQueue(){
        if(!front) return;
        Node* current=front;
        do{
            Node* temp=current;
            current=current->next;
            delete temp;
        }while(current!=front);
        front=rear=NULL;
    }
    int dequeue(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int value;
        if(front==rear){ 
            value=front->val;
            delete front;
            front=rear=NULL;
        }else{
            Node* temp=front;
            value=front->val;
            front=front->next;
            rear->next=front;
            delete temp;
        }
        return value;
    }
    int peek(){
        if(front==NULL){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return front->val;
    }
    bool isEmpty(){
        return front==NULL;
    }
    void display(){
        if(front==NULL){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node* temp=front;
        cout<<"Queue elements: ";
        do{
            cout<<temp->val<<" ";
            temp=temp->next;
        }while(temp!=front);
        cout<<endl;
    }
};
int main(){
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<"Front element: "<<q.peek()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    q.display();
    q.enqueue(40);
    q.display();
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    cout<<"Dequeued: "<<q.dequeue()<<endl;
    q.display();
    cout<<"Dequeued: "<<q.dequeue()<<endl;
}
