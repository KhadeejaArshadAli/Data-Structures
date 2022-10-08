#include <iostream>
using namespace std;
 struct Node{
    int value;
   struct Node*next;

 };
struct Node*Head=NULL;
 
 void DynamicLinkedList(){
 
 int numberofnodes,i,Value;
 i=0;
 cout<<"Enter the number of nodes: ";
 cin>>numberofnodes;

 while(i!=numberofnodes){
    cout<<"Enter the value of nodes:  ";
 cin>>Value;
 
struct Node*temp=new Node{Value,NULL};
//Entering the new node at the front of existing code
// temp->next=Head;
//  Head=temp;
 


//Entering the new node at the end of the existisg node  
struct Node*TempHead;

if(Head==NULL){
    Head=temp;
}
else{
TempHead=Head;

while(TempHead->next!=NULL){
       TempHead= TempHead->next;
    }
    TempHead->next=temp;
}
i++;
 }
 }
 
 
 
 void PrintLinkedList( Node* node){
    while(node!=NULL){
        cout<<node->value<<endl;
        node = node->next;
    }

 }
 


 int main(){


 DynamicLinkedList();
 PrintLinkedList(Head);
 

 return 0;
 }
