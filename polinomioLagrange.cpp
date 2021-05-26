/*
Herber Bran
Universidad Mariano Galvez de Guatemala
Metodos Numericos

Polinomio de Lagrange
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

void gotoxy(int, int);

main(){
	int n, i, j, inicio_y = 0;
	double x[100], y[100], z, valor = 0, v;
	
	cout<<"Polinomio de Lagrange"<<endl<<endl;
	cout<<"Ingrese la cantidad de elementos: ";
	cin>>n;
	for(i = 1; i <= n; i++){
		cout<<"Ingrese el elemento x"<<i<<": ";
		cin>>x[i];
		
		cout<<"Ingrese el elemento y"<<i<<": ";
		cin>>y[i];
	}
	cout<<endl;
	cout<<"Ingrese el punto a interpolar: ";
	cin>>z;
	system("cls");
	gotoxy(1, inicio_y);printf("i");
	gotoxy(5, inicio_y);printf("j");
	gotoxy(15, inicio_y);printf("v");
	inicio_y++;
	for(i = 1; i <= n; i++){
		v = 1;
		for(j = 1; j <= n; j++){
			gotoxy(1, inicio_y);printf("%i", i);
			gotoxy(5, inicio_y);printf("%i", j);
			if(i != j){
				v = v * (z - x[j])/(x[i] - x[j]);
				gotoxy(15, inicio_y);printf("%4.15f", v);
				inicio_y++;
			}
		}
		valor = valor + v * y[i];
	}
	printf("\n\nEl valor es: %4.15f", valor);
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

