//Tower of hanoi using recursion

#include<stdio.h>
#include<string.h>


void towerOfHanoi(int n,char A, char B, char C){
    if(n==0){
        printf("cannot be 0\n");
        return;
    }
    if(n==1){
        printf("Disk 1 moved from %c to %c",A,B)
        return;
    }
    towerOfHanoi(n-1,A,C,B);
    printf("Disk %d moved from %c to %c",n,A,B);
    towerOfHanoi(n-1,C,A,B);
    printf("Disk %d moved from %c to %c",n,C,B);

}

int main(){
    int n;
    printf("Enter the number of disk: ");
    scanf("%d",%n);


    towerOfHanoi(n,'A','B','C');

    return 0;
}