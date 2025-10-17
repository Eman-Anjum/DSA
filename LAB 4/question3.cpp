#include<iostream>
#include<string>
using namespace std;
void getPermutation(string str,int left,int right){
    if(left==right){
        cout<<str<<endl;
    }else{
        for(int i=left;i<=right;i++){
            swap(str[left],str[i]);
            getPermutation(str,left+1,right);
            swap(str[left],str[i]);
        }
    }
}
int main(){
    string str;
    cout<<"Enter alphabets or digits with no space: ";
    cin>>str;
    cout<<"The permutations are:"<<endl;
    getPermutation(str,0,str.length()-1);
}
