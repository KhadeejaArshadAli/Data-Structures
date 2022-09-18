#include <iostream>
using namespace std;
//Calculating Row Major of Two dimensional array through the slot formula
void RowMajor(){
    int Dimension=2;
    int SizeofData=4;
  
           
    int Row, Column;
    int k=0;
    cout << "Enter number of rows = "<<endl;
    cin >> Row;
    cout << "Enter number of columns = "<<endl;
    cin >> Column;
    int Data[Row][Column];
     int TotalElement=Row*Column;
    for (int j = 0; j < Column; j++)
    {
        for (int i = 0; i < Row; i++)
        {
            cout<<"Enter the " <<TotalElement<< " elements: "<<endl;
            cin >> Data[i][j];
        }
    }
    for (int j = 0; j < Column; j++)
    {
        for (int i = 0; i < Row; i++)
        {
            cout << "Array[" << i << "][" << j << "] =" <<
           Data[i][j] << endl;
        }
        
    }
    cout<<"Total Memory located "<<TotalElement*SizeofData<<endl;

   //Slot formula works for every dimension so we don't have derive a formula for every dimensional just increase the number of indexes and you are good to go  
 int *BaseAddress=&Data[0][0];
  int AddressData[Row][Column];
    int I[TotalElement];
  int S[TotalElement];
  
    int Sum=0;
      for(int i=0;i<Row;i++)
      
        {
          for(int j=0;i<Column;i++)
              Sum= Sum+ Data[i][j];
      }
          
      
      int Product=1;
        for(int i=0;i<Row;i++)
        {
          for(int j=0;i<Column;i++)

          
          Product=Product*Data[i][j];
          
        }
      int  Slot=0;
        for (int i = 0; i <TotalElement; i++)
        {
          Product=1;
          for(int s=i+1;s<=TotalElement;s++){
          Product=Product*S[s];
        
      }
        Slot=Slot+I[i]*Product;
        }
    while(k<TotalElement){
      for(int i=0;i<Row;i++)
        {
          for(int j=0;j<Column;j++){

         cout<<"Address of Data at through slot formula: "<< Data[i][j]<< " ";		
        AddressData[i][j]=*BaseAddress+Slot*SizeofData;
          cout<<AddressData[i][j]<<endl;
          Slot++;
          k++;
        }
        }
    }
//Here I have compare the result of both the formula and you can see the slot formula gives the exact same result as derived one
       cout<<"\n"; 
      for(int i=0;i<Row;i++){
    for(int j=0;j<Column;j++){
   cout<<"Address of Data at  through normal derived formula: "<< Data[i][j]<< " ";			
   AddressData[i][j]=*BaseAddress+(i*Column+j)*SizeofData;
   cout<<AddressData[i][j]<<endl;

    }
      }
}



  
int main(){
    RowMajor();
    											
	
	
    return 0;
} 
   
   
     






