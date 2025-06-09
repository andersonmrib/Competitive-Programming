#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

int main(){

  string line1, line2;
  int data;
  while(getline(cin, line1)){

    getline(cin, line2);
    vi vec1, vec2;

    stringstream ss1(line1);
    while(ss1 >> data) vec1.push_back(data);

    stringstream ss2(line2);
    while(ss2 >> data) vec2.push_back(data);

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    int lenA = vec1.size(), lenB = vec2.size();
    vi intersection(lenA + lenB);

    vi :: iterator endlist;
    endlist = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), intersection.begin());
    int match = endlist - intersection.begin();

    if(match == 0)
      cout << "A and B are disjoint\n";
    else{
      if(match != lenA && match != lenB)
        cout << "I'm confused!\n";
      else{
        if(lenA < lenB)
          cout << "A is a proper subset of B\n";
        else if(lenA > lenB)
          cout << "B is a proper subset of A\n";
        else
          cout << "A equals B\n";
      }
    }
  }

  return 0;
}
