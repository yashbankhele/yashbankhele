#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

node *createnode()
{
	int i,n;
	node *p,*head,*t;
	head=NULL;
	//printf("\nEnter the no. of students : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
		printf("\nEnter the roll numbers of students  : ");
		scanf("%d",&(p->data));
		p->next=NULL;
		if(head==NULL)
			head=p;
		else
		{
			t=head;
				while(t->next!=NULL)
					t=t->next;
				t->next=p;
		}
	}
        return head;
}
	
	void print(node *head)
	{
		node *p;
		int cnt=0;
		p=head;
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p=p->next;
			cnt++;
		}
		printf("\nTotal no. of students=%d",cnt);
	}
	int uni(node *head1,node *head2)
	{
		node *p,*q;
		int found=0,count=0;
		p=head1;
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p=p->next;
			count++;
		}
		for(q=head2;q!=NULL;q=q->next)
		{
			found=0;
			for(p=head1;p!=NULL;p=p->next)
			{
				if(q->data==p->data)
				{
					found=1;
					break;
				}
			}
			if(found!=1)
			{
				printf("\t%d",q->data);
				count++;
			}
		}
		return count;
	}

	void inter(node *head1,node *head2)
	{
		node *p,*q;
		int found=0;
		for(q=head2;q!=NULL;q=q->next)
		{		
			found=0;
			for(p=head1;p!=NULL;p=p->next)
			{
				if(q->data==p->data)
				{
					found=1;
					break;
				}
			}
			if(found==1)
				printf("\t%d",q->data);
		}
	}

	
	int main()
	{
		node *head,*head1;
		int ch=0,ele,loc,m,count;
		head=head1=NULL;
		printf("\nEnter the total no. of second year computer students : ");
		scanf("%d",&m);
		head=NULL;
		while(ch!=6)
		{
			printf("\n=============Sets UsingSLL==============\n");
			printf("\n1.Create\n 2.Print\n 3.Like both vanilla and butterscotch\n 4.Like either vanilla or butterscotch\n 5.Like niether vanilla nor butterscotch\n");
			
			printf("6.Exit\nEnter your choice : ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: printf("\n!!!Total Students who like vanilla!!!\n");
					head=createnode();
					printf("\n!!!Total Students who like butterscotch!!!\n");
					head1=createnode();
					break;
				case 2: printf("\n!!!Students who like vanilla!!!\n");
					print(head);
					printf("\n!!!Students who like butterscotch!!!\n");
					print(head1);
					break;
				case 3: printf("\n!!!Students who like both vanilla & butterscotch!!!\n");
					inter(head,head1);
					break;
				case 4: printf("\n!!!Students who like vanilla or butterscotch!!!\n");
					count=uni(head,head1);
					break;
				case 5: 
				printf("\n Number of students like neither vanilla nor buttescotch=%d",m-count);
					break;
			}
		}
	return 0;
}

