/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Metodo de la secante
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
double p0, p1, q0, q1, p, tolerancia, errorAbs, FP;
bool exito;

void ingresarDatos();
void secante();
double FX(double, int);
void resultado(bool);
void mostrarIteracion();
void encabezadoTabla();
double calcularErrorAbs(double, double);
void gotoxy(int, int);

main(){
	ingresarDatos();
	system("cls");
	encabezadoTabla();
	secante();
}

void ingresarDatos(){
	cout<<"Metodo de la secante"<<endl<<endl;
	cout<<"1.f(x) = ln(x^2 + 1) - e^0.4x * cos(pi * x) "<<endl;//tiene al menos 10 raices
	cout<<"2.f(x) = 2^x - 6cos(x) = 0 "<<endl;
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
	gotoxy(1, inicioY);printf("P0 = [%4.15f], P1 = [%4.15f], Tolerancia = %4.15f", p0, p1, tolerancia);
 	inicioY = inicioY +2;

 	gotoxy(1, inicioY);printf("p0");
 	gotoxy(18, inicioY);printf("p1");
 	gotoxy(35, inicioY);printf("q0");
 	gotoxy(53, inicioY);printf("q1");
 	gotoxy(71, inicioY);printf("p");
 	gotoxy(89, inicioY);printf("f(p)");
 	gotoxy(107, inicioY);printf("Error Abs.");
 	gotoxy(119, inicioY);printf("i");
 	inicioY++;
}

void secante(){
	i = 2;
	q0 = FX(p0, numFuncion);
	q1 = FX(p1, numFuncion);
	exito = false;
	while(i <= iteracionesMaximas && exito == false){
		p = p1 - q1 * (p1 - p0) / (q1 - q0);
		errorAbs = calcularErrorAbs(p, p1);
		FP = FX(p, numFuncion);
		mostrarIteracion();
		if(errorAbs < tolerancia){
			exito = true;
			resultado(exito);
		}else{
			i++;
			p0 = p1;
			p1 = p;
			q0 = q1;
			q1 = FP;
		}
	}
	if(exito == false)
		resultado(exito);
}

double FX(double x, int numFuncion){
	if(numFuncion == 1)
		return log(pow(x, 2) +1) - exp(0.4*x) * cos(M_PI*x);
	
	if(numFuncion == 2)
		return pow(2, x) - 6 * cos(x);		
}

double calcularErrorAbs(double p, double p1){
	return abs((p-p1) / p);
}

void mostrarIteracion(){
	gotoxy(1, inicioY);printf("%4.10f", p0);
	gotoxy(16, inicioY);printf("%4.10f", p1);
	gotoxy(33, inicioY);printf("%4.10f", q0);
	gotoxy(51, inicioY);printf("%4.10f", q1);
	gotoxy(69, inicioY);printf("%4.10f", p);
	gotoxy(87, inicioY);printf("%4.10f", FP);
	gotoxy(105, inicioY);printf("%4.10f", errorAbs);
	gotoxy(119, inicioY);printf("%i", i);
	inicioY++;
}

void resultado(bool exito){
	if(exito){
		printf("\n\nEl metodo converge en la iteracion: %i, con p=%4.15f y f(p) = %4.15f", i, p, FP);
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
