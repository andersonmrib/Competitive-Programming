#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef tuple<string, int, int, int> tup;
bool comp(tup &a, tup &b){

  auto [nameA, dayA, monthA, yearA] = a;
  auto [nameB, dayB, monthB, yearB] = b;
  if(yearA != yearB) return yearB < yearA;
  if(monthA != monthB) return monthB < monthA;
  if(dayA != dayB) return dayB < dayA;
  return false;
}

int main(){

  speedBoost;
  int n; cin >> n; cin.ignore();

  vector<tup> people;
  for(int i=0; i<n; i++){
    string name;
    int day, month, year;
    cin >> name >> day >> month >> year;
    people.push_back({name, day, month, year});
  }

  sort(people.begin(), people.end(), comp);

  auto [na, da, ma, ya] = people[0];
  cout << na << "\n";
  auto [nb, db, mb, yb] = people[n-1];
  cout << nb << "\n";

  return 0;
}
