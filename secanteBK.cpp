#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
float fun (float x);
int main() {
 float error=0.0000001,x0,x1,x2,Ea;
 printf ("Este codigo fue hecho por Jair Beltran USCO Garzon");
 printf ("Digite el primer valor ");
 scanf ("%f",&x0);
 printf ("Digite el segundo valor ");
 scanf ("%f",&x1);
 Ea=error+1;
 while (Ea>error)
 {x2=(x1-((x0-x1)/(fun(x0)-fun(x1))*fun(x1)));
 printf ("%f \n",x2);
 Ea=(fabs (x1-x2));
 x0=x1;
 x1=x2;
 }
 printf ("la raiz es:%4.12f \n",fun(x2));
 return 0;
}
float fun(float x)
{float f;
f=x*x*x+x+16;
return f;
}
