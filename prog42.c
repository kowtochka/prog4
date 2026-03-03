#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]){
    printf("Введите количество строк матрицы\n");
    int m;
    scanf("%d",&m);
    int n;
    printf("Введите количество столбцов матрицы\n");
    scanf("%d",&n);
    printf("\n");
    int** A=malloc((m+1) * sizeof(int *));
    for (int i = 0; i < m+1; i++) {
        A[i] = (int *)malloc((n+1) * sizeof(int));
    }
    int** D=malloc((m+2) * sizeof(int *));
    for (int i = 0; i < m+2; i++) {
        D[i] = (int *)malloc((n+2) * sizeof(int));
    }
    srand(time(0));
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            A[i][j]=rand()%51-25;
        }
    }    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            D[i][n]+=A[i][j];
            D[i][j]=A[i][j];
        }
    }
     for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            D[m][j]+=A[i][j];
        }
    }
    for(int i=0;i<m;i++){ 
    D[m][n]+=D[i][n];
    }
    printf("Исходная матрица A:\n");
    for(int i=0;i<m;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            printf("%3d ",A[i][j]);
        }
    }
    printf("\n");
    printf("\nМатрица D:\n");
    for(int i=0;i<m+1;i++){
        printf("\n");
        for(int j=0;j<n+1;j++){
            printf("%3d ",D[i][j]);
        }
    }
    printf("\n");
    return 0;
}
