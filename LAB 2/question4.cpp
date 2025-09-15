#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int x):val(x),next(NULL){}
};
Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* current=head;
    while (current!=NULL) {
        Node* nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    return prev;
}
bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL)return true;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* postmid=reverseList(slow->next);
    Node* p1=head;
    Node* p2=postmid;
    bool result=true;
    while(p2!=NULL){
        if(p1->val!=p2->val){
            result=false;
            break;
        }
        p1=p1->next;
        p2=p2->next;
    }
    slow->next=reverseList(postmid);
    return result;
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
    cout<<"Enter number of nodes: "<<endl;
    cin>>n;
    Node* head=NULL;
    cout<<"Enter elements in list: "<<endl;
    for(int i=0;i<n;i++){
        cin>>value;
        insertNode(head,value);
    }
    cout<<"Original List: "<<endl;
    printList(head);
    if(isPalindrome(head))
        cout<<"True!The list is a palindrome"<<endl;
    else
        cout<<"False!The list is not a palindrome"<<endl;
    freeList(head);
}
