#include<iostream>
using namespace std;
class MyCircularDeque{
	private:
		int *queue;
		int size;
		int capacity;
		int front;
		int rear;		
	public:
		MyCircularDeque(int k){
			capacity=k;
			queue=new int[k];
			size=0;
			front=-1;
			rear=-1;
		}
		~MyCircularDeque(){
			delete[] queue;
		}
		bool isempty(){
			return size==0;
		}
		bool isfull(){
			return size==capacity;
		}
		bool insertfront(int val){
			if(isfull()) 
			return false;
			if(isempty())
			front=rear=0;
			else
			front=(front-1+capacity)%capacity;
			queue[front]=val;
			size++;
			print();
			return true;
		}
		bool insertrear(int val){
			if(isfull()) 
			return false;
			if(isempty())
			front=rear=0;
			else
			rear=(rear+1)%capacity;
			queue[rear]=val;
			size++;
			print();
			return true;
		}
		bool deletefront(){
			if (isempty()) 
			return false;
			if(front==rear)
			front=rear=-1;
			else
			front=(front+1)%capacity;			
			size--;
			print();
			return true;
		}		
		bool deleterear(){
			if (isempty())
			return false;
			if(front==rear)
			front=rear=-1;
			else
			rear=(rear-1+capacity)%capacity;
			size--;
			print();
			return true;
		}
		int getrear(){
			if(isempty())
			return -1;
			else
			return queue[rear];		
			}	
		int getfront(){
			if(isempty())
			return -1;
			else
			return queue[front];		
			}
			void print(){
				if(isempty()){
					cout<<" queue is empty"<<endl;
					return;
				}
				cout<<" Queue elements ";
				int i=front;
				int cnt;
				for(cnt=0;cnt<size;cnt++){
					cout<<queue[i]<<" ";
					i=(i+1)%capacity;
				}
				cout<<endl;
			}
};
int main(){
	MyCircularDeque c1(5);
	cout<<" Insert 1 at rear: "<<endl;
	c1.insertrear(1);
	cout<<"Insert 2 at rear: "<<endl;
	c1.insertrear(2);
	cout<<"Insert 3 at front: "<<endl;
	c1.insertfront(3);
	cout<<"Insert 4 at front: "<<endl;
	c1.insertfront(4);
	cout<<"Delete rear element: "<<endl;
	c1.deleterear();
}
