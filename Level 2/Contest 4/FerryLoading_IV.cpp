// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1975

#include <iostream>
#include <queue>

using namespace std;

int getTrips(int inputLines, int ferryLength);

int main(){
    int testCases, inputLines, ferryLength;
    cin>>testCases;
    for(int i=0; i<testCases; i++){
        cin>>ferryLength>>inputLines;
        cout<<getTrips(inputLines, ferryLength)<<endl;
    }
}

int getTrips(int inputLines, int ferryLength){
    queue<int> left, right;
    int vehicleLength, leftPosition = 1, trips = 0, ferryInCm = ferryLength*100;
    string position;
    
    for(int i=0; i<inputLines; i++){
        cin>>vehicleLength>>position;
        if(position == "left"){
            left.push(vehicleLength);
        }else{
            right.push(vehicleLength);
        }
    }
    
    while(!(left.empty() && right.empty())){
        int loaded = 0;
        if(leftPosition){
            while(!left.empty() && loaded+left.front()<=ferryInCm){
                loaded+=left.front();
                left.pop();
            }
            leftPosition = 0;
        }else{
            while(!right.empty() && loaded+right.front() <= ferryInCm){
                loaded += right.front();
                right.pop();
            }
            leftPosition = 1;
        }
        trips++;
        loaded = 0;
    }
    return trips;
}
