#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
#include<process.h>
struct queue
{
	int item[MAX];
	int rear;
	
};
void enqueue( struct queue *q, int val)
{
	if(q->rear==MAX-1)
	{
		printf("\nQueue Is Full. You Cant Add Any things.\n");
	}
	else
	{
		q->rear++; //simplified ma ++q->rear muni
		q->item[q->rear]=val;
		printf("\nEntered Sucessfulled! Move On.\n");
	}
}
int dequeue(struct queue*q)
{
int val,i;
if(q->rear=-1)
	{
		printf("Queue is Empty .you cant remove any items from empty queue");
		exit(0);
	}
else
	{
		int val=q->item[0];
		for(int i=1;i<=q->rear;i++)
		
			q->item[i-1]=q->item[i]; // 5th position ko value 4th .4th ko third yo type ma aagadi sarxa
			q->rear--;
			return val;
	}
}

void display(struct queue q)
{
	int i;
if(q.rear==-1)
{
	printf("\nQueue is empty");
}	
else
{
		printf("/nQueue Contains");
		for(i=0;i<=q.rear;i++)
		{
		printf("%d\t",q.item[i]);
		}	
}
}
int main()
{
	int n; //value halna
	struct queue q;
	char ch;
	q.rear=-1;
	while(1)
	{
		
	system("cls");
	 			printf("1. Inqueue\n");
    			printf("2. Dequeue\n");
        		printf("3. Display\n");
        		printf("4. Exit\n");
        		ch = getchar();
					switch(ch)
					{
						
						case'1':
								printf("\nEnter Number:");
								scanf("%d",&n);
								enqueue(&q,n);
								break;
						case '2': 
								if(q.rear==-1)
								{
									printf("/nQueue Empty/n");
									
								}
								else
								{
								n=dequeue(&q);
								printf("\n%d removed",n);
								
								}
								break;
						case '3':
							display(q);
					
							break;
							
						case '4': return 0;	
					}	
					getch();
					
	}	
	}
   


	
	
	

