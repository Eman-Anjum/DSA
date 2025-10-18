#include<iostream>
#include<queue>
using namespace std;
class ProductOfNumbers{
    private:
        queue<int> q;
    public:
        ProductOfNumbers(){}
        void add(int num){
            q.push(num);
        }
        int getProduct(int k){
            if(k>q.size())
		    return 0;
            int product=1;
            int n=q.size();
            queue<int> temp=q;
            for(int i=0;i<n-k;i++){
        	    temp.pop();
		    }
            while(!temp.empty()){
                product*=temp.front();
                temp.pop();
            }
            return product;
        }
};
int main(){
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    cout<<productOfNumbers.getProduct(2)<<endl;
    cout<<productOfNumbers.getProduct(3)<<endl;
    cout<<productOfNumbers.getProduct(4)<<endl;
    productOfNumbers.add(8);
    cout<<productOfNumbers.getProduct(2)<<endl;
}
