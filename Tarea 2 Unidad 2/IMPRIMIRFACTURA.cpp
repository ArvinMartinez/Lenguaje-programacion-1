#include <iostream>

using namespace std;

double subtotal = 0;
double impuesto = 0.15;
double total = 0;
string  listaproductos;

void agregarproducto(string descripcion, int cantidad, double precio)
{
    subtotal = subtotal  + (cantidad * precio);
    listaproductos = listaproductos + descripcion + '\n';
    total = subtotal + (subtotal * 0.15);
}

void imprimirfactura()
{
    system("cls");
    cout << "********" << endl;
    cout << "factura" << endl;
    cout << "*********" << endl;
    cout << endl;

    cout << "productos: " << endl;
    cout << listaproductos; 

    
    cout << endl;
    cout << "subtotal: " << subtotal;  
    cout << endl; 
    cout << endl; 
    system("pause");

     cout << endl;
    cout << "total: " << total;  
    cout << endl; 
    cout << endl; 
    system("pause");
}