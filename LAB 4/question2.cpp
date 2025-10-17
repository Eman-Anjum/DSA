#include<iostream>
#include<string>
using namespace std;
class Stack{
private:
    char* arr;
    int top;
    int capacity;
public:
    Stack(int s){
        capacity=s;
        arr=new char[capacity];
        top=-1;
    }
    ~Stack(){
        delete[] arr;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==capacity-1;
    }
    void push(char x){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top]=x;
    }
    char pop(){
        if(!isEmpty()){
            return arr[top--];
        }
        return '\0';
    }
    char peek(){
        if(!isEmpty()){
            return arr[top];
        }
        return '\0';
    }
    int size(){
        return top+1;
    }
};
bool backspaceCompare(string s,string t){
    Stack st1(s.length()),st2(t.length());
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c=='#'){
            st1.pop();
        } else {
            st1.push(c);
        }
    }
    for(int i=0;i<t.length();i++){
        char c=t[i];
        if(c=='#'){
            st2.pop();
        }else{
            st2.push(c);
        }
    }
    if(st1.size()!=st2.size()){
        return false;
    }
    while(!st1.isEmpty()){
        if(st1.pop()!=st2.pop()){
            return false;
        }
    }
    return true;
}
int main(){
    string s,t;
    cout<<"Enter first string: ";
    cin>>s;
    cout<<"Enter second string: ";
    cin>>t;
    if(backspaceCompare(s,t))
        cout<<"The strings are equal"<<endl;
    else
        cout<<"The strings are not equal"<<endl;
}
