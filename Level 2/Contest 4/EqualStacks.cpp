// https://www.hackerrank.com/contests/june-world-codesprint/challenges/equal-stacks

#include <iostream>
#include <stack>

using namespace std;

int getHeight(stack<int> *s, int i);
bool allHeightsEqual(int *heights);
void popMaxHeight(stack<int> *s, int *heights);

int main(){
    int value, *size = new int[3], *heights = new int[3];
    stack<int> *stacks = new stack<int>[3];
    
    for(int i=0; i<3; i++)
        cin>>size[i];
    
    for(int i=0; i<3; i++){
        for(int j=0; j<size[i]; j++){
            cin>>value;
            stacks[i].push(value);
        }
    }
    
    for(int i=0; i<3; i++)
        heights[i] = getHeight(stacks, i);
    
    while(!allHeightsEqual(heights)){
        popMaxHeight(stacks, heights);
    }
    cout<<heights[0]<<endl;
}

int getHeight(stack<int> *s, int i){
    stack<int> other;
    int h = 0;
    while(!s[i].empty()){
        h += s[i].top();
        other.push(s[i].top());
        s[i].pop();
    }
    s[i] = other;
    return h;
}

bool allHeightsEqual(int *heights){
    return heights[0] == heights[1] && heights[0] == heights[2];
}

void popMaxHeight(stack<int> *s, int *heights){
    int max = heights[0], maxIndex = 0;
    for(int i=1; i<3; i++){
        if(max < heights[i]){
            max = heights[i];
            maxIndex = i;
        }
    }
    heights[maxIndex] -= s[maxIndex].top();
    s[maxIndex].pop();
}