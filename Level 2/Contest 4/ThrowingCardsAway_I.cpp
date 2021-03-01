// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876

#include <iostream>
#include <queue>

using namespace std;

void printOutPut(queue<int> q);

int main(){
    int n;
    cin>>n;
    while(n!=0){
        queue<int> q;
        for(int i=1; i<=n; i++)
            q.push(i);
        printOutPut(q);
        cin>>n;
    }
}

void printOutPut(queue<int> q){
    cout<<"Discarded cards:";
    while(q.size()!=1){
        cout<<" "<<q.front()<<(q.size()==2?"":",");
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
    cout<<"Remaining card: "<<q.front()<<"\n";
}