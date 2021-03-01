/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Metodo de Newton-Raphson
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

int numFuncion, inicioY = 1, iteracionesMaximas, i;
float puntoInicial, p, tolerancia, errorAbs;
bool exito;

void ingresarDatos();
void newtonRaphson();
float FX(float, int);
float primeraDerivadaFX(float, int);
void resultado(bool);
void mostrarIteracion();
void encabezadoTabla();
float calcularErrorAbs(float, float);
void gotoxy(int, int);

main(){
	ingresarDatos();
	system("cls");
	encabezadoTabla();
	newtonRaphson();
}

void ingresarDatos(){
	cout<<"Metodo de Newton-Raphson"<<endl<<endl;
	cout<<"1.f(x) = x^4 - 3x^2 - 3 "<<endl;//tiene raiz en el intervalo [1, 2]
	cout<<"Ingrese el numero de la funcion:";
	cin>>numFuncion;
	cout<<"Ingrese el punto inicial: ";
	cin>>puntoInicial;
	cout<<"Ingrese la tolerancia: ";
	cin>>tolerancia;
	cout<<"Ingrese la cantidad maximas de iteraciones: ";
	cin>>iteracionesMaximas;
}

void encabezadoTabla(){
	gotoxy(1, inicioY);printf("Punto inicial = [%2.2f] Tolerancia = %4.15f", puntoInicial, tolerancia);
 	inicioY = inicioY +2;
 	gotoxy(1, inicioY);printf("Iteracion");
 	gotoxy(15, inicioY);printf("p0");
 	gotoxy(35, inicioY);printf("f(p0)");
 	gotoxy(55, inicioY);printf("p");
 	gotoxy(75, inicioY);printf("f(p)");
 	gotoxy(95, inicioY);printf("Error Abs.");
 	inicioY++;
}

void newtonRaphson(){
	i = 1;
	exito = false;
	while(i <= iteracionesMaximas && exito == false){
		p = puntoInicial - (FX(puntoInicial, numFuncion) / primeraDerivadaFX(puntoInicial, numFuncion));
		errorAbs = calcularErrorAbs(p, puntoInicial);
		mostrarIteracion();
		if(errorAbs < tolerancia){
			exito = true;
			resultado(exito);
		}
		i++;
		puntoInicial = p;
	}
	if(exito == false)
		resultado(exito);
}

float FX(float x, int numFuncion){
	if(numFuncion == 1)
		return pow(x, 4) - 3 * pow(x, 2) - 3;
}

float primeraDerivadaFX(float x, int numFuncion){
	if(numFuncion == 1)
		return 4 * pow(x, 3) - 6 * x;
}

float calcularErrorAbs(float p, float puntoInicial){
	return abs((p-puntoInicial) / p);
}

void mostrarIteracion(){
	gotoxy(1, inicioY);printf("%i", i);
	gotoxy(15, inicioY);printf("%4.15f", puntoInicial);
	gotoxy(35, inicioY);printf("%4.15f", FX(puntoInicial, numFuncion));
	gotoxy(55, inicioY);printf("%4.15f", p);
	gotoxy(75, inicioY);printf("%4.15f", FX(p, numFuncion));
	gotoxy(95, inicioY);printf("%4.15f", errorAbs);
	inicioY++;
}

void resultado(bool exito){
	if(exito){
		printf("\n\nEl metodo converge en la iteracion: %i, con p=%4.15f y f(p) = %4.15f", i, p, FX(p, numFuncion));
	}else{
		printf("\n\nEl metodo no converge en las iteraciones solicitadas (%i)", iteracionesMaximas);
	}
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
