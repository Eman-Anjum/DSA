#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x),next(NULL),prev(NULL){}
};
class DoubEndedQueue{
private:
    Node* front;
    Node* rear;
public:
    DoubEndedQueue() : front(NULL),rear(NULL){}
    ~DoubEndedQueue(){
        Node* current=front;
        while(current){
            Node* temp=current;
            current=current->next;
            delete temp;
        }
        front=rear=NULL;
    }
    void enqueueatfront(int x){
        Node* newNode=new Node(x);
        if(front==NULL){
            front=rear=newNode;
            
        }else{
            newNode->next=front;
            front->prev=newNode;
            front=newNode;
        }
        cout<<"\nEnqueued at front "<<x<<endl;
    }
    void enqueueatrear(int x){
    	Node* newNode=new Node(x);
    	if(front==NULL){
            front=rear=newNode;
            
        }else{
        	rear->next=newNode;
            newNode->prev=rear;
            rear=newNode;
        }
        cout<<"Enqueued at rear "<<x<<endl;
    }
    int dequeueatFront(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int value=front->val;
        Node* temp=front;
        if(front==rear){ 
            front=rear=NULL;
        }else{
            front=front->next;
            front->prev=NULL;
            
        }
        delete temp;
        return value;
    }
    int dequeueatrear(){
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        int value=rear->val;
        Node* temp=rear;
        if(front==rear){ 
            front=rear=NULL;
        }else{
            rear=rear->prev;
            rear->next=NULL;
            
        }
        delete temp;
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
        while(temp){
        	cout<<temp->val<<" ";
        	temp=temp->next;
		}
		cout<<endl;
    }
};
int main(){
    DoubEndedQueue q;
    q.enqueueatrear(10);
    q.enqueueatrear(20);
    q.enqueueatfront(30);
    q.display();
    cout<<"\nDequeued at front: "<<q.dequeueatFront()<<endl;
    q.display();
    q.enqueueatfront(40);
    q.display();
    cout<<"\nDequeued at rear: "<<q.dequeueatrear()<<endl;
    cout<<"\nDequeued at rear: "<<q.dequeueatrear()<<endl;
    cout<<"\nDequeued at rear: "<<q.dequeueatrear()<<endl;
    q.display();
}
