#include <stdio.h>
#define MAX 510

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    char str[MAX][MAX]; //str[x][y] where x = max number of string and y = maximum length of strings

    for(int i=0; i<n; i++) scanf("%s", str[i]);

    for(int i=0; i<n; i++){
        if(i > 0){ //Drop coming from the top
           for(int j=0; j<m; j++){
            if(str[i][j] == '.' && str[i-1][j] == 'o')
                str[i][j] = 'o';
           }
        }
        if(i < n-1){ //Drop moving to the left
           for(int j=m-2; j>=0; j--){
            if(str[i][j] == '.' && str[i][j+1] == 'o' && str[i+1][j+1] == '#')
                str[i][j] = 'o';
           }
           for(int j=1; j<m; j++){ //Drop moving to the right
            if(str[i][j] == '.' && str[i][j-1] == 'o' && str[i+1][j-1] == '#')
                str[i][j] = 'o';
           }
        }
    }

    for(int i=0; i<n; i++)
        printf("%s\n", str[i]);

    return 0;
}
