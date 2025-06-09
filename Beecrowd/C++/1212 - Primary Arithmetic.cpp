#include <bits/stdc++.h>
using namespace std;

int main(){

  string num1, num2;
  while((cin >> num1 >> num2), (stoi(num1) || stoi(num2))){

    int len = max(num1.size(), num2.size());

    while(num1.size() < len) num1 = '0' + num1;
    while(num2.size() < len) num2 = '0' + num2;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    int numCarry = 0;
    for(int i=0; i<len; i++){
      int sum = (num1[i] - '0' + num2[i] - '0') + carry;
      if(sum >= 10){
        carry = sum/10;
        numCarry++;
      }
      else
        carry = 0;
    }
    if(!numCarry)          printf("No carry operation.\n");
    else if(numCarry == 1) printf("%d carry operation.\n", numCarry);
    else                   printf("%d carry operations.\n", numCarry);
  }

  return 0;
}

