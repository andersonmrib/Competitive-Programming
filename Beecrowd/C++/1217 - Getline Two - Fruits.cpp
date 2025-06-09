#include <bits/stdc++.h>
using namespace std;

int main(){

  int TC; cin >> TC;

  float totalValue = 0;
  int totalFruits = 0, counter = 0;

  while(TC--){
    int dailyFruits = 0; float f;
    string str, fruit;

    cin >> f; cin.ignore();
    totalValue += f;

    stringstream ss;
    getline(cin, str);
    ss << str;
    while(ss >> fruit){
      dailyFruits++;
      totalFruits++;
    }

    printf("day %d: %d kg\n", ++counter, dailyFruits);
  }
  printf("%.2f kg by day\n", (float)totalFruits/counter);
  printf("R$ %.2f by day\n", (float)totalValue/counter);

  return 0;
}
