// linked list random 100 sorting number code

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

typedef struct list{int data ;struct list *next;} list;//recursion
int is_empty(const list *l){return(l==NULL);}


list* create_list(int d)
{
    list*head=malloc(sizeof(list));
    head->data=d;
    head->next=NULL;
    return head;

}

list* add_to_front(int d,list* h)
{
    list*head=create_list(d);
    head->next=h;
    return head;

}
list* array_to_list(int d[],int size)
{
    list*head=create_list(d[0]);
    int i;
    for(i=1;i<size;i++){
    head=add_to_front(d[i],head);
    }
    return head;
}

void print_list(list*h,char*title){
    printf("%s\n",title);
    while(h!=NULL){static int k=0;
        printf("%d :",h->data);
        h=h->next;
        k++;
        if(k%5==0){
            printf("\n");
        }

    }
}

/* function to swap data of two list a and b*/
void swap(list *a, list*b)  
{  
    int temp = a->data;  
    a->data = b->data;  
    b->data = temp;  
} 

list* bubbleSort(list *start)  
{  
    int swapped, i;  
    list *ptr1;  
    list *lptr = NULL;  
  
    /* Checking for empty list */
    if (start == NULL)  
        return NULL;  
  
    do
    {  
        swapped = 0;  
        ptr1 = start;  
  
        while (ptr1->next != lptr)  
        {  
            if (ptr1->data > ptr1->next->data)  
            {  
                swap(ptr1, ptr1->next);  
                swapped = 1;  
            }  
            ptr1 = ptr1->next;  
        }  
        lptr = ptr1;  
    }  
    while (swapped);  
}  
  

  


int main()
{  
   srand(time(NULL));
   list*head=NULL;
   int data[100];
   for(int i=0;i<100;i++)
   {
      data[i]=rand()%10000+1;

   }
   head=array_to_list(data,100);
   print_list(head,"Multiple Element List") ;
   printf("\n\n");
   print_list(bubbleSort(head),"Multiple Element List After Sorting") ;
   printf("\n\n");

 return 0;  
}