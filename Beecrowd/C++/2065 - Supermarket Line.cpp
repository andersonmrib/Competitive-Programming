#include <bits/stdc++.h>
using namespace std;

int main(){

  priority_queue<pair<int, int>> priorQueue; //priorQueue<time, identifier>
  int n, m; //Cashiers and clients
  int vi[10010], c; //Velocity of each cashier and number of items per client
  int ans = 0;

  cin >> n >> m;

  for(int i=1; i <= n; i++) cin >> vi[i]; //Gets the velocity of each cashier

  for(int i=1; i <= n; i++) priorQueue.push({0, -i}); //'i' works as identifier

  while(m--){
    cin >> c;

    int free = -priorQueue.top().first; //How much time the cashier takes to be free again
    int id = -priorQueue.top().second; //Identifier of the cashier
    priorQueue.pop(); //Removes the cashier from the heap

    priorQueue.push({-(free + vi[id] * c), -id}); //Inserts it again with the time updated
    ans = max(ans, free + vi[id] * c); //Updates the answer for the max result
  }

  cout << ans << endl;

  return 0;
}
