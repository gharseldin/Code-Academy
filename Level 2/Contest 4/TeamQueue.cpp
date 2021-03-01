// https://onlinejudge.org/external/5/540.pdf

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void handleTeamQueueing(int teams, int counter);
void enqueueNumber(int number, queue<int> *queues, int **teamMembers, int teams, queue<int> &order);
int dequeNumber(queue<int> *queues, queue<int> &order);
int findTeamOfNumber(int number, int **teamMembers, int teams);

int main()
{
    int teams, counter = 1;
    cin >> teams;
    while (teams != 0)
    {
        handleTeamQueueing(teams, counter++);
        cin >> teams;
    }
}

void handleTeamQueueing(int teams, int counter)
{
    cout << "Scenario #" << counter << endl;
    queue<int> *queues;
    queue<int> order;
    queues = new queue<int>[teams];
    int **teamMembers;
    teamMembers = new int *[teams];
    for (int i = 0; i < teams; i++)
    {
        teamMembers[i] = new int[1000000];
        for (int j = 0; j < 1000000; j++)
            teamMembers[i][j] = 0;
        int members;
        cin >> members;
        for (int j = 0; j < members; j++)
        {
            int member;
            cin >> member;
            teamMembers[i][member] = 1;
        }
    }
    string command;
    int number;
    cin >> command;
    while (command != "STOP")
    {
        if (command == "ENQUEUE")
        {
            cin >> number;
            enqueueNumber(number, queues, teamMembers, teams, order);
        }
        else
        {
            cout << dequeNumber(queues, order) << endl;
        }
        cin >> command;
    }
    cout << endl;
}

void enqueueNumber(int number, queue<int> *queues, int **teamMembers, int teams, queue<int> &order)
{
    int team = findTeamOfNumber(number, teamMembers, teams);
    if (queues[team].empty())
        order.push(team);
    queues[team].push(number);
}

int dequeNumber(queue<int> *queues, queue<int> &order)
{
    int next = order.front();
    int val = queues[next].front();
    queues[next].pop();
    if (queues[next].empty())
        order.pop();
    return val;
}

int findTeamOfNumber(int number, int **teamMembers, int teams)
{
    for (int i = 0; i < teams; i++)
        if (teamMembers[i][number] == 1)
            return i;
    return -1; //Not found and not a condition we will come across
}
