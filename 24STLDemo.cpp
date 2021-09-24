#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(char exp[]) {
    stack<char> s;
    for(int i=0;exp[i]!='\0';i++) {
        if(exp[i] == '(') {
            s.push(exp[i]);
        }
        else if(exp[i] == ')') {
            if(s.empty()) {
                return false;
            }
            else if(s.top() == '(') {
                s.pop();
            }
        }
    }
    if(s.empty()) {
        return true;
    }
    return false;
}
void NGR(int A[], int n) {
    stack<int> ans;
    stack<int> s;
    for(int i=(n-1);i>=0;i--) {
        if(s.empty()) {
            ans.push(-1);
        }
        else {
            if(s.top()>=A[i]) {
                ans.push(s.top());
            }
            else {
                while(s.top()<=A[i]) {
                    s.pop();
                }
                if(s.empty()) {
                    ans.push(-1);
                }
                else  {
                    ans.push(s.top());
                }
            }
        }
        s.push(A[i]);
    }
    while(!ans.empty()) {
        int x = ans.top();
        printf("%d ", x);
        ans.pop();
    }
}
int main() {
        
    return 0;
} 


