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
    bool checkPalindrome(const string& original){
        string reversed="";
        while(!isEmpty()){
        	reversed+=pop();
		}return original==reversed;
    }
};
int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    int n=str.length();
    Stack s(n);
    for(int i=0;i<n;i++){
        s.push(str[i]);
    }
    if(s.checkPalindrome(str))
        cout<<"The string is a palindrome"<<endl;
    else
        cout<<"The string is not a palindrome"<<endl;
    return 0;
}
