#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
};
Node* mergeTwoLists(Node* list1, Node* list2){
    Node* dummy=new Node(-1);
    Node* tail=dummy;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<=list2->val){
            tail->next=list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            list2=list2->next;
        }
        tail=tail->next;
    }
    if(list1!=NULL)tail->next =list1;
    else tail->next=list2;
    Node* mergedHead=dummy->next;
    delete dummy;
    return mergedHead;
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
int main() {
    int n1,n2,value;
    cout<<"Enter number of nodes in first sorted list: "<<endl;
    cin>>n1;
    Node* list1=NULL;
    cout<<"Enter "<<n1<<" elements in sorted order: "<<endl;
    for(int i=0;i<n1;i++){
        cin>>value;
        insertNode(list1,value);
    }
    cout<<"Enter number of nodes in second sorted list: "<<endl;
    cin>>n2;
    Node* list2=NULL;
    cout<<"Enter "<<n2<<" elements in sorted order: "<<endl;
    for(int i=0;i<n2;i++){
        cin>>value;
        insertNode(list2,value);
    }
    Node* merged=mergeTwoLists(list1,list2);
    cout<<"Merged Sorted List: "<<endl;
    printList(merged);
    freeList(merged);
}
