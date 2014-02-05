//8 queen problem using backtracking for one solution

#include<iostream.h>
#include<conio.h>

struct pos
{int r,c;
};

int MAX=8,top=-1,ctr=0;
pos stack[10];

int check(pos cur)    //This function checks if we can place the queen here
{int i;
 if(top==0)
  return 1;      //1st queen
 for(i=0;i<top;i++)
 {if(stack[i].r==cur.r)   //same row
   return -1;     //hinderance
  else if(stack[i].c==cur.c)   //same column
    return -1;
  else if(stack[i].c==(cur.c-(cur.r-stack[i].r)   //be careful, we subtract the rows
                 )
     )   //same diagnol on right
    return -1;
  else if(stack[i].c==(cur.c+(cur.r-stack[i].r)    //be careful, we subtract the rows
                 )
     )   //same diagnol on left
    return -1;
 }
 return 0;  //no problem
}

pos determinecur(pos cur)            //this function determines the current queen to be placed
{if(stack[top].r!='\0')          //if we are backtracking to an already existing pos(already placed queen)
  {
  if(cur.c!=7)
  {cur.c=stack[top].c+1;   //setting column
   return cur;
  }
  else                        //this cant be incremented anymore
  {stack[top].r='\0';         //take this queen off the board and go back to previous queen
   stack[top].c='\0';
   top--;
   determinecur(stack[top]);
  }
  }
 else
 {cur.c=0;    //new assignment
 cur.r=top;
 return(cur);
 } 
}

void create()
{ 
 while(top<MAX)
 { 
 
 if(top==-1)                  //1st queen 
  {stack[++top].r=0;
   stack[top].c=0;
   top++;
   continue;
  }
  
 else
 {pos cur=determinecur(stack[top]);          //determine which queen to consider
 int flag=0,i=cur.c;
 for(;i<8;i++)
 {cur.c=i;
  if(check(cur)==0||check(cur)==1)
  {flag++;
   break;}           //solution found
 }    
 if(flag==1)
  stack[top++]=cur;
 else
  {stack[top].r='\0';
   stack[top].c='\0';
   top--;
  }
 }
 cout<<"";               //THIS IS THE COUT I WAS TALKING ABOUT. WHY CAN'T I REMOVE THIS? 
 }
}


int main()
{create();
 int i;
 cout<<"The positions are:\n";
 for(i=0;i<8;i++)
  {cout<<stack[i].r<<" "<<stack[i].c<<"\n";}
 getch();
}
//kaneez2001@gmail.com
