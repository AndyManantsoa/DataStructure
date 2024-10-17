//Tower of hanoi using recursion

#include<stdio.h>
#include<string.h>


void towerOfHanoi(int n,char Src, char Aux, char Dest){
    if(n==0){
        printf("cannot be 0\n");
        return;
    }
    if(n==1){
        printf("Disk 1 moved from %c to %c",Src,DeS)
        return;
    }

    towerOfHanoi(n-1,Src,Dest,Aux);
    printf("Disk %d moved from %c to %c",n,Src,Dest);
    towerOfHanoi(n-1,Aux,Source,Dest);

}

int main(){
    int n;
    printf("Enter the number of disk: ");
    scanf("%d",%n);
    
    towerOfHanoi(n,'A','B','C');
    
    return 0;
}