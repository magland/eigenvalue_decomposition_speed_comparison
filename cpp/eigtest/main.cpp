#include <QCoreApplication>
#include <QDebug>
#include <QTime>
#include <math.h>

#include "lapacke.h"
bool eigenvalue_decomposition_sym(int M,double *U, double *S,double *X)
{
    //X=U*diag(S)*U'
    //X is MxM, U is MxM, S is 1xM
    //X must be real and symmetric

    for (int ii=0; ii<M*M; ii++) {
        U[ii]=X[ii];
    }

    //'V' means compute eigenvalues and eigenvectors (use 'N' for eigenvalues only)
    //'U' means upper triangle of A is stored.
    //QTime timer; timer.start();
    int info=LAPACKE_dsyev(LAPACK_COL_MAJOR,'V','U',M,U,M,S);
    //printf("Time for call to LAPACKE_dsyev: %g sec\n",timer.elapsed()*1.0/1000);
    if (info!=0) {
        printf("Error in LAPACKE_dsyev: %d\n",info);
        return false;
    }
    return true;
}


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    int M=1000;
    double *X=(double *)malloc(sizeof(double)*M*M);
    double *U=(double *)malloc(sizeof(double)*M*M);
    double *S=(double *)malloc(sizeof(double)*M);
    for (int j=0; j<M; j++) {
        for (int i=0; i<M; i++) {
            X[i+M*j]=sin(sin(i)+sin(j)+sin(i+j));
        }
    }

    QTime timer; timer.start();
    eigenvalue_decomposition_sym(M,U,S,X);
    printf("First 10 eigenvalues:\n");
    for (int j=0; j<10; j++) {
        printf("%g ",S[j]);
    }
    printf("\n");
    printf("M=%d: Elapsed time (sec) = %g\n",M,timer.elapsed()*1.0/1000);

    //return a.exec();
}

