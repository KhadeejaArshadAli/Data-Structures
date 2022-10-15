#include <iostream>
using namespace std;
//To store different types of graph on an adjacency matrix and calculating indegree and outdegree

void Graph(){
     int vertices,Option;
     int edges,row,column,k=0;


    
    cout << "Enter number of vertice = "<<endl;
    cin >> vertices;
     int Graph[vertices][vertices];
    for (int j = 0; j < vertices; j++)
    {
        for (int i = 0; i < vertices; i++)
        {
            
            Graph[i][j]=0;
        }
      
    } 

  
    cout<<"Enter the number of edges = "<<endl;
    cin>> edges;
     cout<<"Type of graph to store (Undirected=1,Directed=2,Weighted=3) :"<<endl;
        cin>>Option;
    while(k<edges){
        cout<<"Enter its starting vertice : "<<endl;
        cin>>row;
        cout<<"Enter its ending vertice: "<<endl;
        cin>>column;
        if (Option==1){
            Graph[row][column]=1;
          Graph[column][row]=1;

        }
        else if(Option==2){
            Graph[row][column]=1;

        }
        else{
            cout<<"Enter the values of your edges in the same order as defined above: "<<endl;
            int value;
            cin>> value;
            Graph[row][column]=value;
        }

         k++;
    }
    
  
    for (int j = 0; j < vertices; j++)
    {
        for (int i = 0; i < vertices; i++)
        {
            
            cout<< Graph[i][j]<<" ";
        }
        cout<<endl;
    } 

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



}



int main(){
    Graph();
    return 0;
}
