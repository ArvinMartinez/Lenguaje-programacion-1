#include <iostream>
#include <math.h>

 
using namespace std;
 
void RaizCuadrada()
 {

  double numero = 0;
  double raiz = 0;

 
  cout << "Escribe un numero:";
  cin >> numero;
 
  raiz = sqrt(numero);
  
  cout << endl;
 
  cout << "La raiz cuadrada de " << numero << " es " << raiz << endl;
 
  system("pause");
}
