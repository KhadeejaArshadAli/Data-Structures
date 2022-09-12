#include <iostream>
using namespace std;
struct Node {
   char data;
   struct Node*LC, *RC;
   struct Node*ETRoot=NULL;
};
Node* newNode(char data){
    Node* temp=new Node;
    temp->data = data;
    temp->LC = temp->RC = NULL;
    return temp;
}
  void InOrder(struct Node*node){
    if(node->LC!=NULL){
        InOrder(node->LC);
        

    }
    cout<<(node->data);
    if(node->RC!=NULL){
    InOrder(node->RC);
   } 
  }
  void PreOrder(struct Node*node){
   cout<<(node->data);
   if (node->LC!=NULL)
   {
      PreOrder(node->LC);
   }
   if(node->RC!=NULL){
    PreOrder(node->RC);
   } 
  }
   void PostOrder(struct Node*node){

   if (node->LC!=NULL)
   {
      PreOrder(node->LC);
   }
   if(node->RC!=NULL){
    PreOrder(node->RC);
   } 
    cout<<(node->data);

   
  }
int main(){
   struct Node* root= newNode('+');
   root->LC=newNode('a');
   root->RC=newNode('b');
  
  cout<<"The inorder of the given expression is:";
  InOrder(root);
  cout<<"\n";

  cout<<"The Preorder of the given expression is:";
  PreOrder(root);
   cout<<"\n";
  cout<<"The Postorder of the given expression is:";
   PostOrder(root);
  

   return 0;


};