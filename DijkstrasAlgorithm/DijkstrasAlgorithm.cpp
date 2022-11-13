#include<iostream>
using namespace std;
#define INF 9999999
#define V 6
//KEEP THE SOURCE VERTEX 0
int main(){
     int Graph[V][V]={
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
 
    int v,w;
bool Known[V];
int Distance[V];
int Previous[V];
int source,Destination,i,k;
 //Initializing the array by false and inf
 for (int i=0;i<V;i++){
    Known[i]=false;
    Distance[i]=INF;
     }
cout<<"Enter the source vertex: "<<endl;
cin>>source;
Distance[source]=0;
Previous[source]=-1; //we initialize this from -1 to indicate none of vertex was previous this hence the source


        for(int i=0;i<V;i++){
            if(Distance[i]<=INF&&Known[i]==false){
                v=i;
                Known[v]=true;
        for(int i=0;i<V;i++){
        if(Graph[v][i]!=0){//correspond vertices of selected vertex
            w=i;
            if(!Known[w]&&Distance[v]+Graph[v][w]<Distance[w]&&Graph[v][w] && Distance[v] != INF){//know==false and distance of vertex+weight <distance of corresponding vertex
                
          
                Distance[w]=Distance[v]+Graph[v][w];// switch 
                 Previous[w]=v;
               
                
            }
            
        }
     
    }
            }

               
            }

    cout<<"Vertex\t\tDistance from source vertex\t Previous visited Vertex"<<endl;
    for(int k = 0; k<V; k++)                      
    { 
        
        cout<<k<<"\t\t\t"<<Distance[k]<<"\t\t\t\t"<<Previous[k]<<endl;
    }
    // The following code segment will give the shortest path for your desired dstination
    cout<<"Enter your destination: "<<endl;
    cin>>Destination;
    cout<<"The total cost to reach "<<Destination<<" is "<< Distance[Destination]<<endl;
    
		if(Destination!=source)
		{
			cout<<"Shortest Path to reach "<< Destination;
			k=Destination;
			do
			{
				k=Previous[k];
				cout<<"<---"<<k;
			}
			while(k!=source);
		}
        else
        cout<<"Already there"<<endl;


   
   return 0;


 

}



    


        
        

