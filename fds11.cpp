/*
        Implement C++ program for expression conversion as infix to
    postfix and its evaluation using stack based on given conditions:
        1. Operands and operator, both must be single character.
        2. Input Postfix expression must be in a desired format.
        Only '+' , '-' , '*', '/' operators are expected
*/

#include<iostream>
using namespace std;

class Stack
{
    public:
        //member functions
        char *arr;
        int size;
        int top;

        Stack(int n)
        {
            size = n;
            arr = new char[size];
            top = -1;
        }

        void push(char data)
        {
            //check full
            if(top == size-1)
            {
                cout << "Stack Overflow" << endl;
                return;
            }
            else
            {
                arr[++top] = data;
            }
        }

        void pop()
        {
            //check empty
            if(top == -1)
            {
                cout << "Stack Underflow" << endl;
            }
            else
            {
                top--;
            }
        }

        char topp()
        {
            //check empty
            if(top == -1)
            {
                cout << "Stack Underflow" << endl;
            }
            else 
                return arr[top];
        }

        bool isempty()
        {
            if(top == -1) return true;
            else return false;
        }
};

int pref(char ch)
{
    if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
}

void infix_postfix(string infix)
{
    Stack st(infix.length());
    string postfix = "";
    for(int i = 0 ; i < infix.length() ; i++)
    {
        char ch = infix[i];
        //if '(' push into stack
        if(ch == '('){
            st.push(ch);
        }
        //if operand is traversed print it
        else if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z'))
            postfix += ch; 
        //if ')' is traversed
        else if(ch == ')'){
            while(ch != '('){
                postfix += st.topp();
                st.pop();
            }
            //to remove opening bracket
            st.pop();
        }
        //if operator is traversed
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(st.isempty()){
                st.push(ch);
            }
            else{
                while(!st.isempty() && pref(ch) <= pref(st.topp())){
                    postfix += st.topp();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while(!st.isempty()){
        postfix += st.topp();
        st.pop();
    }
    cout << "Postfix : " << postfix;
}

int main(){
    string temp = "a+b*c/z";
    infix_postfix(temp);
    
    return 0;
}