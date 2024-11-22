//command option n for run
#include <iostream>
#define n 50
using namespace std;

class Stack{
	char arr[n];
	int top;
	public:
		Stack(){
			top = -1;
		}
		void push(int item){
			arr[++top] = item;
		}
		char pop(){
			return arr[top--];
		}
		char return_topitem(){
			return arr[top];
		}
		int return_top(){
			return top;
		}
};
int priority(char item)
{  
    switch(item)
    {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		default:  return 0;
	}
}
int main(){
	Stack obj;
	char infix[n], postfix[n];
	cout << "Enter infix: ";
	cin >> infix;
	
	int i = 0;
	int j = 0;
	while(infix[i] != '\0'){
		char ch = infix[i];
		if(ch == '(')
			obj.push(ch);
		else if(isalnum(ch))
			postfix[j++] = ch;
		else if(ch == ')'){
			while(obj.return_topitem() != '('){
				postfix[j++] = obj.pop();
			}
			obj.pop();
		}
		else{
			while( priority(ch) <= priority(obj.return_topitem()))
			{
				postfix[j++]= obj.pop();
			}
			obj.push(ch);
		}	
		i++;
	}
	while(obj.return_top() != -1){
		postfix[j++] = obj.pop();
	}
	postfix[j] = '\0';
	cout << "postfix: " << postfix << endl;
	return 0;
}
