#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool checkingEachPath(vector<vector<char>>& board,string& word,int i,int j,int k){
    if(k==word.size()) return true;
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k]){
        return false;
    }
    char temp=board[i][j];
    board[i][j]='#';
    bool found=checkingEachPath(board,word,i+1,j,k+1) || checkingEachPath(board,word,i-1,j,k+1) || checkingEachPath(board,word,i,j+1,k+1) || checkingEachPath(board,word,i,j-1,k+1);
    board[i][j]=temp;
    return found;
}
bool IfwordExist(vector<vector<char>>& board,string word){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(checkingEachPath(board,word,i,j,0)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int m,n;
    cout<<"Enter rows and columns: ";
    cin>>m;
	cin>>n;
    vector<vector<char>> board(m,vector<char>(n));
    cout<<"Enter the board characters (row by row):"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    string word;
    cout<<"Enter the word to search: ";
    cin>>word;
    if(IfwordExist(board, word)){
        cout<<"Word exists in the grid"<<endl;
    }else{
        cout<<"Word does not exists in the grid"<<endl;
    }
}
