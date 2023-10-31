// /*Write a program to convert Infix to postfix expression / notation.*/

// #include <iostream>
// #include <string>
// using namespace std;

// class Stack
// {
//     char data[100];
//     int top;

// public:
//     Stack()
//     {
//         top = -1;
//     }

//     void push(char c)
//     {
//         data[++top] = c;
//     }

//     char pop()
//     {
//         if (!isEmpty())
//         {
//             return data[top--];
//         }
//         return '\0';
//     }

//     char peek()
//     {
//         if (!isEmpty())
//         {
//             return data[top];
//         }
//         return '\0';
//     }

//     bool isEmpty()
//     {
//         return top == -1;
//     }
// };

// class InfixToPostfix
// {
//     string infix;
//     string postfix;

//     int getPrecedence(char c)
//     {
//         if (c == '^')
//             return 3;
//         else if (c == '*' || c == '/')
//             return 2;
//         else if (c == '+' || c == '-')
//             return 1;
//         else
//             return 0;
//     }

// public:
//     void readInfix()
//     {
//         cout << "Enter an infix expression: ";
//         getline(cin, infix);

//         check();
//     }

//     void displayInfix()
//     {
//         cout << "Infix expression: " << infix << endl;
//     }

//     string convert()
//     {
//         Stack operatorStack;

//         for (int i = 0; i < infix.length(); i++)
//         {
//             char c = infix[i];

//             if (isalnum(c))
//             {
//                 string operand;
//                 while (isalnum(infix[i]))
//                 {
//                     operand += infix[i];
//                     i++;
//                 }
//                 i--;
//                 postfix += operand + ' ';
//             }
//             else if (c == '(')
//             {
//                 operatorStack.push(c);
//             }
//             else if (c == ')')
//             {
//                 while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
//                 {
//                     postfix += operatorStack.pop();
//                     postfix += ' ';
//                 }
//                 if (!operatorStack.isEmpty() && operatorStack.peek() == '(')
//                 {
//                     operatorStack.pop();
//                 }
//             }
//             else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
//             {
//                 while (!operatorStack.isEmpty() && getPrecedence(c) <= getPrecedence(operatorStack.peek()))
//                 {
//                     postfix += operatorStack.pop();
//                     postfix += ' ';
//                 }
//                 operatorStack.push(c);
//             }
//         }

//         while (!operatorStack.isEmpty())
//         {
//             postfix += operatorStack.pop();
//             postfix += ' ';
//         }

//         return postfix;
//     }

//     bool isOperator(char c)
//     {
//         return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
//     }

//     void check()
//     {

//         int operand = 0, operatorr = 0;

//         for (char c : infix)
//         {
//             if (isdigit(c))
//             {
//                 operand++;
//             }
//             else if (isOperator(c))
//             {
//                 operatorr++;
//             }
//         }

//         if (operatorr != operand - 1 || isOperator(infix[infix.length() - 1]))
//         {
//             cout << endl
//                  << endl
//                  << "Invalid expression!..Re-Enter..!" << endl
//                  << endl;
//             readInfix();
//         }
//     }
// };

// int main()
// {
//     InfixToPostfix converter;
//     converter.readInfix();
//     converter.displayInfix();
//     string postfixExpression = converter.convert();

//     cout << "Postfix expression: " << postfixExpression << endl;

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char data[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) { data[++top] = c; }

    char pop()
    {
        if (!isEmpty())
        {
            return data[top--];
        }
        return '\0';
    }

    char peek()
    {
        if (!isEmpty())
        {
            return data[top];
        }
        return '\0';
    }

    bool isEmpty() { return top == -1; }
};

class InfixToPostfix
{
    string infix, postfix;

    int getPrecedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return 0;
    }

    bool isOperand(char c)
    {
        return (isalpha(c) || isdigit(c));
    }

    bool isOperator(char c)
    {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    bool isOpenPar(char c)
    {
        return (c == '(');
    }

    bool isClosedPar(char c)
    {
        return (c == ')');
    }

    void validate()
    {
        int opCount = 0, opndCount = 0, parCount = 0;
        bool prevCharOperator = true; // Initially set to true to handle cases like '-5'.

        for (char c : infix)
        {
            if (isOperand(c))
            {
                opndCount++;
                prevCharOperator = false;
            }
            else if (isOperator(c))
            {
                opCount++;
                if (prevCharOperator && (c != '-' && c != '+'))
                {
                    cout << "Invalid consecutive operators" << endl;
                    return;
                }
                prevCharOperator = true;
            }
            else if (isOpenPar(c))
            {
                parCount++;
                prevCharOperator = true;
            }
            else if (isClosedPar(c))
            {
                parCount--;
                prevCharOperator = false;
            }
        }

        if (parCount != 0)
        {
            cout << "Unbalanced parentheses" << endl;
            return;
        }

        if (opCount != opndCount - 1)
        {
            cout << "Invalid operator/operand counts" << endl;
            return;
        }

        if (!isOperand(infix[0]) || !isOperand(infix[infix.length() - 1]))
        {
            cout << "Invalid start/end characters" << endl;
            return;
        }

        if (infix.length() == 0)
        {
            cout << "Empty expression" << endl;
            return;
        }

        cout << "Valid expression" << endl;
    }

public:
    void readInfix()
    {
        cout << "Enter infix expression: ";
        getline(cin, infix);
        validate();
    }

    string convertToPostfix()
    {
        Stack operatorStack;

        for (int i = 0; i < infix.length(); i++)
        {
            char c = infix[i];

            if (isalnum(c))
            {
                string operand;
                while (isalnum(infix[i]))
                {
                    operand += infix[i];
                    i++;
                }
                i--;
                postfix += operand + ' ';
            }
            else if (c == '(')
            {
                operatorStack.push(c);
            }
            else if (c == ')')
            {
                while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
                {
                    postfix += operatorStack.pop();
                    postfix += ' ';
                }
                if (!operatorStack.isEmpty() && operatorStack.peek() == '(')
                {
                    operatorStack.pop();
                }
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            {
                while (!operatorStack.isEmpty() && getPrecedence(c) <= getPrecedence(operatorStack.peek()))
                {
                    postfix += operatorStack.pop();
                    postfix += ' ';
                }
                operatorStack.push(c);
            }
        }

        while (!operatorStack.isEmpty())
        {
            postfix += operatorStack.pop();
            postfix += ' ';
        }

        return postfix;
    }
};

int main()
{
    InfixToPostfix i;
    i.readInfix();
    string postfix = i.convertToPostfix();
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
