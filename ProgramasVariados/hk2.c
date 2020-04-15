  
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 20

int main() {

    int n, q, i, j, total;
    char s[100];
    
    scanf("%d", &n);
    char m[n];
    printf("%d", n);
    for(i = 0; i < n; i++){
        gets(s);
        printf("%s", s);
        m[i] = s;
    }
    
    scanf("%d", &q);
    
    for(i = 0;i < q; i++){
        scanf("%s", s);
        total = 0;
        for(j = 0; j < n; j++)
            if(strcmp(s, m[j]) == 0)
                total++;
        printf("%d", total);
    }
    
    return 0;
}