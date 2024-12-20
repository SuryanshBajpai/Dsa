#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insertionFirst();  
void insertionLast();  
void insertionLoc();  
void deleteFirst();  
void deleteLast();  
void deleteLoc();  
void printList();  
void searchList();  
int main()  
{  
    int choice =0;  
    while(choice != 9)  
    {  
        printf("\nDoubly Linked ListMenu\n");    
        printf("\n1.Insert at begining\n");
        printf("2.Insert at last\n");
        printf("3.Insert at any random location\n");
        printf("4.Delete from Beginning\n");
        printf("5.Delete from last\n");
        printf("6.Delete the node after the given data\n");
        printf("7.Search\n");
        printf("8.Show\n");
        printf("9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
                insertionFirst();  
                break;  
            case 2:  
                insertionLast();  
                break;  
            case 3:  
                insertionLoc();  
                break;  
            case 4:  
                deleteFirst();  
                break;  
            case 5:  
                deleteLast();  
                break;  
            case 6:  
                deleteLoc();  
                break;  
            case 7:  
                searchList();  
                break;  
            case 8:  
                printList();  
                break;  
            case 9:  
                exit(0);  
                break;  
            default:  
                printf("Invalid Choice!!! Please try again....");  
        }  
    }  
    return 0;
}  
void insertionFirst()  
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW!!!");  
   }  
   else  
   {  
    printf("\nEnter value to insert: ");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted successfully....\n");  
}  
     
}  
void insertionLast()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW!!!");  
   }  
   else  
   {  
       printf("\nEnter value to insert: ");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nNode inserted successfully\n");  
    }  
void insertionLoc()  
{  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW!!!");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location: ");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\nThere are less than %d elements\n", loc);  
               return;  
           }  
       }  
       printf("Enter value: ");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("\nNode inserted successfully...\n");  
   }  
}  
void deleteFirst()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW!!!");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nNode deleted successfully....\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nNode deleted successfully....\n");  
    }  
  
}  
void deleteLast()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nUNDERFLOW!!!");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nNode deleted successfully...\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nNode deleted successfully...\n");  
    }  
}  
void deleteLoc()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\nEnter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete....\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nNode deleted successfully...\n");  
    }     
}  
void printList()  
{  
    struct node *ptr;  
    printf("\nThe Doubly Linked List is\nSTART %c ",29);  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d %c ",ptr->data,29);  
        ptr=ptr->next;  
    }  
    printf("NULL\n\n");
}   
void searchList()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nItem %d found at location %d ",item, i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem %d not found\n",item);  
        }  
    }     
          
}
