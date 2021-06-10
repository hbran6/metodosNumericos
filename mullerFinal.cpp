/*
Autor: Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Fecha: 09/06/2021
Descripcion: Metodo de Muller
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

double x0, x1, x2, tolerancia, h1, h2, S1, S2, d, b, D, E, h, p, DTest;
int iteracionesMaximas, i, numFuncion, inicioY;
bool exito;

void ingresarDatos();
void muller();
double f(double, int);
double errorAbsoluto(double, double);
void resultado(bool, bool);
void mostrarIteracion();
void encabezadoTabla();
void gotoxy(int, int);

main(){
	ingresarDatos();
	system("cls");
	encabezadoTabla();
	muller();
}

void ingresarDatos(){
	cout<<"Metodo de Muller"<<endl<<endl;
	cout<<"1. f(x) = (9/11)x^3 - (11/2)x + 2 "<<endl;//tiene al menos 10 raices
	cout<<"Ingrese el numero de la funcion: ";
	cin>>numFuncion;
	cout<<"Ingrese el x0: ";
	cin>>x0;
	cout<<"Ingrese el x1: ";
	cin>>x1;
	cout<<"Ingrese el x2: ";
	cin>>x2;
	cout<<"Ingrese la tolerancia: ";
	cin>>tolerancia;
	cout<<"Ingrese la cantidad maximas de iteraciones: ";
	cin>>iteracionesMaximas;
}

void encabezadoTabla(){
	gotoxy(1, inicioY);printf("x0 = [%2.2f], x1 = [%2.2f], x2 = [%2.2f] Tolerancia = %4.15f", x0, x1, x2, tolerancia);
 	inicioY = inicioY +2;

 	gotoxy(1, inicioY);printf("i");
 	gotoxy(8, inicioY);printf("p");
 	gotoxy(28, inicioY);printf("f(p)");
 	gotoxy(48, inicioY);printf("Error Abs");
 	inicioY++;
}

void muller(){
	h1 = x1 - x0;
	h2 = x2 - x1;
	S1 = (f(x1, numFuncion) - f(x0, numFuncion)) / h1;
	S2 = (f(x2, numFuncion) - f(x1, numFuncion)) / h2;
	d = (S2 - S1) / (h2 + h1);
	i = 3;
	
	while(i <= iteracionesMaximas && exito == false){
		b = S2 + h2 * d;
		DTest = pow(b, 2) - 4 * f(x2, numFuncion) * d;

		if(DTest < 0){
			exito = true;
			resultado(exito, true);
		}else{
			D = pow(DTest, 0.5);
			if(abs(b - D) < abs(b + D))
				E = b + D;
			else
				E = b - D;
			
			h = -2 * f(x2, numFuncion) / E;
			p = x2 + h;
			
			mostrarIteracion();
			
			if(abs(h) < tolerancia){
				exito = true;
				resultado(exito, false);
			}
						
			x0 = x1;
			x1 = x2;
			x2 = p;
			
			h1 = x1 - x0;
			h2 = x2 - x1;
			S1 = (f(x1, numFuncion) - f(x0, numFuncion)) / h1;
			S2 = (f(x2, numFuncion) - f(x1, numFuncion)) / h2;
			d = (S2 - S1) / (h2 + h1);
			i++;
		}
	}
	if(exito == false)
		resultado(exito, false);
}

double f(double x, int numFuncion){
	if(numFuncion == 1)
		return 0.81* pow(x, 3) - 5.5 * x + 2;
}

double errorAbsoluto(double x0, double x1){
	return abs((x1-x0) / x1);
}

void mostrarIteracion(){
	gotoxy(1, inicioY);printf("%i", i);
	gotoxy(8, inicioY);printf("%4.15f", p);
	gotoxy(28, inicioY);printf("%4.15f", f(p, numFuncion));
	gotoxy(48, inicioY);printf("%4.15f", errorAbsoluto(x0, x1));
	cout<<endl;
	inicioY++;
}

void resultado(bool exito, bool negativo){
	if(exito){
		if(negativo)
			printf("\nEl metodo fracaso porque la funcion tiene raices imaginarias.");
		else
			printf("\nEl metodo converge aprox. en la iteracion: %i, con p=%4.15f y f(p) = %4.15f ", i, p, f(p, numFuncion));
	}else{
		printf("\nEl metodo no converge en las iteraciones solicitadas (%i)", iteracionesMaximas);
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

