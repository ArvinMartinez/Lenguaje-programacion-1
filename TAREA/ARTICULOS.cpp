#include <iostream>

using namespace std;

extern void agregarproducto(string descripcion, int cantidad, double precio);

                       
void productos(int opcion) 
 { 
 system("cls");
  int opcionproducto = 0;
  switch (opcion)
      {
          case 1:  
            {
           cout << "bebidas calientes" << endl;
           cout << "xxxxxxxxxxxxxxx" << endl;
           cout << "1 capuchino - L 25.00" << endl;
           cout << "2- Mocca- L 16.00" << endl;
           cout << "3- Frappe - L 16.00" << endl;
           cout << endl;

           cout << "ingrese una opcion: ";
         
           cin >> opcionproducto;
            switch (opcionproducto)
            {
            case 1:
              agregarproducto("1 capuchino - L 25.00", 1, 25);
              break;
            case 2:
              agregarproducto("2 Mocca - L 16.00", 1, 16);
              break;
            case 3:
              agregarproducto("3 Frappe - L 16.00", 1, 16);
              break;
            default:
            {
             cout << "opcion no valida";
             return;
              break;
              }
            }
              cout << endl; 
             cout << "producto agregado" << endl << endl;
             system("pause");
             break;
          }
          
     case 2:
     {
           cout << "*******" << endl;
          cout << "bebidas frias" << endl;
          cout << "*******" << endl;
           cout << "1 Jugo de jamaica- L 25.00" << endl;
           cout << "2 Limonada - L 16.00" << endl;
           cout << "3 Iced Tea - L 18.00" << endl;
           cout << endl;

           cout << "ingrese una opcion: ";
         
           cin >> opcionproducto;
            switch (opcionproducto)
            {
            case 1:
              agregarproducto("1 Jugo de jamaica - L 25.00", 1, 25);
              break;
            case 2:
              agregarproducto("1 Limonada - L 16.00", 1, 16);
              break;
            case 3:
              agregarproducto("3 Icea Tea - L 18.00", 1, 18);
              break;  
            default:
            {
             cout << "opcion no valida";
             return;
              break;
              }
            }
              cout << endl; 
             cout << "producto agregado" << endl << endl;
             system("pause");
             break;
          }
                    
           break;
           } 
   switch (opcion)       
   
     case 3:
        {
          cout << "*******" << endl;
          cout << "reposteria" << endl;
          cout << "*******" << endl;
          cout << "1 Brownie - L 150.00" << endl;
          cout << "2 pie de limon - L 10.00" << endl;
          cout << "3 Torta de Chocolate - L 15" << endl;
          cout << endl;
          cout << "ingrese una opcion: ";
         
           cin >> opcionproducto;
          switch (opcionproducto)
            {
          case 1:
           agregarproducto("1 Brownie - L 15.00", 1, 15);
            break;
            case 2:
             agregarproducto("2 pie de limon - L 10.00", 1, 10);
             break;
            default:
             case 3:
             agregarproducto("3 Torta de Chocolate - L 15.00", 1, 15);
             break;
            {
           cout << "opcion no valida";
           return;
             break;
            }
            }
             cout << endl; 
             cout << "producto agregado" << endl << endl;
             system("pause");
             break;
          }       
}
