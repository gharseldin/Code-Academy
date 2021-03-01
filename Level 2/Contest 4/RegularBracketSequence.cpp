// https://codeforces.com/problemset/problem/26/B

#include <iostream>
#include <stack>

using namespace std;


int main(){
    string input;
    cin>>input;
    stack<char> s;
    int counter = 0;
    for(int i=0; i< int(input.size()); i++){
        if(input[i] == '('){
            s.push(input[i]);
        }else{
            if(!s.empty()){
                counter+=2;
                s.pop();
            }
        }
    }
    cout<<counter<<endl;
}