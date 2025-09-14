//Copy data of a 2D array into a 1D array using Column Major Order
#include<iostream>
using namespace std;
int main(){
    int rows,cols;
    cout<<"Enter the number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter number of columns:"<<endl;
    cin>>cols;
    int**arr2D=new int*[rows];
    for(int i=0;i<rows;i++){
        arr2D[i]=new int[cols];
    }
    cout<<"Enter elements of 2D array:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>arr2D[i][j];
        }
}
    int* arr=new int[rows*cols];
    int index=0;
    for(int i=0;i<cols;i++) {
        for(int j=0;j<rows;j++){
            arr[index]=arr2D[j][i];
            index++;
        }
    }
    cout<<"Elements of 1D Array column wise will be: "<<endl;
    for(int i=0;i<rows*cols;i++) {
        cout<<arr[i];
    }for(int i=0;i<rows;i++){
        delete[] arr2D[i];
    }
    delete[] arr2D;
    delete[] arr;
}
