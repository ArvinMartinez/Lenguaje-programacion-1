#include <iostream>

using namespace std;

	int sumar(int a, int b){ 
		return a+b;
	}
	int resta(int a, int b){ 
		return a-b;
	}	
	
	int main(int argc, char const *argv[])
	{
	
	system("cls");
	
	int numero1=0;
	int numero2=0;
	
	cout<<"ingrese el valor a: ";
	cin>>numero1;
	cout<<"ingrese el valor b: ";
	cin>>numero2;
	
	cout<< endl;
	
	cout<<"El resultado de la suma es:"<< sumar(numero1, numero2);
	cout<<endl;
	cout<<"El resultado de la resta es:"<< resta(numero1, numero2);
	cout<< endl;
	
	return 0;
}
