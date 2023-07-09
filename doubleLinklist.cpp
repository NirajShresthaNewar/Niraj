#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node*next;
  struct node*prev;
};
struct node*header=NULL;
struct node*getnode(int n)
{
   struct node*ptrnew=(struct node*)malloc(sizeof(struct node));
   if(ptrnew==NULL)
   {
      printf("Memory allocation failed.");
      getch();
      exit(0);
   }
   ptrnew->info=n;
   ptrnew->next=ptrnew->prev=NULL;
   return ptrnew;
}
void insertAtFront()
{
   struct node*ptrnew;
   int n;
   printf("\nEnter a number:");
   scanf("%d",&n);
   ptrnew=getnode(n);
   if(header==NULL)
     header=ptrnew;
   else
   {
      ptrnew->next=header;
      header->prev=ptrnew;
      header=ptrnew;
   }
   printf("\nInserted at the front.");
}
void insertAtEnd()
{
   struct node*ptrnew,*ptrthis;
   int n;
   printf("Enter a number:");
   scanf("%d",&n);
   ptrnew=getnode(n);
   if(header==NULL)
     header=ptrnew;
   else
   {
      for(ptrthis=header;ptrthis->next!=NULL;ptrthis=ptrthis->next);//move to last node
      ptrthis->next=ptrnew;
      ptrnew->prev=ptrthis;
   }
   printf("Inserted at the end.");
}
void insertAfter()
{
   struct node*ptrnew,*ptrthis;
   int n,key;
   if(header==NULL)
      printf("List is empty.");
   else
   {
      printf("Enter a number after which you want to insert new number:");
      scanf("%d",&key);
      for(ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
      {
	 if(ptrthis->info==key)
	 {
	     //insert new node after current node and then exit
	     printf("Enter a number:");
	     scanf("%d",&n);
	     ptrnew=getnode(n);
	     if(ptrthis->next!=NULL)//if current node is not the last node
		(ptrthis->next)->prev=ptrnew;
	     ptrnew->next=ptrthis->next;
	     ptrnew->prev=ptrthis;
	     ptrthis->next=ptrnew;
	     printf("Inserted after %d",key);
	     return;
	 }
      }
      printf("Key does not exist.");
   }
}
void insertBefore()
{
   struct node*ptrnew,*ptrthis;
   int n,key;
   if(header==NULL)
      printf("List is empty.");
   else
   {
      printf("Enter a number before which you want to insert new number:");
      scanf("%d",&key);
      for(ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
      {
	 if(ptrthis->info==key)
	 {
	     //insert new node before current node and then exit
	     printf("Enter a number:");
	     scanf("%d",&n);
	     ptrnew=getnode(n);
	     ptrnew->prev=ptrthis->prev;
	     ptrnew->next=ptrthis;
	     if(ptrthis==header)//if inserting before first node, then change header too
	       header=ptrnew;
	     else//if current node is not first node
	       (ptrthis->prev)->next=ptrnew;
	     ptrthis->prev=ptrnew;
	     printf("Inserted before %d",key);
	     return;
	 }
      }
      printf("Key does not exist.");
   }
}
void removeFromFront()
{
   struct node*ptrthis;
   if(header==NULL)
     printf("List is emtpy.");
   else
   {
      ptrthis=header;
      header=header->next;
      if(header!=NULL)
	header->prev=NULL;
      free(ptrthis);
      printf("Removed from front.");
   }
}
void removeFromEnd()
{
   struct node*ptrthis;
   if(header==NULL)
     printf("List is emtpy.");
   else
   {
      for(ptrthis=header;ptrthis->next!=NULL;ptrthis=ptrthis->next);
      if(ptrthis==header)
	header=NULL;
      else
	(ptrthis->prev)->next=NULL;
      free(ptrthis);
      printf("Removed from end.");
   }
}
void removeAny()
{
   struct node*ptrthis;
   int key;
   if(header==NULL)
     printf("List is emtpy.");
   else
   {
      printf("Enter your key:");
      scanf("%d",&key);
      for(ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
      {
	 if(ptrthis->info==key)
	 {
	    //remove and return;
	    if(ptrthis==header)
	    {
	       header=header->next;
	       header->prev=NULL;
	    }
	    else
	    {
	       if(ptrthis->next!=NULL)
		 (ptrthis->next)->prev=ptrthis->prev;
	       (ptrthis->prev)->next=ptrthis->next;
	    }
	    free(ptrthis);
	    printf("Removed");
	    return;
	 }
      }
      printf("Key not found.");
   }
}

void display()
{
   struct node*ptrthis;
   if(header==NULL)
     printf("List is empty.");
   else{
      printf("List contains:\n");
      for(ptrthis=header;ptrthis!=NULL;ptrthis=ptrthis->next)
	printf("%d\t",ptrthis->info);
   }
}
int main()
{
   char choice;
   header=NULL;//initially list is empty
   while(1)
   {
      system("cls");
      //clrscr();
      printf("Select your choice:\n");
      printf("1. Insert at front\n2. Insert at rear\n3. Insert After\n4. Insert Before\n");
      printf("5. Remove from front\n6. Remove from rear\n7. Remove Any\n");
      printf("8. Display\n9. Exit");
      choice=getche();
      switch(choice)
      {
	 case '1':insertAtFront();break;
	 case '2':insertAtEnd();break;
	 case '3':insertAfter();break;
	 case '4':insertBefore();break;
	 case '5':removeFromFront();break;
	 case '6':removeFromEnd();break;
	 case '7':removeAny();break;
	 case '8':display();break;
	 case '9':
		printf("Good bye");
		getch();
		exit(0);
	 default: printf("Invalid choice. Try again!");
      }
      getch();
   }
}

