#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, op1, x;
  int s, q, pq;
  stack<int>st4ck;
  queue<int>qu3ue;
  priority_queue<int>priorqueue;

  while(cin >> n){

    while(!st4ck.empty())      st4ck.pop();
    while(!qu3ue.empty())      qu3ue.pop();
    while(!priorqueue.empty()) priorqueue.pop();

    s = 1, q = 1, pq = 1;
    for(int i=0; i<n; i++)
    {
        cin >> op1 >> x;

        if(op1 == 1)
        {
            if(s)  st4ck.push(x);
            if(q)  qu3ue.push(x);
            if(pq) priorqueue.push(x);
        }
        else
        {
            if(s)
            {
                if(st4ck.empty() || st4ck.top() != x)
                    s = 0;
                else st4ck.pop();
            }
            if(q)
            {
                if(qu3ue.empty() || qu3ue.front() != x)
                    q = 0;
                else qu3ue.pop();
            }
            if(pq)
            {
                if(priorqueue.empty() || priorqueue.top() != x)
                    pq = 0;
                else priorqueue.pop();
            }
        }
    }
        if(s && !q && !pq)       cout << "stack\n";
        else if(!s && q && !pq)  cout << "queue\n";
        else if(!s && !q && pq)  cout << "priority queue\n";
        else if(!s && !q && !pq) cout << "impossible\n";
        else                     cout << "not sure\n";
  }

  return 0;
}
