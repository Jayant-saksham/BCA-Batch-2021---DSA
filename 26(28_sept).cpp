#include<iostream>
#include<stack>
using namespace std;
int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*') {
        return 1;
    }
    return 0;
}
int solver(int f, int s, char op) {
    if(op == '+') {
        return s+f;
    }
    else if(op == '-') {
        return s - f;
    }
    else if(op == '*') {
        return s*f;
    }
    else if(op == '/') {
        return s/f;
    }
    return 0;
}
int postFixSolver(char exp[]) {
    stack<int> s;
    for(int i=0;exp[i]!='\0';i++) {
        if(isOperator(exp[i])) {
            int fi = s.top();
            s.pop();
            int se = s.top();
            s.pop();
            int ans = solver(fi, se, exp[i]);
            s.push(ans);
        }
        else {
            int data = exp[i] -'0';
            s.push(data);
        }
    }
    return s.top();
}
int main() {
    char exp[] = "33+";
    char c = '2';
    printf("%d ", postFixSolver(exp));
    return 0;
}