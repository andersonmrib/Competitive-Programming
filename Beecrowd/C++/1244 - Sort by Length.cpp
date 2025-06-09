#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool cmp(string a, string b) { return a.length() > b.length(); }

void insertionSort(vector<string> &v){

  int n = v.size();
  for(int i=1; i<n; i++){
    int j = i-1;
    string x = v[i];
    while(j>=0 && cmp(x, v[j])){
        v[j+1] = v[j];
        j--;
    }
    v[j+1] = x;
  }
}

int main(){

  int n; cin >> n;
  cin.ignore();
  while(n--){
    string text, word;
    vector<string> vec;

    getline(cin, text);

    stringstream ss(text);

    while(ss >> word)
      vec.push_back(word);

    insertionSort(vec);

    cout << vec[0];
    for(int i=1; i<vec.size(); i++)
        cout << ' ' << vec[i];
    cout << endl;
  }

  return 0;
}
