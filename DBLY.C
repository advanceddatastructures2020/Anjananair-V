#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
struct node *next;
int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main()
{
int choice =0;
while(choice != 9)
{
printf("\n ***********MENU*******\n");
printf("\n choose the option");
printf("\n 1.insert at beginning\n 2.insert at end\n3.insert at specified\n4.delete from beginning\n 5.delete from last\n 6.delete from specified\n 7.search\n8.show\n 9.exit\n");
printf("enter your choice\n");
scanf("%d" , &choice);
switch(choice)
{
case 1:
insertion_beginning();
break;
case 2:
insertion_last();
break;
case 3:
insertion_specified();
break;
case 4:
deletion_beginning();
break;
case 5:
deletion_last();
break;
case 6:
deletion_specified();
break;
case 7:
search();
break;
case 8:
display();
break;
case 9:
exit(0);
break;
default:
printf("please enter a valid choice");
}
}
getch();
}
void insertion_beginning()
{
struct node*ptr;
int item;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\n overflow");
}
else
{
printf("\n enter the item value");
scanf("%d",&item);
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
ptr->data=item;
head=ptr;
}
else
{
ptr->data=item;
ptr->prev=NULL;
ptr->next=head;
head=ptr;
}
printf("\n node inserted");
}
}
void insertion_last()
{
struct node *ptr,*temp;
int item;
ptr=(struct node *)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\n overflow");
}
else
{
printf("\n enter a value");
scanf("%d",&item);
ptr->data=item;
if(head==NULL)
{
ptr->next=NULL;
ptr->prev=NULL;
head=ptr;
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->prev=temp;
ptr->next=NULL;
}
}
printf("\n node inserted\n");
}
void insertion_specified()
{
struct node *ptr,*temp;
int item,loc,i;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\n overflow\n");
}
else
{
temp=head;
printf("enter the location\n");
scanf("%d",&loc);
for(i=0;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("\n there are less than %d elements",loc);
return;
}
}
printf("enter value");
scanf("%d",&item);
ptr->data=item;
ptr->next=temp->next;
ptr->prev=ptr;
temp->next->prev=ptr;
printf("\n node inserted\n");
}
}
void deletion_beginning()
{
struct node *ptr;
if(head==NULL)
{
printf("\n underflow");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("\n node deleted");
}
else
{
ptr=head;
head=head->next;
head->prev=NULL;
free(ptr);
printf("\n node deleted\n");
}
}
void deletion_last()
{
struct node *ptr;
if(head==NULL)
{
printf("\n underflow\n");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("\n node deleted\n");
}
else
{
ptr=head;
if(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->prev->next=NULL;
free(ptr);
printf("\n node deleted\n");
}
}
void deletion_specified()
{
struct node *ptr,*temp;
int val;
printf("\n enter the value after which node to deleted\n");
scanf("%d",&val);
ptr=head;
while(ptr->data!=val)
ptr=ptr->next;
if(ptr->next==NULL)
{
ptr->next=NULL;
}
else
{
temp=ptr->next;
ptr->next=temp->next;
temp->next->prev=ptr;
free(temp);
printf("\n node deleted\n");
}
}
void display()
{
struct node *ptr;
printf("\n printing values\n");
ptr=head;
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr=head;
if(ptr==NULL)
{
printf("\n empty list\n");
}
else
{
printf("\n enter item which you want to search\n");
scanf("%d",&item);
while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("\n item found at location%d",i+1);
flag=0;
break;
}
else
{
flag=1;
}
i++;
ptr=ptr->next;
}
if(flag==1)
{
printf("\n items not found");
}
}
}


