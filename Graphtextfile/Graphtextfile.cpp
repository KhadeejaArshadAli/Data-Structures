#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    int row=0;
    int column=0;
    int count,Option,value,vertices;
    cout << "Enter number of vertice = "<<endl;
    cin >> vertices;
    int Graph[vertices][vertices];
    //Initializing the Matrix with zero
    for (int j = 0; j < vertices; j++)
    {
        for (int i = 0; i < vertices; i++)
        {
            
            Graph[i][j]=0;
        }
      
    } 
  
    ifstream File;
    File.open("C:\\Users\\khadija\\OneDrive\\Documents\\University\\Data Structure\\Graph.txt");//Path of your text file
    string line;
    
    while (! File.eof() ){//while the file ends

    while (getline(File, line)){
    
        stringstream linestream(line);
        string item;
        int i;
        count=1;
      
        while (getline(linestream, item, ','))//tokenizing through ','
        { //Three types of graph Undirected, Directed and Weighted Geaph
            if(item=="UG"){
                Option=1;
            }
            if(item=="DG"){
                Option=2;
            }
            if(item=="WG"){
                Option=3;
                cout<<"Enter the value for your edges: "<<endl;
                cin>>value;
            }
            else{
        
         i=stoi(item); ///Coveting string to integer
          if(count==1){
         row=i;
         count++;
          }
          else{
            column=i;
          }
          }
        }
          if(Option==1){
          Graph[row][column]=1;
         Graph[column][row]=1;
          }
          if(Option==3){
             Graph[row][column]=value;
    

          }
        else{
              Graph[row][column]=1;

          }
    }
    }
    
    File.close();
       int Outdgree[vertices];
    int Indegree[vertices];
    for (int i = 0; i < vertices; i++)
        {
            
            Indegree[i]=0;
            Outdgree[i]=0;
        }

   
    for(int i=0;i<vertices;i++){
        for (int j=0; j<vertices;j++){
            if (Graph[i][j]!=0){
                Outdgree[i]++;
               

            }
            if (Graph[j][i]!=0){
                Indegree[i]++;
        }
    }
}
 cout<<"Outdegree: "<<endl;
for (int i = 0; i < vertices; i++)
{
    
    cout<<Outdgree[i]<<" ";
}
cout<<endl;
cout<<"Indegree: "<<endl;
for (int i = 0; i < vertices; i++)
{
   
    cout<<Indegree[i]<<" ";
}
cout<<endl;
    //Printing the matrix
    if (Option==1){
        cout<<"Undirected Graph Adajacency Matrix"<<endl;
    }
    if (Option==2){
        cout<<"Directed Graph Adajacency Matrix"<<endl;
    }
    if (Option==3){
        cout<<"Weighted Graph Adajacency Matrix"<<endl;
    }
    for (int j = 0; j < vertices; j++)
    {
        for (int i = 0; i < vertices; i++)
        {
            
            cout<< Graph[i][j]<<" ";
        }
        cout<<endl;
    } 
      
    return 0;
}

    
  
    
