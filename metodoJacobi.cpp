/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos
2021-05-28

Metodo de Jacobi
*/
#include<iostream>
#include<cmath>

using namespace std;

int n;
float jacobi(float m[], float aux[], int pos);
float obtenerError(float xAnt[], float x[], int pos);

int main(){
	cout<<"Ingrese la cantidad de variables ";
	cin>>n;
	
	float a[n][n], b[n], x[n], xAnt[n], aux[n], error[n], tolerancia;
	int iteraciones = 0, maxIteraciones;
	bool exito;
	
//	pedimos la matriz aumentada
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<"Valor en ["<<i<<", "<<j<<"] = ";
			cin>>a[i][j];
		}
	}
//	pedimos el vector del resultado
	for(int i =0; i < n; i++){
		cout<<"b["<<i<<"] = ";
		cin>>b[i];
	}
	
	cout<<"Ingrese la tolerancia: ";
	cin>>tolerancia;
	
	cout<<"Cantidad maxima de iteraciones: ";
	cin>>maxIteraciones;
//	pedimos los valores iniciales
	for(int i = 0; i < n; i++){
		cout<<"variable "<<i<<" = ";
		cin>>xAnt[i];
	}
	
	do{
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				//se agrega el valor de la posicion de la matriz aumentada a un vector para hacer el calculo en la funcion seidel
				aux[j] = a[i][j];
			}
			x[i] = (1 / a[i][i]) * (b[i] - jacobi(aux, xAnt, i));
			error[i] = obtenerError(x, xAnt, i);
//			aqui no se cambia el valor anterior, se usa el valor inicial que ingreso el usuario
		}
		
		for(int i = 0; i < n; i++){
			if(error[i] <= tolerancia){
				exito = true;
				break;
			}else{
				exito = false;
				break;
			}
		}
		cout<<endl<<"Iteracion "<<iteraciones<<endl;
		for(int i = 0; i < n; i++){
			xAnt[i] = x[i];
			cout<<"x"<<i + 1<<" = "<<x[i]<<endl;
		}
		iteraciones++;
	}while(exito == false && iteraciones < maxIteraciones);
	
	cout<<endl<<"Terminando "<<endl<< "Iteraciones: "<<iteraciones - 1<<endl;
	for(int i = 0; i < n; i++){
		cout<<"X"<<i+1<<" valor aproximado = "<<x[i]<<endl;
	}
	return 1;
}

float jacobi(float m[], float aux[], int pos){
	float temp = 0;
	for(int i = 0; i < n; i++){
		if(pos != i){
			temp = temp + m[i] * aux[i];
		}
	}
	return temp;
}
float obtenerError(float v1[], float v2[], int pos){
	float error;
	error = fabs((v1[pos] - v2[pos]) / v1[pos]);
	return error;
}
