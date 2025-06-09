#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){

  int T, D, I, B;
  cin >> T;
  while(T--){
    cin >> D >> I >> B;
    int ingredientsIndex[I];
    int costs[B];

    for(int i=0; i<I; i++)
        cin >> ingredientsIndex[i];

    for(int j=0; j<B; j++){
        int pairs;
        cin >> pairs;
        int cost = 0;
        for(int k=0; k<pairs; k++){
            int index, quantity;
            cin >> index >> quantity;
            cost += (ingredientsIndex[index] * quantity);
        }
        costs[j] = cost;
    }

    sort(costs, costs + B);

    cout << D/costs[0] << endl;
  }


  return 0;
}
