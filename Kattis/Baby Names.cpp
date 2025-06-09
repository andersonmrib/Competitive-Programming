#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag,
             tree_order_statistics_node_update> ost;

int main(){

  speedBoost;
  ost male, female;

  int option;
  int gender;
  string name;
  while((cin >> option), option){

    int ans;
    if(option == 1){
      cin >> name >> gender;
      if(gender == 1) male.insert(name);
      else            female.insert(name);
    }

    else if(option == 2){
      cin >> name;
      if(male.find(name) != male.end())
        male.erase(name);
      else
        female.erase(name);
    }

    else if(option == 3){
      string starting, ending;
      cin >> starting >> ending >> gender;

      if(!gender){
        ans = male.order_of_key(ending) - male.order_of_key(starting) +
              female.order_of_key(ending) - female.order_of_key(starting);
      }

      else if(gender == 1){
        ans = male.order_of_key(ending) - male.order_of_key(starting);
      }

      else{
        ans = female.order_of_key(ending) - female.order_of_key(starting);
      }

      cout << ans << "\n";
    }

    else break;
  }

  return 0;
}
