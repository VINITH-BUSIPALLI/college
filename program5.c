#include<stdio.h> 
#include<math.h> 
#include<ctype.h> 

int main() 
{ 
	char postfix[50]; 
	int choice;
	float res; 
	do{
		printf("Enter postfix expression\n"); 
		scanf("%s",postfix); 
		res=eval(postfix); 
		printf("Result=%f\n",res); 
		printf("Do you want to enter another expression:(1/0):");
		scanf("%d",&choice);
	}while(choice!=0);
}
 


/*evaluate()*/ 
float eval(char postfix[]) 
{ 
		float op1,op2,res; 
		char ch; 
		int i=0; 
		while((ch=postfix[i])!='\0') 
		{ 
			if(isdigit(ch)) 
				push(ch-'0'); 
			else 
			{ 
				op2=pop(); 
				op1=pop(); 
				value = oper(ch, op1,op2);
				push(value);
			}
			i++;
		}
			return(pop()); 
	} 
	

	float oper(char symb, float op1, float op2)
	{
		switch(symb)	
		{ 
			case '$': 
			case '^': return(pow(op1,op2)); 
			case '*': return(op1*op2); 
			case '/': return(op1/op2); 
			case '+': return(op1+op2); 
			case '-': return(op1-op2);  
		} 
	} 
		 

float stack[50]; 
int top=-1; 

/*push()*/
void push(float x) 
{ 
		stack[++top]=x; 
} 

/*pop()*/ 
float pop() 
{ 
		return(stack[top--]); 
} 
