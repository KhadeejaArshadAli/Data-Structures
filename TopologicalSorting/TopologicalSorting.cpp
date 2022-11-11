#include <iostream>
#include <cstring>
using namespace std;
//For checking this code
//vertices=6
//edges=6
//Starting vertice= 5,Ending vertice=0
//Starting vertice= 5,Ending vertice=2
//Starting vertice= 4,Ending vertice=1
//Starting vertice= 4,Ending vertice=0
//Starting vertice= 3,Ending vertice=1
//Starting vertice= 2,Ending vertice=3

// Output=4,5,0,2,3,1

int main(){
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
    while(k<edges){
        cout<<"Enter its starting vertice : "<<endl;
        cin>>row;
        cout<<"Enter its ending vertice: "<<endl;
        cin>>column;
            Graph[row][column]=1;

        

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
    int Indegree[vertices];
    for (int i = 0; i < vertices; i++)
        {
            
            Indegree[i]=0;
            
        }

   
    for(int i=0;i<vertices;i++){
        for (int j=0; j<vertices;j++){
            if (Graph[j][i]!=0){
                Indegree[i]++;
        }
    }
}

cout<<"Before Sorting Indegree: "<<endl;
for (int i = 0; i < vertices; i++)
{
   
    cout<<Indegree[i]<<" ";
}
cout<<endl;
//Initializing the array by false
bool selected[vertices];
 for (int i=0;i<vertices;i++){
    selected[i]=false;
      
   
    }
unsigned int counter;
int topnum[vertices];
int v,w;
  cout<<"Topological Sorting od the given directed graph"<<endl;
 for(counter=0;counter<vertices;counter++){
  for (int i=0;i<vertices;i++){
    if(Indegree[i]==0&&selected[i]==false){//Indegree should be zero
        v=i;
        cout<<v<<" ";
        selected[v]=true;// Once the vertice is selected change its state to true
        for(int i=0;i<vertices;i++){
        if(Graph[v][i]==1){
            w=i;
            Indegree[w]--;// Pop the indegree by 1 of those vertices associated with the selected one 
        }
    }
        

   
    }
   
  }
    if(v==-1){
        cout<<"Graph is Cyclic"<<endl;// If none of the vertices indegree is zero then the graph is cyclic
    
        
    }

 topnum[v]=counter;



   
  } 
 //After processing all the indegree must be equal to zero
 cout<<endl;
cout<<"After Sorting Indegree: "<<endl;
for (int i = 0; i < vertices; i++)
{
   
    cout<<Indegree[i]<<" ";
}
cout<<endl;
}


