#include<iostream>
using namespace std;
int size;
	
struct SLL_Node	
{
    int start;
    int end;
    int min;
    int max;
    int flag;
    struct SLL_Node *next;
}*head;


class App_Shedule
{
  public:
	void create_Shed();
         	 
	void display_Shed();

	void book_App();

	void cancel_App();

	void sort_App();
	
}A1;


int main()
{
   int ch;
   char ans;
   
   do
   {    
      cout<<"\n\n *** Menu ***";
      cout<<"\n 1. Create Appointment Schedule";
      cout<<"\n 2. Display Free Slots";
      cout<<"\n 3. Book an Appointment";
      cout<<"\n 4. Cancel an Appointment";
      cout<<"\n 5. Sort slots based on Time";

      
      cout<<"\n\n\t Enter your choice: ";                        
      cin>>ch;
      
      switch(ch)
      {
         case 1: A1.create_Shed();
         	 break;
         	 
         case 2: A1.display_Shed();
         	 break;         	 
         	 
         case 3: A1.book_App();
         	 break;
         	 
         case 4: A1.cancel_App();
         	 break;

         case 5: A1.sort_App();
         	 break;
         	 
         default: cout<<"\n\t Wrong choice!!!";
	          	 
      }
      
      cout<<"\n\n\t Do you wanna continue? (y/n) : ";
      cin>>ans;
   }while(ans == 'y');
   
}


void App_Shedule :: create_Shed()           //Function Definition to create Appointment Schedule
{
    int i;
    struct SLL_Node *temp, *last;
    head = NULL;
    cout<<"\n\n\t How many Appointment Slots: ";
    cin>>size;
    for(i=0; i<size; i++)
    {
       temp = new(struct SLL_Node);         // Step 1: Dynamic Memory Allocation
       
       cout<<"\n\n\t Enter Start Time: ";   // Step 2: Assign Data & Address
       cin>>temp->start; 
       cout<<"\n\t Enter End Time: ";
       cin>>temp->end;
       cout<<"\n\n\t Enter Minimum Duration: ";
       cin>>temp->min;
       cout<<"\n\t Enter Maximum Duration: ";
       cin>>temp->max;
       temp->flag = 0;
       temp->next = NULL;
       
       if(head == NULL)
       {
          head = temp;
          last = head;
       }
       else
       {
          last->next = temp;
          last = last->next;
       }
       
    }
}

void App_Shedule :: display_Shed()          //Function Definition to Display Appointment Schedule         
{
   int cnt = 1;
   struct SLL_Node *temp;
   
   cout<<"\n\n\t ****Appointment Schdule****";
   cout<<"\n\n\t Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";        
   
   temp = head;
   while(temp != NULL)
   {
      cout<<"\n\n\t "<<cnt;
      cout<<"\t "<<temp->start;
      cout<<"\t "<<temp->end;
      cout<<"\t  "<<temp->min;
      cout<<"\t  "<<temp->max;
      
      if(temp->flag)
         cout<<"\t-Booked-";                        
      else
         cout<<"\t--Free--";         
         
      temp = temp->next; 
      cnt++;  
   }
}


void App_Shedule :: book_App()              //Function Definition to Book Appointment
{
    int start;
    struct SLL_Node *temp;

    cout<<"\n\n\t Please enter Appointment time: ";
    cin>>start;
 
   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 0)
         {
            cout<<"\n\n\t Appointment Slot is Booked!!!";
            temp->flag = 1;
         }
         else
            cout<<"\n\n\t Appointment Slot is not Available!!!";
      }

      temp = temp->next; 
   }

}
      
         

void App_Shedule :: cancel_App()            //Function Defination to Cancel Appointment
{
    int start;
    struct SLL_Node *temp;

    cout<<"\n\n\t Please enter Appointment time to Cancel: ";
    cin>>start;
 
   temp = head;

   while(temp != NULL)
   {
      if(start == temp->start)
      {
         if(temp->flag == 1)
         {
            cout<<"\n\n\t Your Appointment Slot is Canceled!!!";
            temp->flag = 0;
         }
         else
            cout<<"\n\n\t Your Appointment was not Booked!!!";
      }

      temp = temp->next; 
   }
}


void App_Shedule :: sort_App()              
{
   int i,val;
   struct SLL_Node *temp,*tempnext;


   for(i=0; i < size-1; i++) 	
   {
       temp = head;
       while(temp->next != NULL)
       { 
       	  tempnext=temp->next;
          if(temp->start > tempnext->start)
          {
            val = temp->start;
	        temp->start = tempnext->start;
	        tempnext->start = val;

            val = temp->end;
	        temp->end = tempnext->end;
	        tempnext->end = val;

            val = temp->min;
	        temp->min = tempnext->min;
	        tempnext->min = val;

            val = temp->max;
	        temp->max = tempnext->max;
	        tempnext->max = val;
	        
	        val=temp->flag;
	        temp->flag=tempnext->flag;
	        tempnext->flag=val;
	
          }
          temp = temp->next;
       }   
   }

   cout<<"\n\n\t The Appointments got Sorted!!!";

}

