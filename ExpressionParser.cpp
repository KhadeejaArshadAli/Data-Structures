//INFIX TO POSTFIX AND ITS EVALUATION

#include <iostream>
using namespace std;
#include <cstring>
#define SIZE 20
int stack[SIZE];
int top = -1; 
void push(int item)
{

    if (top >= SIZE - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}


int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}
int IsOperator(char c){
    if(c=='^') {
        return 3;
        }
    if (c=='*'||c=='/') {
        return 2;
    }
    if (c=='+'||c=='-') {
        return 1;
    }
    if (c=='('|| c==')')
    {
        return 4;
    }
    
return 0;
};
int EvaluatePostfix(){
    
    char x[SIZE];
    int a, b;
    cout<<"Enter the converted postfix expression with your desired values:\n"; //34+(enter like this)
    cin>>x;
    for (int i = 0; i < strlen(x); i++)
    {
        if (x[i] >= '0' && x[i] <= '9')
            push(x[i]-'0');
        else if (IsOperator!=0)
        {
            a=pop();
            b=pop();
            switch(x[i])
            {
            case '+':
                push(a+b);
                break;
            case '-':
                push(a-b);
                break;
            case '*':
                push(a*b);
                break;
            case '/':      
                push(a/b);
                break;
            }
        }
    }
    cout<<"Evaluated Postfix Expression is:"<<pop()<<endl;
};



int infixtopostfix(char* infix){
char postfix[20]=" ";
char stack [20];
int top=-1;
int j=0;



for(int i=0;i<strlen(infix);i++){
    if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix[j++]=infix[i];
		}
   
    else if(infix[i]=='('){
        stack[++top]=infix[i];
        
        
    }
    else if (infix[i]==')')
    {
        while (stack[top]!='('&&top!=-1)
        {
            char temp=stack[top];

            postfix[j++]=temp;
            top--;
            
    
        }
        if(stack[top]=='('){
          top--;  
        
        }
    }
    else if(IsOperator(infix[i])==0){
    stack[++top]=infix[i];
    
    
    }
    
    else{    
    while(top!=-1&&IsOperator(infix[i]<=IsOperator(stack[top]))){
    postfix[j++]=stack[top--];

 }
    stack[++top]=infix[i];
    

}
}

while(top!=-1){
postfix[j++]=stack[top--];


}

postfix[j++]='\0';
printf("%s",postfix  );
cout<< "\n"<<endl;
cout<<"Do you want to evaluate the postfix expression(Yes==1,No==0)?"<<endl;
int response;
cin>>response;
if(response==1){
  EvaluatePostfix();
}
else{
    return 0;


}




};




int main(){

   
char infix [20];
cout<<"Enter the infix expression:"<<endl;
cin>>infix;
cout<<"The postfix expression is: "<<endl; 
infixtopostfix(infix);


return 0;
};
