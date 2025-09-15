#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
};
Node* deleteDuplicates(Node* head){
    Node* current=head;
    while(current!=NULL && current->next!=NULL){
        if(current->val==current->next->val){
            Node* temp=current->next;
            current->next=current->next->next;
            delete temp;
        }else{
            current=current->next;
        }
    }
    return head;
}
void insertNode(Node*& head,int value){
    Node* newNode=new Node(value);
    if(head==NULL) {
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void printList(Node* head){
    while(head!=NULL) {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
void freeList(Node* head){
    while(head!=NULL){
        Node* temp = head;
        head=head->next;
        delete temp;
    }
}
int main(){
    int n,value;
    cout<<"Enter number of nodes in sorted list: "<<endl;
    cin>>n;
    Node* head=NULL;
    cout<<"Enter elements in sorted order: "<<endl;
    for(int i=0;i<n;i++){
        cin>>value;
        insertNode(head,value);
    }
    cout<<"Original List: "<<endl;
    printList(head);
    head=deleteDuplicates(head);
    cout<<"List after removing duplicates: "<<endl;
    printList(head);
    freeList(head);
}
