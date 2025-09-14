//Implement MedianFinder class with addNum() and findMedian() methods
#include <iostream>
using namespace std;
class MedianFinder {
private:
    int* arr;       
    int size;      
    int capacity;
public:
    MedianFinder() {
        capacity=10;
        arr=new int[capacity];
        size=0;
    }
    ~MedianFinder(){
        delete[] arr;
    }
    int findPosition(int x){
        int low=0,high=size;
        while(low<high){
            int mid=(low+high)/2;
            if(arr[mid]<x)low=mid+1;
            else high=mid;
        }
        return low;
    }
    void addNum(int x){
        if(size==capacity){
            capacity*=2;
            int* newArr=new int[capacity];
            for(int i=0;i<size;i++)newArr[i]=arr[i];
            delete[] arr;
            arr=newArr;
        }
        int pos=findPosition(x);
        for(int i=size;i>pos;i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=x;
        size++;
    }
    double findMedian(){
        if(size==0) return 0;
        if(size%2==1){
            return arr[size/2];
        }else{
            return(arr[size/2-1]+arr[size/2])/2.0;
        }
    }
};
int main(){
    MedianFinder* medianFinder=new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);
    cout<<medianFinder->findMedian()<<endl;
    medianFinder->addNum(3);
    cout<<medianFinder->findMedian()<<endl;
    delete medianFinder;
    return 0;
}
