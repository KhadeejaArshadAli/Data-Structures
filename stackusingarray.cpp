#include <iostream>
using namespace std;
#define MAX 8
class stackusingarray{
    public:
    int stack[MAX];
    int top=-1;
    int PUSH(int data){
        if(top!=MAX-1){
            top++;
            stack[top]=data;
            
        }
        else{
            cout<<"OVERFLOW!!"<<endl;
        }
    }
    int POP(){
        if (top==-1)
        {
            cout<<"STACK IS EMPTY"<<endl;
        }
        else
        top--;
        
    }
    void DISPLAYSTACK(){
        if (top==-1)
        {
            cout<<"STACK IS EMPTY"<<endl;
        }
        else
        {
            for (int i = 0; i <=top; i++)
            {
                cout<<stack[i]<<" ";
                cout<<"\n";
            }
            
        }
        
    }
};
int main(){
    stackusingarray s;
    s.PUSH(1);
    s.PUSH(2);
    s.PUSH(3);
    s.POP();
    s.DISPLAYSTACK();
    return 0;
    

}