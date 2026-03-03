#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
    int n =5;
    printf("Введите количество строк матрицы\n");
    int m;
    scanf("%d",&m);
    int** B=malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        B[i] = (int *)malloc(n * sizeof(int));
    }
    int** C=malloc((m-1) * sizeof(int *));
    for (int i = 0; i < m-1; i++) {
        C[i] = (int *)malloc((n-1) * sizeof(int));
    }
    srand(time(0));
    int I=0;
    int J=0;
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            B[i][j]=rand()%51-25;
            if(B[I][J]<B[i][j]){
                I=i;
                J=j;
            }
        }
    }
    printf("\n");
    printf("Исходная матрица B:\n");
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf("%3d ",B[i][j]);
        }
    }
    for(int i=0;i<m-1;i++){ 
        if(i<I){
            for(int j=0;j<n-1;j++){
                if(j<J){
                    C[i][j]=B[i][j];
                }else C[i][j]=B[i][j+1];
            }
        }else{
            for(int j=0;j<n-1;j++){
                if(j<J){
                    C[i][j]=B[i+1][j];
                }else C[i][j]=B[i+1][j+1];            
        }
    }
}
printf("\n");
printf("\nМаксимальное число:%d",B[I][J]);
printf("\nСтрока:%d",I+1);
printf("\nСтолбец:%d",J+1);
    printf("\n");
    printf("\nМатрица C:\n");
    for(int i=0;i<m-1;i++){
        printf("\n");
        for(int j=0;j<n-1;j++){
            printf("%3d ",C[i][j]);
        }
    }
    printf("\n");
    
    return 0;
}
