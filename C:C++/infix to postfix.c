#include <stack>
using namesapce std;

int precedence(char c);

char result[100];

char *infixToPostfix(char *str) {
    
    int i = 0;
    stack<char> post;
    
    while (*str) {
        if (*str == '(')
            post.push('(');
        else if (isdigit(*str)) {
            result[i++] = *str;
            result[i++] = ' ';
        }
        else if (*str == ')') {
            while (!post.empty() && post.top() != '(') {
                result[i++] = post.top();
                result[i++] = ' ';
                post.pop();
            }
            if (!post.empty() && post.top() == '(')
                post.pop();
        }
        else {    // handling posts
            while (!post.empty() && precedence(*str)<=precedence(post.top())) {
                result[i++] = post.top();
                result[i++] = ' ';
                post.pop();
            }
            post.push(*str);
        }
        
        str++;
        
    }
    
    while (!post.empty()) {
        result[i++] = post.top();
        result[i++] = ' ';
        post.pop();
    }
    
    result[i] = '\0';
    
    return result;
    
}

int precedence(char c) {
    
    if (c=='+' || c=='-')
        return 1;
    else if (c=='*' || c=='/')
        return 3;
    else if (c=='(' || c==')')
        return 0;
}

double calculate(char *str) {
    double num;
    double curr, prev;
    stack<double> s;
    
    while (*str) {
        while (*str==' ')
           str++;            
        
        if (isdigit(*str))
            s.push(*str-'0');
        else {
            curr = s.top();
            s.pop();
            prev = s.top();
            s.pop();
            if (*str=='+') {
                num = prev+curr;
            }
            else if (*str=='-') {
                num = prev-curr;
                s.push(num);
            }
            else if (*str=='*') {
                num = prev*curr;
                s.push(num);
            }
            else if (*str=='/') {
                num = prev/curr;
                s.push(num);
            }
        }
        str++;
    }
    
    num = s.top();    
}