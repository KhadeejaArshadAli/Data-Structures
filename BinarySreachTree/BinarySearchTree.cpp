#include <iostream>
using namespace std;
struct BinarySearchTree{
    int data;
    struct BinarySearchTree*LC, *RC;
   
};
BinarySearchTree* NewNode(int data){
    BinarySearchTree* temp=new BinarySearchTree;
    temp->data = data;
    temp->LC = temp->RC = NULL;
    return temp;
}
BinarySearchTree*Insert(BinarySearchTree*Root,int data){
    if(Root==NULL){
        Root=NewNode(data);
    }
    else if(data<=Root->data){
        Root->LC=Insert(Root->LC,data);
    }
    else{
        Root->RC=Insert(Root->RC,data);
    }
    return Root;
}
bool Search(BinarySearchTree*Root,int data){
    if(Root==NULL){
        return false;
       
    
    }
    else if (Root->data==data){

        return true;
        
    }
    else if(data<=Root->data){
       return Search(Root->LC,data);
    }
    else {
       return Search(Root->RC,data);
    }

}



int main(){
     struct BinarySearchTree*Root=NULL;
     int Number,i,data;
     i=0;
     cout<<"How many element you want to insert? ";
     cin>>Number;
     while(i<Number){
        cout<<"Enter the element you want to insert: ";
        cin>>data;
        Root=Insert(Root,data);
        i++;
     }
    int Element;
    cout<<"Enter the element you want to search: ";
    cin>>Element;
    Search(Root,Element);
    if(Search(Root,Element)==true){
        cout<<"Element Found"<<endl;
    }
    else{
        cout<<"Element Not Found"<<endl;
    }
    return 0;
}
