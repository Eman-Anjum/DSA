#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
class Call{
    public:
        int callID;
        int arrivalTime;
        string customerName;
        Call(int id,int time,string name){
            callID=id;
            arrivalTime=time;
            customerName=name;
        }
};
class CallCenter{
    private:
        queue<Call> callQueue;
        int CSRs;
        vector<bool> csrAvailable;
    public:
        CallCenter(int n){
            CSRs=n;
            csrAvailable.resize(n);
            for(int i=0;i<n;i++)
            csrAvailable[i]=true;
        }
        void addCall(Call c){
            cout<<"Call "<<c.callID<<" from "<<c.customerName<<" is added to queue (Arrival Time: "<<c.arrivalTime<<")"<<endl;
            callQueue.push(c);
        }
        void processCalls(){
            while(!callQueue.empty()){
                for(int i=0;i<CSRs;i++){
                    if(!callQueue.empty()&&csrAvailable[i]){
                        Call currentCall=callQueue.front();
                        callQueue.pop();
                        csrAvailable[i]=false;
                        cout<<"CSR "<<i+1<<" is handling Call "<<currentCall.callID<<" from "<<currentCall.customerName<<endl;
                        cout<<"CSR "<<i+1<<" has completed Call "<<currentCall.callID<<endl;
                        csrAvailable[i]=true;
                    }
                }
            }
        }
};
int main(){
    CallCenter center(2);
    center.addCall(Call(1,1,"Amna"));
    center.addCall(Call(2,2,"Fatima"));
    center.addCall(Call(3,3,"zehra"));
    center.addCall(Call(4,4,"laiba"));
    center.processCalls();
}
