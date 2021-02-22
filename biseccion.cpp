#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <windows.h>

using namespace std;

float a, b, p, tolerancia, FA, FP;
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
	
//	set_variables(1);
iteraciones = 100;
tolerancia = pow(10, -4);
if(num_funcion == 1){
		a = 0;
		b = 1;
	}
	if(num_funcion == 2){
		a = 0;
		b = 1;
	}
	if(num_funcion == 3){
		a = -1;
		b = 0;
	}
	if(num_funcion == 4){
		a = 0.2;
		b = 0.3;
	}
	if(num_funcion == 5){
		a = 1.2;
		b = 1.3;
	}
	ejecutar_biseccion();
//	set_variables(0);
tolerancia = pow(10, -8);
if(num_funcion == 1){
		a = 0;
		b = 1;
	}
	if(num_funcion == 2){
		a = 0;
		b = 1;
	}
	if(num_funcion == 3){
		a = -1;
		b = 0;
	}
	if(num_funcion == 4){
		a = 0.2;
		b = 0.3;
	}
	if(num_funcion == 5){
		a = 1.2;
		b = 1.3;
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
		if(FP == 0 || (abs(b-a)/2)<tolerancia){
			exito = 1;
			msj_salida(1);
		}
		if(exito == 0){
			i++;
//			printf("\nFA:%4.15f", FA);
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
//	do{
//		p = (a+b)/2;
//		FP = ejecutar_funcion(p);
//		if(FP == 0 || (abs(b-a)/2)<tolerancia){
//			exito = true;
//			msj_salida(1);
//		}else{
//			mostrar_iteracion();
//			i++;
//			if(FA * FP > 0){
//				a = p;
//				FA = FP;
//			}else{
//				b = p;
//			}
//		}		
//	}while((i <= iteraciones) && exito == false);
//	if(exito == false)
//		msj_salida(0);
}

float ejecutar_funcion(float x){
	if(num_funcion == 1)
		return x - pow(2, x*-1);
		
	if(num_funcion == 2)
		return pow(2.71828, x) - pow(x, 2) + 3*x - 2;
		
	if(num_funcion == 3)
		return 2 * x * cos(x) - pow((x+1), 2);
		
	if(num_funcion == 4 || num_funcion == 5)
		return x * cos(x) - pow(2 * x, 2) + 3 * x - 1;
}

void ingresar_datos(){
	cout<<"Seleccione la funcion que desea ejecutar: "<<endl;
	cout<<"1. f(x) = x - 2^-x = 0 Intervalos [0, 1]"<<endl;
	cout<<"2. f(x) = e^x - x^2 + 3x - 2 = 0 Intervalos [0, 1]"<<endl;
	cout<<"3. f(x) = 2x * cos(x) - (x+1)^2 = 0 Intervalos [-1, 0]"<<endl;
	cout<<"4. f(x) = x * cos(x) - 2x^2 + 3x - 1 = 0 Intervalos [0.2, 0.3]"<<endl;
	cout<<"5. f(x) = x * cos(x) - 2x^2 + 3x - 1 = 0 Intervalos [1.2, 1.3]"<<endl;
	cin>>num_funcion;
}

void set_variables(bool primera_ejecucion){
	tolerancia = pow(10, -8);
	if(!primera_ejecucion)
		tolerancia = pow(10, -4);
		
	iteraciones = 100;
	
	if(num_funcion == 1){
		a = 0;
		b = 1;
	}
	if(num_funcion == 2){
		a = 0;
		b = 1;
	}
	if(num_funcion == 3){
		a = -1;
		b = 0;
	}
	if(num_funcion == 4){
		a = 0.2;
		b = 0.3;
	}
	if(num_funcion == 5){
		a = 1.2;
		b = 1.3;
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
	gotoxy(15, inicio_y);printf("%4.15f", FA*FP);
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
