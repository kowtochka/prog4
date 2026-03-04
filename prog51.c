#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(int argc, char const *argv[]){
    srand(time(0));
    printf("Введите количество элементов A\n");
    int m;
    scanf("%d",&m);
    int k;
    start:
    printf("Введите k (меньше чем %d) \n",m);
    scanf("%d",&k);
    if(k>=m){
        printf("k должно быть МЕНЬШЕ %d\n",m);
        goto start;
    }
    double d=(double)m/(double)k;
    int* A=malloc(sizeof(int)*m);
    int** B=malloc(sizeof(int*)* ceil(d));
    for(int i=0;i<ceil(d);i++){
        B[i]=calloc(k,sizeof(int));
    }
    for(int i =0;i<m;i++){            
        A[i]=rand()%51-25;
    }
    printf("\n");
    for(int i =0;i<m;i++){            
        printf("%5d",A[i]);
    }
    int a=0;         
    for(int i=0;i<ceil(d);i++){
        printf("\n");
        for(int j=0;j<k;j++){
            B[i][j]=A[a];
            a++;
        }
    }
    printf("\n");
    printf("%d",ceil(d));
    for(int i=0;i<ceil(d);i++){
        printf("\n");
        for(int j=0;j<k;j++){
            printf("%3d ",B[i][j]);
        }
    }
    printf("\n");    
    return 0;
}

