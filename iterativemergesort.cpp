// An iterative implementation of quick sort
#include <stdio.h>
#include<conio.h>
// A utility function to swap two elements
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
   
   int x=arr[h];
   int i=l-1;
   for(int j=l;j<h;j++)
   {if(x>=arr[j])
    {i++;
     swap(&arr[i],&arr[j]);
    }
   }
   swap(&arr[i+1],&arr[h]);
   return (i+1);
    /*
    int p=l,pivot=arr[l],loc;
    for(loc=l+1;loc<=h;loc++)
    {if(arr[loc]<p)
     {arr[p]=arr[loc];
      arr[loc]=arr[p+1];
      arr[p+1]=pivot;
     p=p+1;
     }
     
    }
    return p;*/
}
 
 void mergeSort(int arr[],int low,int mid,int high)
{

    int i,m,k,l,temp[100];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){    

         if(arr[l]<=arr[m]){      //take from 1st array if its less
             temp[i]=arr[l];
             l++;
         }
         else{                //otherwise take from 2nd
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;                     //keep incrementing i
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}

 
/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
  int stack[h-l+1];
  int top=-1;
  stack[++top]=l;
  stack[++top]=h;
  while(top>-1)
  {h=stack[top--];
   l=stack[top--];
   if(l<h)
   {
   int mid=(l+h)/2;
   
   {stack[++top]=l;
    stack[++top]=mid;
   }
   
   {stack[++top]=mid+1;
    stack[++top]=h;
   }
   mergeSort(arr,l,mid,h);
  }}

}
 
// A utility function to print contents of arr
void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
        printf( "%d ", arr[i] );
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int n = sizeof( arr ) / sizeof( *arr );
    quickSortIterative( arr, 0, n - 1 );
    printArr( arr, n );
    getch();
    return 0;
}
