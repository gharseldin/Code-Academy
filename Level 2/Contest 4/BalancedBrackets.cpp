// https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <iostream>
#include <stack>

using namespace std;

bool checkBalance(string testCase);
bool matching(char open, char close);

int main(){
    int problems;
    string testCase;
    cin>>problems;
    for(int i=0; i<problems; i++){
        cin>>testCase;
        cout<<(checkBalance(testCase)?"YES\n":"NO\n");
    }
}

bool checkBalance(string testCase){
    stack<char> s;
    for(int i=0; i<int(testCase.size()); i++){
        char closing = testCase[i];
        if( closing == '(' || closing == '[' || closing == '{'){
            s.push(closing);
        }else{
            if(s.empty()){
                return false;
            }else{
                char possibleMatch = s.top();
                if(matching(possibleMatch, closing))
                    s.pop();
                else
                    return false;
            }
        }
    }
    return s.empty();
}

bool matching(char open, char close){
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}
