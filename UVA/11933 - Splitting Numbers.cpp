#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  while((cin >> n) && n){
    int a = 0, b = 0, countt = 0;
    for(int i=0; i<32; i++)
        if(n&(1<<i)){ //Checks if the i-th item is on 
           if(countt%2 == 0) a |= (1 << i); //'Set the i-th item to 1' for a
           else              b |= (1 << i); //'                      ' for b 
           countt++; //The count variable controls the order of turning on the bits
  }
           cout << a << " " << b << endl;
}
  return 0;
}
