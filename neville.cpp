/*
Autor: Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Fecha: 09/06/2021
Descripcion: Metodo de Neville
*/
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <windows.h>

using namespace std;

int n;
double x[100], y[100], xint, Q[100][100];

main(){
	int j, i;
	cout<<"Ingrese cantidad de datos: ";
	cin>>n;
	
	for(i = 0; i < n; i++){
		cout<<"Ingrese x: ";
		cin>>x[i];
		cout<<"Ingrese y: ";
		cin>>y[i];
	}
	cout<<"Valor a interpolar: ";
	cin>>xint;
	
	for(i = 0; i<n;i++){
		Q[i][0] = y[i];
	}
	
	for(i=1;i<n;i++){
		for(j=1;j<=i;j++){
			Q[i][j] = ( (xint - x[i-j])*Q[i][j-1] - (xint-x[i])*Q[i-1][j-1] ) / (x[i] - x[i-j]);
		}
	}
	printf("Interpolacion en el punto xint=%4.15f", Q[n-1][n-1]);
	printf("\n\n\n");
	printf("MATRIZ\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%4.15f ", Q[i][j]);
		}
		printf("\n");
	}
}

