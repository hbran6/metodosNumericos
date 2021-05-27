/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Metodo de Posicion Falsa
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

double p0, p1, tolerancia, q0, q1, p, errorAbs, q;
int iteracionesMaximas, i, numFuncion, inicioY;
bool exito;

void ingresarDatos();
void posicionFalsa();
double f(double, int);
double errorAbsoluto(double, double);
void resultado(bool);
void mostrarIteracion();
void encabezadoTabla();
void gotoxy(int, int);

main(){
	ingresarDatos();
	system("cls");
	encabezadoTabla();
	posicionFalsa();
}

void ingresarDatos(){
	cout<<"Metodo de Posicion Falsa"<<endl<<endl;
	cout<<"1. f(x) = x^3 - 2x^2 - 5 = 0 "<<endl;//tiene al menos 10 raices
	cout<<"2. f(x) = x - cos(x) = 0 "<<endl;
	cout<<"3. f(x) = x^3 + 3x^2 - 1 = 0 "<<endl;
	cout<<"4. f(x) = x - 0.8 - 0.2 * sen(x) = 0 "<<endl;
	cout<<"Ingrese el numero de la funcion: ";
	cin>>numFuncion;
	cout<<"Ingrese el p0: ";
	cin>>p0;
	cout<<"Ingrese el p1: ";
	cin>>p1;
	cout<<"Ingrese la tolerancia: ";
	cin>>tolerancia;
	cout<<"Ingrese la cantidad maximas de iteraciones: ";
	cin>>iteracionesMaximas;
}

void encabezadoTabla(){
	gotoxy(1, inicioY);printf("p0 = [%2.2f], p1 = [%2.2f], Tolerancia = %4.15f", p0, p1, tolerancia);
 	inicioY = inicioY +2;

 	gotoxy(1, inicioY);printf("i");
 	gotoxy(8, inicioY);printf("p0");
 	gotoxy(28, inicioY);printf("p1");
 	gotoxy(48, inicioY);printf("p");
 	gotoxy(68, inicioY);printf("f(p)");
 	gotoxy(88, inicioY);printf("Error.");
 	inicioY++;
}

void posicionFalsa(){
	i = 2;
	q0 = f(p0, numFuncion);
	q1 = f(p1, numFuncion);
	
	while(i <= iteracionesMaximas && exito == false){
		p = p1 - q1 * (p1 - p0) / (q1 - q0);
		errorAbs = errorAbsoluto(p, p1);
		q = f(p, numFuncion);
		
		mostrarIteracion();
		
		if(errorAbs < tolerancia){
			exito = true;
			resultado(exito);
		}
		i = i + 1;
		if(q * q1 < 0){
			p0 = p1;
			q0 = q1;
		}
		p1 = p;
		q1 = q;
	}
	if(exito == false)
		resultado(exito);
}

double f(double x, int numFuncion){
	if(numFuncion == 1)
		return pow(x, 3) - 2 * pow(x, 2) - 5;
		
	if(numFuncion == 2)
		return x - cos(x);
		
	if(numFuncion == 3)
		return pow(x, 3) + 3 * pow(x, 2) - 1;
		
	if(numFuncion == 4)
		return x - 0.8 - 0.2 * sin(x);
}

double errorAbsoluto(double p, double p1){
	return abs((p-p1) / p);
}

void mostrarIteracion(){
	gotoxy(1, inicioY);printf("%i", i);
	gotoxy(8, inicioY);printf("%4.15f", p0);
	gotoxy(28, inicioY);printf("%4.15f", p1);
	gotoxy(48, inicioY);printf("%4.15f", p);
	gotoxy(68, inicioY);printf("%4.15f", q);
	gotoxy(88, inicioY);printf("%4.15f", errorAbs);
	
	cout<<endl;
	inicioY++;
}

void resultado(bool exito){
	if(exito){
		printf("\nEl metodo converge aprox. en la iteracion: %i, con q0=%4.15f, q1=%4.15f, p=%4.15f y f(p) = %4.15f ", i, q0, q1, p, q);
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

