#include <stdio.h>

void teste(){
    
}


int main(){
    int a;
    int *b;
    int **c;

    b = &a;
    c = &b;
    a = 5;
    printf("%d\n", a);
    printf("%d\n", **c);

}