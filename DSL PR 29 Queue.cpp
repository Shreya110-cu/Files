#include<iostream>
using namespace std;
#define MAX 25
class Queue
{
	private:
		int a[25];
		int front;
		int rear;
	public:
		Queue()
		{
			front=rear=-1;
		}
		int empty()
		{
			if(rear==-1)
			{
				return 1;
			}
			else 
			{
				return 0;
			}
		}
		int full()
		{
			if(rear==MAX-1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		void insert(int ele)
		{
			if(full())
			{
				cout<<"Queue Overflow ";
			}
			else
			{
				if(empty())
				{
				front=0;
				rear=0;
				a[rear]=ele;
				}
				else
				{
				rear++;
				a[rear]=ele;
				}
			}	
		}
		int remove()
		{
			int x;
			if(empty())
			{
				cout<<"Queue is already Empty";
				return 0;
			}
			else if(front==rear)
			{
				x=a[front];
				front=-1;
				rear=-1;	
			}
			else
			{
				x=a[front];
				front++;	
			}
			return x;
		}
		void display()
		{
			int i;
			if(front == -1)
			{
				cout<<"Queue is Empty ";
			}
			else
			{
				cout<<"Queue Elements are ";
				for(i=front;i<=rear;i++)
				{
					cout<<a[i]<<"\t";
				}
			}
		}
};
int main()
{
	Queue q1;
	int ch,element,no;
	do
	{
		cout<<"\n***Queue Operations***";
		cout<<"\n1. Insert Job ";
		cout<<"\n2. Delete Job ";
		cout<<"\n3. Display Jobs ";
		cout<<"\n4. Exit ";
	    cout<<"\nEnter Your Choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter Job ID to insert :";
				cin>>element;
				q1.insert(element);
				cout<<"\nElement Inserted successfully";	
				break;
			case 2:
				no=q1.remove();
				if(no!=0)
				{
					cout<<no<<" Job ID Deleted Successfully\n";	
				}
				break;
			case 3:
				q1.display();
				break;
			case 4:
				cout<<"\nProgram Ended Successfully";
				break;
			default:
				cout<<"\nYou Have Entered Wrong Choice ";	
		}	
	}while(ch!=4);
	return 0;
}
