#include <bits/stdc++.h>
using namespace std;

// Function to check if the character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to check if the character is a number
bool isOperand(char ch) {
    return isdigit(ch);
}

// Function to get the precedence of the operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}

// Function to perform arithmetic operations
double performOperation(double operand1, double operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else {
                cout << "Error: Division by zero is undefined." << endl;
                exit(0);
            }
        case '^':
            return pow(operand1, operand2);
        default:
            return 0;
    }
}

// Function to evaluate the expression
double evaluateExpression(string expression) {
    stack<double> operands;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;

        if (isOperand(expression[i])) {
            string operandStr;
            while (i < expression.length() && (isOperand(expression[i]) || expression[i] == '.'))
                operandStr += expression[i++];
            i--;

            double operand = stod(operandStr);
            operands.push(operand);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                double result = performOperation(operand1, operand2, op);
                operands.push(result);
            }

            operators.pop(); // Discard the opening bracket
        } else if (isOperator(expression[i])) {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(expression[i])) {
                double operand2 = operands.top();
                operands.pop();

                double operand1 = operands.top();
                operands.pop();

                char op = operators.top();
                operators.pop();

                double result = performOperation(operand1, operand2, op);
                operands.push(result);
            }

            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        double operand2 = operands.top();
        operands.pop();

        double operand1 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();

        double result = performOperation(operand1, operand2, op);
        operands.push(result);
    }

    return operands.top();
}


