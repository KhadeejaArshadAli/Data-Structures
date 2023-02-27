#include <iostream>
using namespace std;
    bool isPrime( int size){
        if(size<=1){
            return false;
        }
        if(size<=3){
            return true;
        }
        if(size%2==0||size%3==0){
            return false;
        }
        for(int i=5;i*i<=size;i=i+6){
            if(size%i==0||size%(i+2)==0){
                return false;
            }
        }
        return true;
    }
class ClosedHashing
{

    int size,Option;
    int *array;
    
public:
    ClosedHashing(int s)
    {
        this->size = s;

        array = new int[s];
        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
        }
    };


    int hashindex(int key)
    {

        return key % size;
    }

    void insert(int value)
    {

        int ht = hashindex(value);

        if (array[ht] == -1)          //  no collision
        {
            array[ht] = value;
        }
  //      collusion happened
        else{
            cout<<"Collision Alert"<<endl;
            cout<<"Resolve the collision through Linear or Quadractic Probing(Enter 1 for Linear and 2 for Quadratic)"<<endl;
            cin>>Option;

            while (array[ht]!=-1){//if index is not empty
            if(Option==1){
            
                
                ht=(ht+1)%size;//Linear Probing
            }
            else{
                ht=(ht+1)^2%size;
            }
                   
            }
             array[ht]=value;
                ht++; 
            
        }
    }

    void display()
    {
        cout << "_____HashTable_____" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << "HashTable[" << i << "] =>" << array[i] << endl;
        }
    }
  
    int Rehasing(){
        size=size*2;
        if(size<=1)
        return 2;
        int prime=size;
        bool found=false;
        while(!found){
            prime++;
            if(isPrime(prime)){
                found=true;
            }
        }
        return prime;


    }
    int Search(int x){
        for(int i=0;i<size;i++){
            if(x==array[i]){
                return i;

            }
              return -1;
            
        }

    }
};

int main()
{   int Number,value,Size,LoadFactor,x,result;
    cout<<"Enter the size of the HashTable (Prime Number):";
    cin>>Size;
    ClosedHashing HashTable(Size);
    cout<<"Enter the number of elements to want to store in your Hash Table: ";
    cin>>Number;

    for(int i=0;i<Number;i++){
        cout<<"Enter the values of the elements:";
        cin>>value;
         HashTable.insert(value);

    }
    cout<<"Enter the number to be searched: "<<endl;
    cin>>x;
    result=HashTable.Search(x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    cout<<endl;
    HashTable.display();
    LoadFactor=Number/Size;
    if(LoadFactor<=0.5){
      cout<<"No Rehasing required";
    
    }
    else{
      cout<<"Rehasing Required with size:";
       cout<<HashTable.Rehasing();
    }


    return 0;
}
