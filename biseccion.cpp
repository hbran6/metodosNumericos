#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <windows.h>

using namespace std;

double a, b, p, tolerancia, FA, FP;
int i, iteraciones, num_funcion, inicio_y = 4, inicio_y_encabezado = 1;
bool exito;

float ejecutar_funcion(float);//ejecuta f(x), f(p)
void ingresar_datos();//pide seleccionar que f(x) ejecutar
void msj_salida(bool);//imprime en pantalla la raiz o el error en caso no se encuentre raiz, recibe el parametro si fue exitoso el algoritmo o no
void mostrar_iteracion();//muestra cada iteracion
void gotoxy(int, int);//para dibujar en consola
void encabezado_tabla();//encabezado de la tabla a imprimir
void ejecutar_biseccion();//ejecuta el algoritmo
void set_variables(bool);//setea los intervalos y la tolerancia, recibe el parametro para verificar si es la primera ejecucion del algoritmo

main(){
	ingresar_datos();
	system("cls");
	
	iteraciones = 100;
	tolerancia = 0.000001;
	if(num_funcion == 1){
		a = -12;
		b = -10;
	}
	ejecutar_biseccion();
	getch();
}

void ejecutar_biseccion(){
	i = 1;
	exito = 0;
	FA = ejecutar_funcion(a);
	encabezado_tabla();
	while(i <= iteraciones && exito == 0){
		p = (a+b)/2;
		FP = ejecutar_funcion(p);
		mostrar_iteracion();
		if(FP == 0 || abs((b-a)/2)<tolerancia){
			exito = 1;
			msj_salida(1);
		}
		if(exito == 0){
			i++;
			if(FA * FP > 0){
				a = p;
				FA = FP;
			}else{
				b = p;
			}
		}
	}
	if(exito == false)
		msj_salida(0);
}

float ejecutar_funcion(float x){
	if(num_funcion == 1)
		return (pow(2, x)) - (6 * cos(x));
}

void ingresar_datos(){
	cout<<"Seleccione la funcion que desea ejecutar: "<<endl;
	cout<<"1. f(x) = 2^x - 6cos(x) Intervalos [-12, -10]"<<endl;
	cin>>num_funcion;
}

void set_variables(bool primera_ejecucion){
	tolerancia = pow(10, -15);
		
	iteraciones = 100;
	
	if(num_funcion == 1){
		a = -12;
		b = -10;
	}
}

void msj_salida(bool exito){
	mostrar_iteracion();
	if(exito){
		printf("\nLa solucion aproximada se obtiene en la iteracion %i, con p%i = %4.15f y f(p) = %4.15f", i, i, p, FP);
	}else{
		printf("\nEl algoritmo llego al limite de iteraciones(%i)", iteraciones);
	}
}
void mostrar_iteracion(){
	gotoxy(1, inicio_y);printf("%i", i);
	gotoxy(15, inicio_y);printf("%4.15f", a);
	gotoxy(35, inicio_y);printf("%4.15f", b);
	gotoxy(55, inicio_y);printf("%4.15f", p);
	gotoxy(75, inicio_y);printf("%4.15f", FP);
	gotoxy(95, inicio_y);printf("%4.15f", abs((a-b)/2));
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
 void encabezado_tabla(){
 	if(inicio_y > 4){
		inicio_y_encabezado = inicio_y+2;
		inicio_y = inicio_y + 5;
	}
	
 	gotoxy(1, inicio_y_encabezado);printf("Intervalo [%2.2f, %2.2f] Tolerancia = %4.15f", a, b, tolerancia);
 	inicio_y_encabezado = inicio_y_encabezado +2;
 	gotoxy(1, inicio_y_encabezado);printf("Iteracion");
 	gotoxy(15, inicio_y_encabezado);printf("a");
 	gotoxy(35, inicio_y_encabezado);printf("b");
 	gotoxy(55, inicio_y_encabezado);printf("p");
 	gotoxy(75, inicio_y_encabezado);printf("f(p)");
 	gotoxy(95, inicio_y_encabezado);printf("error");
 }
