#include<iostream>
#include<queue>
using namespace std;
class DataStream{
    private:
        int value;
        int k;
        queue<int> q;
        int count;
    public:
        DataStream(int v,int val){
            value=v;
            k=val;
            count=0;
        }
        bool consec(int num){
            q.push(num);
            if(num==value) 
		    count++;
            if(q.size()>k){
                if(q.front()==value) 
			    count--;
                q.pop();
            }
            return q.size()==k && count==k;
        }
};
int main(){
    DataStream dataStream(4,3);
    cout<<dataStream.consec(4)<<endl;
    cout<<dataStream.consec(4)<<endl;
    cout<<dataStream.consec(4)<<endl;
    cout<<dataStream.consec(3)<<endl;
}
