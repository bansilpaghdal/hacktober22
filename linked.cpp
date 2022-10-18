#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
int info;
node* link;

};
node* start=NULL;
struct node * createnode()
 {
    node* n;
    n= new node;
    return n;

 }
  void insertnode(){
  node *temp,*t;
  temp=createnode();
  cout<<"Enter the value";
  cin>>temp->info;
  temp->link=NULL;

   if(start==NULL)
   start=temp;

   else{
   t=start;
   while(t->link!=NULL)
   t=t->link;
   t->link=temp;
      }
  }

void deletenode()
{
    if(start==NULL)
cout<<"list is empty";
else{
  node *r;
  r=start;
  start=start->link;

  }

}

void traversal()
{
  node *p;
  p=start;
  while(p!=NULL)
  {
   cout<<p->info;
   p=p->link;

  }
}

  int menu(){
  int ch;
  cout<<"1. Add Value";
  cout<<"\n 2. Delete first node";
  cout<<"\n 3. view list";
  cout<<"\n exit";
  cout<<"\nenter the choice";
  cin>>ch;
  return ch;


  }
  int main()
  {

while(1)
{
  switch(menu()){
  case 1:insertnode();
  break;
    case 2:deletenode();
    break;
     case 3:traversal();
     break;

        default:cout<<"wrong choice";
}
}
  }
