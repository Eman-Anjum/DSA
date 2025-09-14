//Search target in a sorted array using binary search with O(log n) runtime
#include<iostream>
using namespace std;
int searchTarget(int* nums,int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            left=mid+1; 
        else
            right=mid-1;
    }
    return -1; 
}
int main(){
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    int* arr=new int[n];
    cout<<"Enter elements in sorted order: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target: "<<endl;
    cin>>target;
    int result=searchTarget(arr,n,target);
    if(result!=-1)
        cout<<"Element is found at index: "<<result<<endl;
    else
        cout<<"Element is not found"<<endl;
    delete[] arr;
    return 0;
}
