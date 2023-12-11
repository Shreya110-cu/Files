#include<iostream>
using namespace std;
#define MAX 10
class DequeuqOp
{
	private:
		int arr[MAX];
		int front,rear;
	public:
		DequeuqOp()
		{
			front=rear=-1;
		}
		bool isFull()
		{
			return (rear +1) % MAX ==front;
		}
		bool isEmpty()
		{
			return front== -1 && rear== -1;
		}
		void addFront(int ele);
		void addRear(int ele);
		void removeFront();
		void removeRear();
		void display();				
};
void DequeuqOp :: addFront(int ele)
{
	if(isFull())
	{
		cout<<"\nQueue is Full";
		return;
	}
	if(isEmpty())
	{
		front=rear=0;
	}
	else
	{
		front=(front-1+MAX)%MAX;
	}
	arr[front]=ele;
	cout<<"\n Inserted "<<ele<<" at Front";
}
void DequeuqOp :: addRear(int ele)
{
	if(isFull())
	{
		cout<<"\nQueue is Full";
		return;
	}
	if(isEmpty())
	{
		front=rear=0;
	}
	else
	{
		rear=(rear+1)%MAX;
	}
	arr[rear]=ele;
	cout<<"\n Inserted "<<ele<<" at Rear";
}
void DequeuqOp :: removeFront()
{
	int no;
	if(isEmpty())
	{
		cout<<"Queue Is Empty";
		return;
	}
	no=arr[front];
	if(rear==front)
	{
		rear=front=-1;
	}
	else
	{
		front=(front+1)%MAX;
	}
	cout<<no<<" is Deleted from Front\n";
	
}
void DequeuqOp :: removeRear()
{
	int no;
	if(isEmpty())
	{
		cout<<"\nQueue Is Empty";
		return;
	}
	no=arr[rear];
	if(rear==front)
	{
		rear=front=-1;
	}
	else
	{
		rear=(rear-1+MAX)%MAX;
	}
	cout<<no<<" is Deleted from Rear\n";

}
void DequeuqOp :: display()
{
	int i;
	if(isEmpty())
	{
		cout<<"Queue is Empty";
	}
	else
	{
		i=front;
		cout<<"Queue Elements Are :";
		while(true)
		{
			cout<<arr[i]<<"  ";
			if(i==rear)
			{
				break;
			}
			i=(i+1)%MAX;
			
		}
		cout<<endl;
	}
}
int main()
{
	DequeuqOp ob;
	int ch,ele;
	
	do
	{
		cout<<"\n Operations";
		cout<<"\n 1. Insert At Rear :";
		cout<<"\n 2. Insert At Front :";
		cout<<"\n 3. Delete From Front :";
		cout<<"\n 4. Delete From Rear :";
		cout<<"\n 5. Display :";
		cout<<"\n 6. Exit :";
		
		cout<<"\nEnter Your Choice :";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter Element To Insert :";
				cin>>ele;
				ob.addRear(ele);
				break;
			case 2:
				cout<<"\nEnter Element To Insert :";
				cin>>ele;
				ob.addFront(ele);
				break;
			case 3:
				ob.removeFront();
				break;
			case 4:
				ob.removeRear();
				break;
			case 5:
				ob.display();
				break;
			case 6:
				cout<<"\n Program Ended Successfully ";
				break;
			default:
				cout<<"\nYou have Entered Wrong Choice";
		}
		
	}while(ch!=6);
	return 0;
}
