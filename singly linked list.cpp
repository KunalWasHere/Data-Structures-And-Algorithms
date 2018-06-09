#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *insert(struct node *head,struct node *p,int pos,int x,int count)
{
    struct node *newnode=(node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    if(pos==count+1)
    {
        p->next=newnode;
        p=newnode;
        return p;
    }
    p=head;
    for(int i=1;i<pos-1;i++)
    {
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    return head;
}
void display(struct node *head)
{
    cout<<endl<<"the list so formed is :"<<endl;
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
struct node *remove(struct node *head,struct node *p,int pos,int count)
{
    struct node *q,*r;
    if(pos==1)
    {
        q=head;
        head=head->next;
        free(q);
        return head;
    }
    if(pos==count)
    {
        q=head;
        while(q->next->next!=NULL)
        {
            q=q->next;
        }
        r=q->next;
        free(r);
        q->next=NULL;
        return q;
    }
    q=head;
    for(int i=1;i<pos-1;i++)
    {
        q=q->next;
    }
    r=q->next;
    q->next=r->next;
    free(r);
    return r;
}
int main()
{
   int n,x,i,count=0,more,pos;
   char k;
   cin>>n;
   struct node *newnode,*head,*p,*q;
   cin>>x;
   newnode=(node*)malloc(sizeof(struct node));
   head=newnode;
   newnode->data=x;
   newnode->next=NULL;
   p=newnode;
   for(i=1;i<n;i++)
   {
       cin>>x;
       newnode=(node*)malloc(sizeof(struct node));
       newnode->data=x;
       newnode->next=NULL;
       p->next=newnode;
       p=newnode;
   }
   q=head;
   cout<<"linked list so formed is :"<<endl;
   while(q!=NULL)
   {
       cout<<q->data<<endl;
       q=q->next;
       count++;
   }
   start:
   cout<<"action:";
   cin>>k;
   if(k=='i')
   {
       cout<<"enter pos and data:";
       cin>>pos>>x;
       q=insert(head,p,pos,x,count);
       if(pos==1)
        head=q;
       if(pos==count+1)
        p=q;
       count++;
   }
   if(k=='d')
    display(head);
   if(k=='r')
   {
       cout<<"enter pos:";
       cin>>pos;
       q=remove(head,p,pos,count);
       if(pos==1)
        head=q;
       if(pos==count)
        p=q;
    count--;
   }
   cout<<"press 1 to enter more:";
   cin>>more;
   if(more==1)
    goto start;
}
