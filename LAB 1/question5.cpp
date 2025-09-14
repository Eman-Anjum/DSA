//Search target in a sorted 2D matrix with O(log(m * n)) runtime
#include<iostream>
using namespace std;
bool searchMatrix(int** matrix,int rows,int cols,int target){
    int left=0;
    int right=rows*cols-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        int row=mid/cols;
        int col=mid%cols;
        if(matrix[row][col]==target){
            return true;
        }else if(matrix[row][col]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return false;
}
int main(){
    int rows;
	int cols;
    cout<<"Enter number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter number of columns: "<<endl;
    cin>>cols;
    if(rows<=0 || cols<=0 || rows>100 || cols>100){
        cout<<"Invalid matrix size! Rows and cols must be between 1 and 100"<<endl;
        return 0;
    }
    int** matrix=new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    cout<<"Enter elements of the matrix in sorted order: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cout<<"Enter target value: "<<endl;
    cin>>target;
    if(searchMatrix(matrix,rows,cols,target))
        cout<<"True! Found"<<endl;
    else
        cout<<"False! Target Not found"<<endl;
    for(int i=0;i<rows;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}
