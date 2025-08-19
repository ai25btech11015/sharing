#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "./libs/matfun.h"

int main(void){
    double **A = createMat(2,1);
    double **B = createMat(2,1);
    double **C = createMat(2,1);
    double **E = createMat(2,1);
    double **F = createMat(2,1);

    A[0][0] = 4; A[1][0] = 2;
    B[0][0] = 6; B[1][0] = 5;
    C[0][0] = 1; C[1][0] = 4;
    E[0][0] = 2.5; E[1][0] = 3;
    F[0][0] = 5; F[1][0] = 3.5;

    FILE *file;
    int len = 10;
    file = fopen("./lines.dat", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    for (int i = 0; i <= 10; i++) {
       
        printMat(Matscale(A,2,1,i/10.0),2,1);

       
        fprintf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf \n",
            Matadd(A, Matscale(Matsub(B, A, 2, 1), 2, 1, i/10.0), 2, 1)[0][0],
            Matadd(A, Matscale(Matsub(B, A, 2, 1), 2, 1, i/10.0), 2, 1)[1][0],
            Matadd(B, Matscale(Matsub(C, B, 2, 1), 2, 1, i/10.0), 2, 1)[0][0],
            Matadd(B, Matscale(Matsub(C, B, 2, 1), 2, 1, i/10.0), 2, 1)[1][0],
            Matadd(A, Matscale(Matsub(C, A, 2, 1), 2, 1, i/10.0), 2, 1)[0][0],
            Matadd(A, Matscale(Matsub(C, A, 2, 1), 2, 1, i/10.0), 2, 1)[1][0],
            Matadd(B, Matscale(Matsub(E, B, 2, 1), 2, 1, i/10.0), 2, 1)[0][0],
            Matadd(B, Matscale(Matsub(E, B, 2, 1), 2, 1, i/10.0), 2, 1)[1][0],
            Matadd(C, Matscale(Matsub(F, C, 2, 1), 2, 1, i/10.0), 2, 1)[0][0],
            Matadd(C, Matscale(Matsub(F, C, 2, 1), 2, 1, i/10.0), 2, 1)[1][0]);
    }


   
    free(A);
    free(B);
    free(C);
    free(E);
    free(F);
    free(file);

    return 0;
}

