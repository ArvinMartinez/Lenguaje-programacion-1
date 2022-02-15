/* 
   Autor: Brayam Ovidio Pineda Hernandez
   Cuenta: 20182002211
*/

#include <iostream>

using namespace std;

int main ()
{

	int pares = 0, impares = 0, suma = 0;
	
	cout << " Programa para sumar pares e impares " <<endl;
	
	for (int i = 1; i <= 10; i++) // Ciclo utilizado
	{
		if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10) // Separa los numeros pares
		{
			pares = pares + i;
		}
		cout << i << " "<<endl<<endl;
		
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) // Separa los numeros impares
		{
			impares = impares + i;
		}
	}
	
	suma = pares + impares;
	cout << " La suma total de los pares es de: " <<pares <<endl;
	cout << " La suma total de los impares es de: "<<impares <<endl;
	cout << " La suma de pares e impares es de : "<<suma <<endl;
	return 0;
}
