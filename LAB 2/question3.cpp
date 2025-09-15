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
Node* sortList(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* rightHalf = slow->next;
    slow->next = NULL;
    Node* leftHalf = head;
    Node* leftSorted = sortList(leftHalf);
    Node* rightSorted = sortList(rightHalf);
    return mergeTwoLists(leftSorted, rightSorted);
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
    head=sortList(head);
    cout<<"Sorted List: "<<endl;
    printList(head);
    freeList(head);
}
