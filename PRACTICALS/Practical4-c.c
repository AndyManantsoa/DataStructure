// GCD using 

#include<stdio.h>

int GCD(int a, int b){
    if(b==0){
        return a;
    }else {
        return GCD(b,a%b);
    }
}
int main(){
    int a,b;
    printf("Enter a & b: ");
    scanf("%d %d",&a,%b);

    printf("\nThe GCD of %d and %d is %d",a,b,GCD(a,b));
}