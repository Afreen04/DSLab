//double linked list

#include<iostream.h>
#include<conio.h>

#define us unsigned short

struct node
{int info;
 node *next;
 node *prev;
}*start,*start2,*temp;

void Addatbeg(int n)
{node *ptr=new node;
 ptr->info=n;
 ptr->next=start;
 ptr->prev=NULL;
 if(start!=NULL)
 start->prev=ptr;
 start=ptr;
}


void Addatend(int n)
{node *ptr=new node;
 ptr->info=n;
 ptr->next=NULL;
 temp=start;
 while(temp->next)
 {temp=temp->next;}
 temp->next=ptr;
 ptr->prev=temp;
}

void delfirst()
{temp=start;
 start=start->next;
 start->prev=NULL;
 delete temp;
}

void dellast()
{temp=start;
 node *prev=new node;
 while(temp->next)
 {prev=temp;
  temp=temp->next;
 }
 prev->next=NULL;
 delete temp;
}

void display1()
{temp=start;
 cout<<"\n";
 while(temp)
 {cout<<temp->info<<"\n";
  temp=temp->next;
 }
}

int main()
{int n,ch=1;
 cout<<"enter your choice: ";
 while(ch!=0)
 {cout<<"ch:";
  cin>>ch;
  switch(ch)
  {case 1:cout<<"Enter n:";cin>>n;Addatbeg(n);break;
   case 2:cout<<"Enter n:";cin>>n;Addatend(n);break;
   case 3:delfirst();break;
   case 4:dellast();break;
   case 5:display1();break;
   default:;   
  }
 }
 getch();
}
