#include<iostream>
#include<stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;  // For '('
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (size_t i = 0; i < infix.length(); ++i) 
	{
        char ch = infix[i];
        if (isalnum(ch)) 
		{
            postfix += ch;
        } 
		else if (ch == '(') 
		{
            s.push(ch);
        } 
		else if (ch == ')') 
		{
            while (!s.empty() && s.top() != '(') 
			{
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Pop '('
        } else
		 { // Operator
            while (!s.empty() && precedence(ch) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty())
	 {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

double evaluatePostfix(const string& postfix) {
    stack<double> s;

    for (size_t i = 0; i < postfix.length(); ++i) 
	{
        char ch = postfix[i];
        if (isalnum(ch)) 
		{
            s.push(ch - '0');  // Convert character to integer
        } 
		else 
		{
            double operand2 = s.top();
            s.pop();
            double operand1 = s.top();
            s.pop();

            switch(ch) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }

    return s.top();
}

int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    double result = evaluatePostfix(postfixExpression);
    cout << "Result after evaluation: " << result << endl;

    return 0;
}

