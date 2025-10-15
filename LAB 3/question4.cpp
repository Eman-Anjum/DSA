#include<iostream>
using namespace std;
class Node{
	public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    ~DoublyLinkedList(){
        Node* current=head;
        while(current){
            Node* temp=current;
            current=current->next;
            delete temp;
        }
        head=tail=nullptr;
    }
    DoublyLinkedList(const DoublyLinkedList& other){
        head=tail=nullptr;
        Node* current=other.head;
        while(current){
            insertEnd(current->data);
            current=current->next;
        }
    }
    void insertEnd(int value){
        Node* newNode=new Node(value);
        if(!head){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void concatenate(DoublyLinkedList& other){
        if(!other.head)return;
        if(!head){
            head=other.head;
            tail=other.tail;
        }else{
            tail->next=other.head;
            other.head->prev=tail;
            tail=other.tail;
        }
    }
    void sortDescending(){
        if(!head) return;
        bool swapped;
        Node* current;
        Node* last=nullptr;
        do{
            swapped=false;
            current=head;
            while(current->next!=last){
                if(current->data<current->next->data){
                    int temp=current->data;
                    current->data=current->next->data;
                    current->next->data=temp;
                    swapped=true;
                }
                current=current->next;
            }
            last=current;
        } while(swapped);
    }
};
int main() {
    DoublyLinkedList L;
    for(int i=2;i<=10;i+=2){
        L.insertEnd(i);
    }
    cout<<"List L: ";
    L.display();
    DoublyLinkedList M;
    for(int i=1;i<=9;i+=2){
        M.insertEnd(i);
    }
    cout<<"List M: ";
    M.display();
    DoublyLinkedList N=L;
    N.concatenate(M);
    cout<<"List N (L + M): ";
    N.display();
    N.sortDescending();
    cout<<"List N sorted in descending order: ";
    N.display();
}
