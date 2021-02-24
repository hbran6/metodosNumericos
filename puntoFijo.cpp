/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Metodo de Punto Fijo
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

void ingreseDatos();
void ejecutarPuntoFijo();
float ejecutarFuncionF(float, int);
float ejecutarFuncionG(float, int);
float calcularError(float, float);
void resultado(bool);
void encabezadoTabla();
void mostrarIteraciones();

float puntoInicial, tolerancia, p, fp, error;
int iteracionesMaximas, i, numFuncion;
bool exito;


main(){
	ingreseDatos();
	ejecutarPuntoFijo();
}

void ingreseDatos(){
	cout<<"Ingrese el punto inicial: ";
	cin>>puntoInicial;
	cout<<"Ingrese la tolerancia: ";
	cin>>tolerancia;
	cout<<"Ingrese la cantidad maxima de iteraciones: ";
	cin>>iteracionesMaximas;
}

void ejecutarPuntoFijo(){
	i = 1;
	while(i <= iteracionesMaximas && exito == false){
		p = ejecutarFuncionG(puntoInicial, numFuncion);
		fp = ejecutarFuncionF(p, numFuncion);
		error = calcularError(p, puntoInicial);
		if(abs(error)<tolerancia){
			exito = true;
			resultado(exito);
		}
		printf("iteracion: %i\n p0: %4.15f\n g(p0): %4.15f\n f(p): %4.15f\n Error: %4.15f\n\n", i, puntoInicial, p, fp, error);
		i++;
		puntoInicial = p;
	}
}
float ejecutarFuncionF(float x1, int numFuncionX){
	return 3*pow(x1, 2)-4*x1-5;
}
float ejecutarFuncionG(float x, int numFuncionG){
	return sqrt((4*x+5)/3);
}
float calcularError(float p, float puntoInicial){
	return (p-puntoInicial) / p;
}
void resultado(bool){
}
void encabezadoTabla(){
}
void mostrarIteraciones(){
}