int main()
{
    printf("SCIENTIFIC CALCULATOR BY HYPERTEXT ASSASSINS\n\n");
    float a, b, c, d, n, i, j, r, l, nf, nrf, rf, nCr, rnr, m, p, nPr;
    float tn, ret, val, PI, x, y, ans, ex, ln, tnlg, fn, fact, k;
    int dn, re, g, bi = 0, bn, rem, deci, w, on, odn, hn;
    float bsq, fac, root, sqrtt, ult, toa, absq, afac, aroot, asqrtt, ault, atoa;
    char name1[30], name[30], sign;

    printf("type 'start' to start your calculator\n\n ");
    printf("START YOUR CALCULATOR = ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline character


    if (strcmp(name, "start") == 0) {
        printf("\ntype 'calculation' for the calculation part\n"
               "type 'sin' for sin function\n"
               "type 'arcsin' for inverse sin function\n"
               "type 'tan' for tan function\n"
               "type 'arctan' for inverse tan function\n"
               "type 'cos' for cos function\n"
               "type 'arccos' for inverse cos function\n"
               "type 'xsin' to get xsin(n)\n"
               "type 'xtan' to get xtan(n)\n"
               "type 'xcos' to get xcos(n)\n"
               "type 'xarcsin' to get x inverse sin(n) function\n"
               "type 'xarctan' to get x inverse tan(n) function\n"
               "type 'xarccos' to get x inverse cos(n) function\n"
               "type 'power' to get power function\n"
               "type 'root' to get square root function\n"
               "type 'exp' for exponential function\n"
               "type 'ln' for ln function\n"
               "type 'tenlog' for log function\n"
               "type 'fact' for factorial function\n"
               "type 'nCr' to get combination function\n"
               "type 'nPr' to get permutation function\n"
               "type 'binary' to convert decimal to binary number\n"
               "type 'decimal' to convert binary to decimal number\n"
               "type 'oct' to convert decimal to octal number\n"
               "type 'otod' to convert octal to decimal number\n"
               "type 'dtoh' to convert decimal to hexa-decimal number\n"
               "type 'htod' to convert hexa-decimal number to decimal number\n"
               "type 'bino' for binomial equation\n"
               "type 'exit' to exit\n\n   ");
        system("PAUSE");
        system("cls");
        printf("Which Function? = ");
        while (1) {


            fgets(name1, sizeof(name1), stdin);
            name1[strcspn(name1, "\n")] = '\0';

            if (strcmp(name1, "calculation") == 0)
                     {
                string expression;
                cout << "Enter an expression: ";
                getline(cin, expression);

                double result = evaluateExpression(expression);
                cout<<result<<endl;

                     }
            else if(strcmp(name1,"sin")==0)
                    {
                    printf("enter a number ");
                    scanf("%f",&tn);
                    getchar();
                    PI=3.14159265359;
                   val = PI / 180.0;
                   ret = sin(tn*val);
                   printf("sin(%f)= %f",tn,ret);
                    }


            else if (strcmp(name1, "cos") == 0) {
                printf("Enter a number: ");
                scanf("%f", &tn);
                getchar(); // Consume the newline character
                PI = 3.14159265359;
                val = PI / 180.0;
                ret = cos(tn * val);
                printf("cos(%f) = %f\n", tn, ret);
            }

            else if (strcmp(name1, "arcsin") == 0) {
            printf("Enter a number: ");
            scanf("%f", &tn);
            getchar();
            PI = 3.14159265359;
            val = 180 / PI;
            ret = asin(tn) * val;
            printf("arcsin(%f) = %f", tn, ret);

    }

            else if (strcmp(name1, "tan") == 0) {
                printf("Enter a number: ");
                scanf("%f", &tn);
                getchar();
                PI = 3.14159265359;
                val = PI / 180.0;
                ret = tan(tn * val);
                printf("tan(%f) = %f", tn, ret);

    }

             else if (strcmp(name1, "arctan") == 0) {
                printf("Enter a number: ");
                scanf("%f", &tn);
                getchar();
                PI = 3.14159265359;
                val = 180 / PI;
                ret = atan(tn) * val;
                printf("arctan(%f) = %f", tn, ret);
        }

            else if (strcmp(name1, "cos") == 0) {
                printf("Enter a number: ");
                scanf("%f", &tn);
                getchar();
                PI = 3.14159265359;
                val = PI / 180.0;
                ret = cos(tn * val);
                printf("cos(%f) = %f", tn, ret);
    }

            else if (strcmp(name1, "arccos") == 0) {
                printf("Enter a number: ");
                scanf("%f", &tn);
                getchar();
                PI = 3.14159265359;
                val = 180 / PI;
                ret = acos(tn) * val;
                printf("arccos(%f) = %f", tn, ret);
            }

            else if (strcmp(name1, "power") == 0) {
                printf("Enter base and exponent: ");
                scanf("%f %f", &x, &y);
                getchar();
                ans = pow(x, y);
                printf("Result: %f", ans);
            }

            else if (strcmp(name1, "root") == 0) {
                printf("Enter a number: ");
                scanf("%f", &x);
                getchar();
                ans = sqrt(x);
                printf("Square root: %f", ans);
            }

             else if (strcmp(name1, "ln") == 0) {
                printf("Enter a number: ");
                scanf("%f", &x);
                getchar();
                ln = log(x);
                printf("ln(%f) = %f", x, ln);
            }

            else if (strcmp(name1, "binary") == 0) {
                printf("Enter decimal number: ");
                scanf("%d", &dn);
                getchar();
                g = 1;
                while (dn != 0) {
                    re = dn % 2;
                    dn = dn / 2;
                    bi = bi + (re * g);
                    g = g * 10;
                }
                printf("Binary: %d", bi);
    }

            else if (strcmp(name1, "decimal") == 0) {
                printf("Enter binary number: ");
                scanf("%d", &bn);
                getchar();
                deci = 0;
                w = 1;
                while (bn != 0) {
                    rem = bn % 10;
                    deci = deci + rem * w;
                    bn = bn / 10;
                    w = w * 2;
                }
                printf("Decimal: %d", deci);
    }

            else if (strcmp(name1, "factorial") == 0) {
                printf("Enter a number: ");
                scanf("%f", &fn);
                getchar();
                fact = 1;
                for (int k = 1; k <= fn; k++) {
                    fact *= k;
                }
                printf("%f! = %f", fn, fact);
            }


            else if (strcmp(name1, "exit") == 0){
               break;
            }


            else {
        printf("Invalid operation.");
    }


            cout<<endl;
            printf("Which Function? = ");

        }
    } else {
        exit(1);
    }

    return 0;
}

