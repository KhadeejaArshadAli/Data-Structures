#include <iostream>
using namespace std;
class stackarraypointer{
     public:
    int stack[8];
    int top=-1;
    int PUSH(int data){
        if(top<8-1){
            top++;
            stack[top]=data;
            return 0;

        }
        else 
        return -1;

    }
    int POP(int *ret){
        if(top!=-1){
            *ret=stack[top];
            top--;
            return 0;

        }
        else 
        return -1;
         
    }
    void DISPLAYSTACK(){
        if (top==-1)
        {
            cout<<"UNDERFLOW!!"<<endl;
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
    stackarraypointer s;
    s.PUSH(1);
    int r=1;
    s.POP(&r);
    s.DISPLAYSTACK();
    return 0;
}