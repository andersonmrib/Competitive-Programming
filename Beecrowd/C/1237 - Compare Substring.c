#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LongestCommonSubstring(char *string1, char *string2);

int main (){

  char str1[51], str2[51];

  while (scanf ("%50[^\n]%*c%50[^\n]%*c", str1, str2) != EOF)
     printf ("%d\n", LongestCommonSubstring(str1, str2));


  return 0;
}

int LongestCommonSubstring(char *string1, char *string2){

    int n = strlen(string1), m = strlen(string2);
    int result;
    int **mtr;

    mtr = (int**) malloc ((n + 1) * sizeof(int*));
    for (int i=0;i<=n;i++)
    {
        mtr[i] = (int*)malloc((m + 1) * sizeof(int));
        for (int j=0;j<=m; j++)
            mtr[i][j] = 0;
    }

    result = 0;
    for (int i =1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                mtr[i][j] = mtr[i - 1][j - 1] + 1;
                result = result < mtr[i][j] ? mtr[i][j] : result;
            }
        }
    }

    return result;
}
