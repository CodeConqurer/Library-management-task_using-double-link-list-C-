#include <iostream>
using namespace std;
struct book
{
  int ID;
  string title;
  string authorName;
  string genre;
};

class node
{
  book *b1;
  node *next;
  node *pre;

public:
  node()
  {
    this->next = NULL;
    this->pre = NULL;
  }

  node(book b)
  {
   
    this->next = this->pre = NULL;
    this->b1=new book;
    this->b1->authorName = b.authorName;
    this->b1->genre = b.genre;
    this->b1->ID = b.ID;
    this->b1->title = b.title;
  }

  friend class library;
};

class library
{
  node *head;
  node *tail;

public:
  library()
  {
    head = nullptr;
    tail = head;
  }
  library(book b)
  {

    head = nullptr;
    tail = head;
  }

  void insertatend(book b)
  {
    node *newnode = new node(b);
    if (head == nullptr)
    {
      head = newnode;
      newnode->pre = NULL;
      tail = newnode;
    }

    else
    {
      node *temp = head;
      while (temp->next != nullptr)
      {

        temp = temp->next;
      }

      temp->next = newnode;
      newnode->pre = temp;
      tail = newnode;
    }
  }

  void insertatfront(book b){
    node*newnode=new node(b);
    newnode->next=head;
    head->pre=newnode;
    head=newnode;

  }
  
  void insertafternode(int pos,book b){
    node*temp=head;
    int count=1;
    while(count!=pos-1){
      count++;
      temp=temp->next;
    }
   
    node*newnode=new node(b);
    newnode->next=temp->next;

     temp->next=newnode;
    newnode->pre=temp;
      newnode->next->pre=newnode;
  }

  bool update(int id, book b){
    bool flag=false;
    node*temp=head;
     
    while(temp!=NULL){
      if(temp->b1->ID==id){
        temp->b1->authorName=b.authorName;
        temp->b1->genre=b.genre;
        temp->b1->ID=b.ID;
        temp->b1->title=b.title;
        flag=true;
       return flag;
        

      }

      else{
        temp=temp->next;
      }
     
    }

 return flag;
                        
  }

 bool remove(int id){
bool flag = false;
node* pre = head;
node* temp = head;
while(temp != NULL){
if(temp->b1->ID == id){
 
  pre->next = temp->next;

temp->next->pre = pre;

flag = true;
break;
}
else{
pre = temp;
temp = temp->next;
}
}
return flag;
}
  //void insertatfront()
  void display()
  {
    node *temp = head;
    while (temp != NULL)
    {
      cout << temp->b1->authorName << "\t" << temp->b1->genre << "\t" << temp->b1->ID << "\t" << temp->b1->title << endl;
      temp = temp->next;
    }
  }
};

int main()
{
  library l1;

  book b;
  b.authorName = "John";
  b.genre = "B";
  b.ID = 1;
  b.title = "Geography";


  book b1;
  b1.authorName = "Berrel";
  b1.genre = "B";
  b1.ID = 2;
  b1.title = "History";

  book b2;
b2.authorName = "Carola";
b2.genre = "B";
b2.ID = 3;
b2.title = "Literature";
  
  l1.insertatend(b);
  l1.insertatend(b1);
  cout<<"\n\nAfter inserting at end: "<<endl;
  l1.display();
  l1.insertatfront(b2);
  l1.insertafternode(2,b1);
    cout<<"\n\nAfter inserting at front: "<<endl;

  l1.display();
  if(l1.update(1,b2)==false){
    cout<<"----Not found-----//"<<endl;
  }
      cout<<"\n\nAfter updating record of ID#1: "<<endl;

  l1.display();
  
  if(l1.remove(2)==false){
    cout<<"----Not Found----"<<endl;
  }

  
  
   cout<<"\n\nAfter removing record of ID#2:  "<<endl;

 l1.display();
  return 0;
}