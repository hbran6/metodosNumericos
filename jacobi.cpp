/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Metodo de Jacobi
*/
#include<iostream>
#define n 10

using namespace std;

void jacobi(int l, float x[], float a[][10], float b[]);

int main(){
	int i, j, l;
	float x[n], a[n][n], b[n], suma;
	
	cout<<"Ingrese la cantidad de ecuaciones: ";
	cin>>l;
	
	cout<<"Ingrese la matriz aumentada"<<endl;
	for(i = 0; i < l; i++){
		x[i] = 0;
		for(j = 0; j < l; j++){
			cout<<"a["<<i<<","<<j<<"]= ";
			cin>>a[i][j];
		}
	}
	cout<<"ingrese el vector de los resultados: "<<endl;
	for(i = 0; i < l; i++){
		cout<<"b["<<i<<", 0] = ";
		cin>>b[i];
	}
	
	jacobi(l, x, a, b);
}

void jacobi(int l, float x[], float a[][10], float b[]){
	float c[n];
	int k, i, j;
	for(k = 0; k < 10; k++){
		for(i = 0; i < l; i++){
			c[i] = b[i];
			for(j = 0; j < l; j++){
				if(i != j)
					c[i] = c[i] - a[i][j] * x[j];
			}
		}
		for(i = 0; i < n; i++){
			x[i] = c[i] / a[i][i];
		}
	}
	cout<<"La solucion de la ecuacion es:"<<endl;
	for(i = 0; i < l; i++)
		printf("x%i = %4.15f\n", i, x[i]);
//		cout<<"x("<<i<<") = "<<x[i]<<endl;
}






