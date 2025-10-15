#include<iostream>
using namespace std;
class Node{
	public:
    string url;
    Node* prev;
    Node* next;
    Node(string u){
        url=u;
        prev=nullptr;
        next=nullptr;
    }
};
class BrowserHistory{
private:
    Node* current;
public:
    BrowserHistory(string homepage){
        current=new Node(homepage);
    }
    ~BrowserHistory(){
        while(current && current->prev) current=current->prev;  
        while(current){
            Node* temp=current;
            current=current->next;
            delete temp;
        }
    }
    void visit(string url){
        Node* newNode=new Node(url);
        current->next=nullptr;
        newNode->prev=current;
        current->next=newNode;
        current=newNode;
    }
    string back(int steps){
        while(steps>0 && current->prev!=nullptr){
            current=current->prev;
            steps--;
        }
        return current->url;
    }
    string forward(int steps){
        while(steps>0 && current->next!=nullptr){
            current=current->next;
            steps--;
        }
        return current->url;
    }
};
int main(){
    BrowserHistory browser("homepage.com");
    browser.visit("google.com");
    browser.visit("youtube.com");
    browser.visit("github.com");
    cout<<browser.back(1)<<endl;
    cout<<browser.back(1)<<endl;
    cout<<browser.forward(1)<<endl;
    browser.visit("linkedin.com");
    cout<<browser.back(2)<<endl;
    cout<<browser.back(7)<<endl;
}
