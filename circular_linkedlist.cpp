#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node*next;

    //constructor

    node(int d)
    {
        this->data=d;
        this->next=NULL;

    }

    //destructor
    ~node()
    {
        int value=this->data;
        if(this->next!=NULL)
        {
            next=NULL;

        }

        cout<<"memory is free for node with data"<<value<<endl;
    }


};

void insertnode(node*&tail,int element,int d)
//assuming the elements present in the list
{
// case 1:-> LIST IS EMPTY
if (tail==NULL)
{
    node*temp=new node(d);
    tail=temp ;
    temp ->next=temp ;

}
else{
    //non empty list
    //assuming that the element is present in the list

    node* curr=tail;

    while(curr->data!=element){
        curr=curr->next;

    }
    //element found->curr is representing element vala node
    node*temp=new node(d);
    temp->next=curr->next;
    curr->next=temp;

   }

}
void print(node*tail)
//{
     //node*temp=tail;

//     while(tail->next!=temp)       //is method se hm single node nahi print krva sakte      
//     {
//         cout<<tail->data<<" ";
//         tail=tail->next;
//     }
// }


//ab hm do while se krege 
{
    node*temp=tail;
    
    if(tail==NULL)
     {
        cout<<"tail is empty"<<endl;
           return;
    }
    

    do{
        cout<<tail->data<<" ";
        tail=tail->next;

    } while(tail != temp);
    cout<<endl;
}

// ab hm deletion krege 

void deletenode(node*&tail ,int value)
{

    //empty list
    if(tail==NULL)
   
    {
       cout<<"list is empty"<<endl;

    }
    else{
        //non-empty
        //assuming that "value" is present in the linked list
       node*prev=tail;
       node*curr=prev->next;
       
       while(curr->data !=value)
       {
        prev=curr;
        curr=curr->next;
       }
      
       prev->next=curr->next;

    // 1 node lincked list 
       if(curr==prev)
       {
        tail=NULL;
       }

      //>=2 node lincked list
      else  if(tail==curr){
        tail=prev;
       }
       curr->next=NULL;
       delete curr;


    }
}


int main()
{

node*tail=NULL;
// yeh 0th position  matlam jan list empty hogi
insertnode(tail,0,3);
print(tail);
//ek node milne ke bad uske next 
insertnode(tail,3,5);
print(tail);
// 2 node ke just bad
insertnode(tail,5,7);
print(tail);
//3 node le just bad 
insertnode(tail,7,9);
print(tail);

//list mae 5 dhundne ke bad uske just next
insertnode(tail,5,6);
print(tail);


deletenode(tail,2);
print(tail);

}
