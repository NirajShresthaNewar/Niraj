#include<stdio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>
#define MAX 100
struct stack{
   char items[MAX];
   int tos;
};
void push(struct stack *sp,char ch)
{
   sp->items[++sp->tos]=ch;
   return;
}
char pop(struct stack *sp)
{
   return sp->items[sp->tos--];
}
char peek(struct stack *sp)
{
   return sp->items[sp->tos];
}
int getPrecedence(char ch)
{
   switch(ch)
   {
      case '(': return 0;
      case '+':
      case '-': return 1;
      case '*':
      case '/': return 2;
      case '$': return 3;
   }
}
int main()
{
   char infix[MAX],ch;
   int i;
   struct stack opstack,poststack;
   opstack.tos=poststack.tos=-1;
   system("cls");
   printf("Enter your infix expression:");
   gets(infix);
   for(i=0;i<strlen(infix);i++)
   {
      if(infix[i]=='(')
	 push(&opstack,infix[i]);
      else if(isalnum(infix[i]))
	 push(&poststack,infix[i]);
      else if(infix[i]==')')
      {
	 while(ch=pop(&opstack)!='(')
	   push(&poststack,ch);
	 /*do{
	   ch=pop(&opstack);
	   if(ch!='(')
	     push(&poststack,ch);
	 }while(ch!='(');*/
      }
      else//if operator
      {
	 if(opstack.tos==-1)
	   push(&opstack,infix[i]);
	 else
	 {
	    while(getPrecedence(infix[i])<=getPrecedence(peek(&opstack)))
	    {
	       ch=pop(&opstack);
	       push(&poststack,ch);
	       if(opstack.tos==-1)break;
	    }
	    push(&opstack,infix[i]);
	 }
      }
   }
   while(opstack.tos!=-1)
   {
      push(&poststack,pop(&opstack));
   }
   while(poststack.tos!=-1)
     printf("%c",pop(&poststack));
   getchar();
   return 0;
}
