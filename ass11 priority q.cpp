
#include<iostream>
using namespace std;
#define size 50
int main()
{
int rear,front,que[50],choice;
int insert(int que[50],int rear,int front);
int Qfull(int rear);
int Qempty(int rear,int front);
int delet(int que[50],int front);
void display(int que[50],int rear,int front);
char ans;
front=0;
rear=-1;
do
{
	cout<<"\n\t\t prority queue\n";
	cout<<"\n Main Menu";
	cout<<"\n1.insert";
	cout<<"\n2.Delete";
	cout<<"\n3.display";
	cout<<"Enter your choice\n";
cin>>choice;
	switch(choice)
	{
		case 1:if(Qfull(rear))
			cout<<"q full\n";
		    else
			rear=insert(que,rear,front);
			break;
		case 2:if(Qempty(rear,front))
			cout<<"Can not delete element\n";
		    else
			front=delet(que,front);
			break;
		case 3:
			display(que,rear,front);
			break;
		default:
			break;
	}
		cout<<" do u continue (y/n)";
		cin>>ans;
}
while(ans=='y'||ans=='Y');
}
int insert(int que[50],int rear,int front)
{
	int item,j;
	cout<<"enter element ";
	cin>>item;
	if(front==-1)
	front++;
	j=rear;
	while(j>=0&& item<que[j])
	{

	que[j+1]=que[j];
	j--;
	}
	que[j+1]=item;
	rear=rear+1;
	return rear;
}
int Qfull(int rear)
{

	if(rear==size-1)
 	cout<<"full";
	else
   	return 0;
}
int delet(int que[50],int front)
{
	int item;
	item=que[front];
	cout<<"\n the item deleted is"<<item;
	front++;
	return front;
}
void display(int que[50],int rear,int front)
{	 int i;
	for(i=front;i<=rear;i++)
	{
	cout<<"queue="<<que[i];
	}
}
int Qempty(int rear,int front)
{

if(front==-1||front>rear)
return 1;
else 
return 0;
}
