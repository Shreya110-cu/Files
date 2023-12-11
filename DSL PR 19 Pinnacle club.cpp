#include<iostream>
using namespace std;
typedef struct node
{
	int rollno;
	string name;
	struct node *next;
};
class student
{
	private:
		node *head;
	public:
		student()
		{
			head=NULL;	
		}
	node* create()
	{
		if(head == NULL)
		{
			int r;
			string n;
			node *h=new node;
			cout<<"\nEnter Name of Presedient :";
			cin>>n;
			cout<<"\nEnter PRN No of Presedient :";
			cin>>r;
			h->rollno=r;
			h->name=n;
			h->next=NULL;
			head=h;	
		}
		else
		{
			cout<<"linked list is already created";
		}
		return head;
	}
	void display(node *h)
	{
		while(h!=NULL)
		{
			cout<<"Name :"<<h->name<<"\t";
			cout<<"PRN No :"<<h->rollno<<"\n";
			h=h->next;
		}
	}
	void add_m(node *h)
	{
		if(h == NULL)
		{
			cout<<"linked list is not created";
		}
		else
		{
			node *temp =h;
			int i,loc;
			
			cout<<"Enter Location of Insert Member(Except location first & last) :";
			cin>>loc;
			for(i=1;i<loc-1;i++)
			{
				temp=temp->next;
			}
			
			int r;
			string n;
			node *m=new node;
			cout<<"\nEnter Name of Member :";
			cin>>n;
			cout<<"\nEnter PRN No of Member :";
			cin>>r;
			m->rollno=r;
			m->name=n;
			m->next=NULL;	
		
			m->next=temp->next;
			temp->next=m;
			cout<<"Member Added Successfully";	
		}
	}
	node* add_p(node *h)
	{
		node *p;
		if(h == NULL)
		{
	 		p =create();
	 		return p;
		}
		else
		{
			int r;
			string n;
			node *m=new node;
			cout<<"\nEnter Name of Precident :";
			cin>>n;
			cout<<"\nEnter PRN No of Precident :";
			cin>>r;
			m->rollno=r;
			m->name=n;
			m->next=h;
			cout<<"Precident Added successfully";
			return m;
		}	
	}
	void add_s(node *h)
	{
		node *temp=h;
		if(h == NULL)
		{
	 		cout<<"Linked list not created";
		}
		else
		{
			int r;
			string n;
			node *m=new node;
			cout<<"\nEnter Name of Secretory :";
			cin>>n;
			cout<<"\nEnter PRN No of Secretory :";
			cin>>r;
			m->rollno=r;
			m->name=n;
			m->next=NULL;
			
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=m;
		
			cout<<"Secretory Added successfully";
			
		}	
	}
	
	node* delete_p(node* h)
	{
		node* temp;
		if(h==NULL)
		{
			cout<<"\n Linked List is not present so not possible to delete!!! ";
		}
		else
		{
			temp=h;
			h=h->next;
			delete temp;
			cout<<"\n President Deleted";
			return h;
		}	
	}
	void delete_s(node* h)
	{
		node* temp ,*q;
		if(h==NULL)
		{
			cout<<"\n Linked List is not present so not possible to delete!!! ";
		}
		else
		{
			temp=h;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			q=temp->next;
			temp->next=NULL;
			delete q;
			cout<<"\n Secretory Deleted";
			
		}	
	}
	
	void delete_m(node* h)
	{
		node* temp ,*q;
		if(h==NULL)
		{
			cout<<"\n Linked List is not present so not possible to delete!!! ";
		}
		else
		{
			temp=h;
			int i,loc;
			cout<<"\n Enter location of member you want to delete(except one & last) :";
			cin>>loc;
			if(loc==1)
			{
				cout<<"\n You Are Trying to delete Precedent!!! please enter correct location ";
				return;
			}
			for(i=1;i<loc-1;i++)
			{
				temp=temp->next;
			}
			q=temp->next;
			temp->next=q->next;
			delete q;	
			cout<<"\n Member Deleted";	
		}	
	}
	void count_n(node* h)
	{
		if(h==NULL)
		{
			cout<<"\n Linked List is not present :";	
		}
		else
		{
			node* temp=h;
			int count=0;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			cout<<"\n Total number of menbers are :"<<count;
		}	
	}
	
	void concat(node* h)
	{
		node *temp,*nh=NULL,*q,*oldh;
		int no,i;
		cout<<"\n Number of members in new list:";
		cin>>no;
		
		for(i=0;i<no;i++)
		{
			q =new node;
			cout<<"\n Enter Member Name:";
			cin>>q->name;
			cout<<"\n Enter PRN No:";
			cin>>q->rollno;
			q->next=NULL;
			if(nh==NULL)
			{
				nh=q;
				temp=nh;
			}
			else
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;	
				}
				temp->next=q;
			}		
		}
	
		oldh=h;
		while(oldh->next!=NULL)
		{
			oldh=oldh->next;
		}
		oldh->next=nh;
		
	}
		
	void menu()
	{
		node *p=NULL;
		int ch;
		do
		{
			cout<<"\n1. Create";
			cout<<"\n2. Add President ";
			cout<<"\n3. Add Member ";
			cout<<"\n4. Add sectretory ";
			cout<<"\n5. Display";
			cout<<"\n6. Delete President";
			cout<<"\n7. Delete Sectretory";
			cout<<"\n8. Delete Member";
			cout<<"\n9. Count Total Members:";
			cout<<"\n10. Concatenation";
			cout<<"\n11. Exit";
			
			cout<<"\nEnter your choice:";
			cin>>ch;
			switch(ch)
			{
				case 1:
					p =create();
					break;
				case 2:
					p=add_p(p);
					break;
				case 3:
					add_m(p);
					break;
				case 4:
					add_s(p);
					break;
				case 5:
					display(p);
					break;
				case 6:
					p=delete_p(p);
					break;
				case 7:
					delete_s(p);
					break;
				case 8:
					delete_m(p);
					break;
				case 9:
					count_n(p);
					break;
				case 10:
					concat(p);
					break;
				case 11:
					cout<<"Thank You For Visiting Club";
					break;
				default:
					cout<<"You have Entered wrong choice";		
			}	
		}while(ch!=11);			
	}
		
};
int main()
{
	cout<<"Singly linked list";
	student s1;
	s1.menu();		
	return 0;	
}
