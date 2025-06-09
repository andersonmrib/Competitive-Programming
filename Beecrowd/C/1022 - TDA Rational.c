#include <stdio.h>

  struct fraction{
    int num; //Numerator
    int den; //Denominator
  };
  typedef struct fraction Fraction;

  Fraction sum(Fraction f1, Fraction f2){
    Fraction result;

    result.num = f1.num * f2.den + f2.num * f1.den;
    result.den = f1.den * f2.den;

    return result;
  }

  Fraction sub(Fraction f1, Fraction f2){
    Fraction result;

    result.num = f1.num * f2.den - f2.num * f1.den;
    result.den = f1.den * f2.den;

    return result;
  }

  Fraction mult(Fraction f1, Fraction f2){
    Fraction result;

    result.num = f1.num * f2.num;
    result.den = f1.den * f2.den;

    return result;
  }

  Fraction div(Fraction f1, Fraction f2){
    Fraction result;

    result.num = f1.num * f2.den;
    result.den = f2.num * f1.den;

    return result;
  }

  int GCD(int a, int b) { return b == 0 ? a : GCD(b, a%b); }

  Fraction simplifyFraction (Fraction f){
    int gcd = (f.num < 0) ? GCD(-f.num, f.den) : GCD(f.num, f.den);

    f.num /= gcd;
    f.den /= gcd;

    return f;
  }

int main(){

  int n; scanf("%d", &n);
  char operation;
  Fraction f1, f2, result;

  while(n--){
    scanf("%d / %d %c %d / %d", &f1.num, &f1.den, &operation, &f2.num, &f2.den);

    switch (operation)
    {
        case '+':
             result = sum(f1, f2);
             break;
        case '-':
             result = sub(f1, f2);
             break;
        case '*':
             result = mult(f1, f2);
             break;
        case '/':
             result = div(f1, f2);
             break;
    }

    printf("%d/%d = ", result.num, result.den);
    result = simplifyFraction(result);
    printf("%d/%d\n", result.num, result.den);
  }

  return 0;
}
