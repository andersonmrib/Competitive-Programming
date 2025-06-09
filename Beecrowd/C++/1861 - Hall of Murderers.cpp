#include <bits/stdc++.h>
using namespace std;

int main(){

    map<string, int> killer;
    map<string, int> dead;

    map<string, int> :: iterator it;

    string s1, s2;

   while (cin >> s1 >> s2)
    {
        ++killer[s1];
        ++dead[s2];
    }
    cout << "HALL OF MURDERERS\n";
    for (it = killer.begin(); it != killer.end(); ++it){
        int aux = dead[it->first];

        if (!aux){
          cout << it->first << ' ' << it->second << '\n';
        }
    }
    killer.clear();
    dead.clear();
}