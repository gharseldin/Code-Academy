// https://vjudge.net/problem/UVA-11988/origin

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

string beijuText(string input);
string convertToString(stack<vector<char>> s, queue<vector<char>> q);

int main(){
    string input;
    getline(cin, input);
    while(!input.empty()){
        cout<<beijuText(input)<<endl;
        getline(cin, input);
    }
}

string beijuText(string input){
    int addToQueue = 0;
    stack<vector<char>> st;
    queue<vector<char>> qe;
    vector<char> initialSegment;
    st.push(initialSegment);
    for(int i=0; i<int(input.size()); i++){
        if(input[i] == '['){
            vector<char> newSegment;
            st.push(newSegment);
            addToQueue=0;
        }else if(input[i] == ']'){
            vector<char> newSegment;
            qe.push(newSegment);
            addToQueue = 1;
        }else{
            if(addToQueue)
                qe.front().push_back(input[i]);
            else
                st.top().push_back(input[i]);
        }
    }
    return convertToString(st, qe);
}

string convertToString(stack<vector<char>> s, queue<vector<char>> q){
    vector<char> result, temp;
    while(!s.empty()){
        temp = s.top();
        s.pop();
        for(int i=0; i<temp.size(); i++){
            result.push_back(temp.at(i));
        }
        
    }
    
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int i=0; i<temp.size(); i++){
            result.push_back(temp.at(i));
        }
    }
    
    string res(result.begin(), result.end());
    return res;
}

