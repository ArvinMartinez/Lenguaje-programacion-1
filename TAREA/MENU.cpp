#include <iostream>

using namespace std;

extern void productos(int opcion);
extern void imprimirfactura();

void menu()
{
          int opcion = 0;
      
 while(true)
 {
   system("cls");
        cout << "*******";
     cout << "menu";
     cout << "*******";
     cout << endl;
     cout << endl;
    
     cout << "1 - Bebidad Calientes" << endl;
     cout << "2 - Bebidas Frias" << endl;
     cout << "3 - Reposteria" << endl;
     cout << "4 - Imprimir factura" << endl;
     cout << "0 - Salir" << endl;

     cin >> opcion;

     if (opcion == 0)
     {
         break;
     }
     if (opcion == 4)
     
     {
       imprimirfactura();
       break;
     } else{
       productos(opcion);
     }
     
  }
}