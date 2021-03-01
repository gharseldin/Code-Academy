// https://www.spoj.com/problems/STPAR/en/

//#include <bits/stdc++.h>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int count, *trucks, order=1;
    cin>>count;
    while(count != 0){
        stack<int> sideRoad;
        trucks = new int[count];
        for(int i=0; i<count; i++)
            cin>>trucks[i];
        
        for(int i=0; i<count;i++){
            if(trucks[i] == order)
                order++;
            else{
                if(!sideRoad.empty() && sideRoad.top() == order){
                    order++;
                    i--;
                    sideRoad.pop();
                }else{
                    sideRoad.push(trucks[i]);
                }
            }
        }
        
        while(!sideRoad.empty() && sideRoad.top() == order){
            order++;
            sideRoad.pop();
        }
        
        cout<<(sideRoad.empty()?"yes":"no")<<endl;
        cin>>count;
        order = 1;
    }
}
