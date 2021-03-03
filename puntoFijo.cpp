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
float calcularErrorRelativo(float, float);
void resultado(bool);
void encabezadoTabla();
void mostrarIteraciones();
void gotoxy(int, int);

float puntoInicial, tolerancia, p, fp, error, errorRelativo;
int iteracionesMaximas, i, numFuncion, inicio_y = 1;
bool exito;


main(){
	ingreseDatos();
	system("cls");
	encabezadoTabla();
	ejecutarPuntoFijo();
	getch();
}

void ingreseDatos(){
	cout<<"Seleccione la funcion a ejecutar: "<<endl;
	cout<<"1.f(x) = x^4-3x^2-3=0 Transformacion: g(x) = (3x^2 + 3)^1/4"<<endl;
	cout<<"2.f(x) = x^4-3x^2-3=0 Transformacion: g(x) = (-x^4 + 3)^1/2 / -3"<<endl;
	cout<<"3.f(x) = x^4-3x^2-3=0 Transformacion: g(x) = ((3x - x) / x^2)^1/2"<<endl;
	cout<<"4.f(x) = x^3+4x^2-10=0 Transformacion: g(x) = (1/2)(10 - x^3)^1/2"<<endl;
	cout<<"5.f(x) = x^3+4x^2-10=0 Transformacion: g(x) = (10 / (4 + x))^1/2"<<endl;
	cout<<"6.f(x) = 230x^4+18x^3+9x^2-221x-9=0 Transformacion: g(x) = 230x^4/221 + 18x^3/221 + 9x^2/221 - 9/221 ";
	cin>>numFuncion;
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
		errorRelativo = calcularErrorRelativo(p, puntoInicial);
		mostrarIteraciones();
		if(abs(error)<tolerancia){
			exito = true;
			resultado(exito);
		}
		i++;
		puntoInicial = p;
	}
	if(exito == false)
		resultado(exito);
}
float ejecutarFuncionF(float x, int numFuncion){
	if(numFuncion == 1)
		return pow(x, 4)-3*pow(x, 2)-3;
		
	if(numFuncion == 2)
		return pow(x, 4)-3*pow(x, 2)-3;

	if(numFuncion == 3)
		return pow(x, 4)-3*pow(x, 2)-3;
				
	if(numFuncion == 4)
		return pow(x, 3) + 4 * pow(x, 2) - 10;
	
	if(numFuncion == 5)
		return pow(x, 3) + 4 * pow(x, 2) - 10;
	
	if(numFuncion == 6)
		return 230 * pow(x, 4) + 18 * pow(x, 3) + 9 * pow(x, 2) - 221 + x -9;
}
float ejecutarFuncionG(float x, int numFuncion){
	if(numFuncion == 1)
		return pow(3*pow(x, 2)+3, 0.25);//esta transformacion aplica para los 3 puntos indicados
		
	if(numFuncion == 2)
		return pow(pow(-x, 4) + 3, 0.5) / -3;//Esta transformacion unicamente funciona para el punto 1.01
	
	if(numFuncion == 3)
		return pow(3*x-3/pow(x, 2), 0.5);//Esta transformacion unicamente funciona para los puntos 1.50 y 1.99
		
	if(numFuncion == 4)
		return 0.5*pow(10-pow(x, 3), 0.5);//Esto transformacion funciona para cualquier punto de la funcionX
	
	if(numFuncion == 5)
		return pow(10/(4+x), 0.5);//Esto transformacion funciona para cualquier punto de la funcionX
	
	if(numFuncion == 6)
		return ((230 * pow(x, 4)) / 221) + ((18 * pow(x, 3))/ 221) + ((9 * pow(x, 2)) / 221)- ((221 + x)/ 221) - (9 / 221);
}
float calcularError(float p, float puntoInicial){
	return (p-puntoInicial) / p;
}
float calcularErrorRelativo(float p, float puntoInicial){
	return (p-puntoInicial);
}
void resultado(bool exito){
	if(exito){
		printf("\n\nLa solucion aproximada es: p=%4.15f f(p) = %4.15f", p, fp);
	}else{
		printf("\n\nEl algoritmo llego al limite de iteraciones(%i)", iteracionesMaximas);
	}
}
void encabezadoTabla(){
	gotoxy(1, inicio_y);printf("Punto inicial = [%2.2f] Tolerancia = %4.15f", puntoInicial, tolerancia);
 	inicio_y = inicio_y +2;
 	gotoxy(1, inicio_y);printf("Iteracion");
 	gotoxy(15, inicio_y);printf("p0");
 	gotoxy(35, inicio_y);printf("p=g(p0)");
 	gotoxy(55, inicio_y);printf("f(p)");
 	gotoxy(75, inicio_y);printf("Error Abs.");
 	gotoxy(95, inicio_y);printf("Error Rel.");
 	inicio_y++;
}
void mostrarIteraciones(){
	gotoxy(1, inicio_y);printf("%i", i);
	gotoxy(15, inicio_y);printf("%4.15f", puntoInicial);
	gotoxy(35, inicio_y);printf("%4.15f", p);
	gotoxy(55, inicio_y);printf("%4.15f", fp);
	gotoxy(75, inicio_y);printf("%4.15f", error);
	gotoxy(95, inicio_y);printf("%4.15f", errorRelativo);
	inicio_y++;
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
