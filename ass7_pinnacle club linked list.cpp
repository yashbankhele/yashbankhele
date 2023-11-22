#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define TRUE 1
#define FALSE 0
#define SIZE 20
struct node
{
	int PRN;
	char name[SIZE];
	struct node *next;
}*head;

class sll
{
	public:
	sll();
	struct node *create();
	void display(struct node *);
	void total();
	void reverse(struct node *);
	struct node *insert_President();
	void insert_Member();
	void insert_Secretary();
	node *remove();
	node *concat(struct node *,struct node *);
	~sll();
};

sll::sll()
{
	head=NULL;
}

sll::~sll()
{
	node *temp,*temp1;
	temp=head->next;
	delete head;
	while(temp!=NULL)
	{
		temp1=temp->next;
		delete temp;
		temp=temp1;
	}
}

node *sll::create()
{
	node *temp=NULL, *New;
	int val,flag;
	char n[SIZE];
	char ans='y';
	flag=TRUE;
	do
	{		
		cout<<"\n Enter the PRN of student : ";
		cin>>val;
		cout<<"\n Enter the name of student : ";
		cin>>n;
		New=new node;
		if(New==NULL)
			cout<<"Unable to allocate memory\n";
		New->PRN=val;
		strcpy(New->name,n);
		New->next=NULL;
		if(flag==TRUE)
		{
			head=New;
			temp=head;
			flag=FALSE;
		}
		else
		{
			temp->next=New;
			temp=New;
		}
		cout<<"\nDo you want to enter more elements?(y/n)";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	return head;
}

void sll::display(node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		cout<<"\nThe list is empty\n";
		return;
	}
	while(temp!=NULL)
	{
		cout<<"["<<temp->PRN<<","<<temp->name<<"]";
		temp=temp->next;
	}
}

void sll::total()
{
	node *temp;
	int count=0;
	temp=head;
	if(temp==NULL)
	{
		cout<<"\nThe list is empty\n";
		return;
	}
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"\nTotal number of members in a club are : "<<count;
}

void sll::reverse(node *head)
{
	if(head==NULL)
		return;
	reverse(head->next);
	cout<<"["<<head->PRN<<","<<head->name<<"]";
}

node *sll::remove()
{
	node *temp,*prev;
	int key;
	prev=new node;
	temp=head;
	cout<<"\nEnter the PRN of node you want to delete : ";
	cin>>key;
	while(temp!=NULL)
	{
		if(temp->PRN==key)
			break;
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		cout<<"\nNode not found";
	else
	{
		if(temp==head)
			head=temp->next;
		else
			prev->next=temp->next;
		delete temp;
		cout<<"\nThe member is deleted\n";
	}
	return head;
}

//Function to insert at end

void sll::insert_Secretary()
{
	node *New,*temp;
	New=new node;
	cout<<"\nEnter the PRN of student : ";
	cin>>New->PRN;
	cout<<"\n Enter the name of student : ";
	cin>>New->name;
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=New;
		New->next=NULL;
	}
	cout<<"\nThe member is inserted\n";
}



void sll::insert_Member()
{
	int key;
	node *temp,*New;
	New=new node;
	cout<<"\nEnter the PRN of student : ";
	cin>>New->PRN;
	cout<<"\n Enter the name of student : ";
	cin>>New->name;
	if(head==NULL)
		head=New;
	else
	{
		cout<<"\nEnter the PRN after which you want to insert the node : ";
		cin>>key;
		temp=head;
		do
		{
			if(temp->PRN==key)
			{
				New->next=temp->next;
				temp->next=New;
				break;
			}
			else 
				temp=temp->next;
		}while(temp!=NULL);
	}
	cout<<"\nThe member is inserted\n";
}


node *sll::insert_President()
{
	node *New, *temp;
	New=new node;
	cout<<"\nEnter the PRN of student : ";
	cin>>New->PRN;
	cout<<"\n Enter the name of student : ";
	cin>>New->name;
	if(head==NULL)
		head=New;
	else
	{
		temp=head;
		New->next=temp;
		head=New;
	}
	cout<<"\nThe member is inserted\n";
	return head;
}

node *sll::concat(node *head1, node *head2)
{
	node *temp;
	temp=head1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=head2;
	cout<<"\nThe lists are concatinated\n";
	return head1;
}

int main()
{
	sll s;
	int choice,ch1;
	char ans='y';
	node *start=NULL;
	node *start1,*start2;
	start1=NULL;
	start2=NULL;
	do
	{
		cout<<"\n1.Create";
		cout<<"\n2.Display Members";
		cout<<"\n3.Insert Member";
		cout<<"\n4.Delete Member";
		cout<<"\n5.Total Members of Club";
		cout<<"\n6.Display list in reverse using recursion";
		cout<<"\n7.Concatenate two lists";
		cout<<"\n8.Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: start=s.create();
				break;
			case 2: s.display(start);
				break;
			case 3: cout<<"\nThe Members are\n";
				s.display(start);
				cout<<"\n**Menu**";
				cout<<"\n1.Insert President";
				cout<<"\n2.Insert Member";
				cout<<"\n3.Insert Secretary";
				cout<<"\n4.Enter your choice : ";
				cin>>ch1;
				switch(ch1)
				{
					case 1: start=s.insert_President();
						break;
					case 2: s.insert_Member();
						break;
					case 3: s.insert_Secretary();
						break;
					default: cout<<"\nInvalid choice";
				}
				break;
			case 4: start=s.remove();
				break;
			case 5: s.total();
				break;
			case 6: s.reverse(start);
				break;
			case 7: cout<<"\nEnter the data for first division\n";
				start1=s.create();
				cout<<"\nEnter the data for second division\n";
				start2=s.create();
				start=s.concat(start1,start2);
				break;
			case 8: exit(0);
				break;
			default: cout<<"\nInvalid choice";
		}
		cout<<"\nWant to go to main menu? : ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
	return 0;
}


