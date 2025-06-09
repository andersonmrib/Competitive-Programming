#include <stdio.h>
#include <math.h>
#define PI 3.1415926535897

int main(){

  int a, b, c;
  while(scanf("%d %d %d", &a, &b, &c) != EOF){
    double p = (a + b + c)/2.0;
    double triangleArea = sqrt(p*(p-a)*(p-b)*(p-c));

    double circleRadius = (a*b*c)/(4.0*triangleArea);   // !remember this mathematical formula! R = abc/A
    double circleArea = PI*circleRadius*circleRadius;

    double littleCircleRadius = triangleArea/p;         // ans this one too
    double littleCircleArea = PI*littleCircleRadius*littleCircleRadius;

    printf("%.4lf ", circleArea - triangleArea);        // sunflowers area
    printf("%.4lf ", triangleArea - littleCircleArea);  // violets area
    printf("%.4lf\n", littleCircleArea);                // roses area
  }

  return 0;
}
