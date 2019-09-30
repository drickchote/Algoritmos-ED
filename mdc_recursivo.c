#include <stdio.h>

int MDC(int x, int y){
    if(x<0) x = -x;
    if(y<0) y = -y;
    if (y==1 || x==1){
       return 1;
    }else if(x>y){
       return MDC(x-y,y);
    } else if (x<y){
        return MDC(x,y-x);
    } else{
        return x;
    }
}

int main(){
    int a, b, c;
    while(42){

        scanf("%d %d", &a,&b);
        c = MDC(a,b);
        printf("%d\n",c);
    }
    return 1;
    
}