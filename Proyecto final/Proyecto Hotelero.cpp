#include<iostream>
#include<string.h>
#include<conio.h>

#define max 100
using namespace std;

//variables
class Customer
{	
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};


class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;

class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};


class Room rooms[max];
int count=0;


Room Room::addRoom(int rno)
{
class Room room;
room.roomNumber=rno;
cout<<"\nTipo Numero de camas(A/B)(presiones la letra A para una cama o preciones B para dos camas) : ";
cin>>room.ac;
cout<<"\nTipo Confort (S/N)(Presione S para una paquete de confort preciones N una habitacion Normal ) : ";
cin>>room.type;
cout<<"\nTipo Tamaño Habitacion (G/N)(Precione la letra G para habitacion grande o le letra N habitacion mediana): ";
cin>>room.stype;
cout<<"\nRenta Diaria : ";
cin>>room.rent;
room.status=0;

cout<<"\n Sala añadida con exito!";
getch();
return room;
}


void Room::searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
cout<<"Detalles de Habitacion\n";
if(rooms[i].status==1)
{
cout<<"\nLa habitacion esta Reservada";
}
else
{
cout<<"\nHabitacion Disponible";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\nHabitacion no Encontrada";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
cout<<"\nNumero de Habitacion: \t"<<tempRoom.roomNumber;
cout<<"\nTipo AC/Non-AC (A/N) "<<tempRoom.ac;
cout<<"\nTipo Comfort (S/N) "<<tempRoom.type;
cout<<"\nTipo Size (B/S) "<<tempRoom.stype;
cout<<"\nRenta: "<<tempRoom.rent;
}

//gestión hotelera
class HotelMgnt:protected Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

if(count==0){
	cout<<"\n No hay Huesped en el Hotel !!";
}	
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<"\n Nombre del cliente: "<<rooms[i].cust.name;
cout<<"\n Numero de Habitacion : "<<rooms[i].roomNumber;
cout<<"\n Direccion (solo ciudad) : "<<rooms[i].cust.address;
cout<<"\n Telefono : "<<rooms[i].cust.phone;
cout<<"\n---------------------------------------";	
}
	
}

getch();
}

//hotel reservation
void HotelMgnt::checkIn()
{
int i,found=0,rno;

class Room room;
cout<<"\nIngrese numero Habitacion : ";
cin>>rno;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
cout<<"\nLa habitacion ya esta reservada";
getch();
return;
}

cout<<"\nIngrese la identificacion de la reserva: ";
cin>>rooms[i].cust.booking_id;

cout<<"\nIngrese el nombre del cliente (Primer nombre): ";
cin>>rooms[i].cust.name;

cout<<"\nIngrese la dirección (solo ciudad): ";
cin>>rooms[i].cust.address;

cout<<"\nIgrese Telefono: ";
cin>>rooms[i].cust.phone;

cout<<"\nIngrese desde la fecha Entrada: ";
cin>>rooms[i].cust.from_date;

cout<<"\nIngrese desde la fecha Salida: ";
cin>>rooms[i].cust.to_date;


cout<<"\nIngrese el pago por adelantado: ";
cin>>rooms[i].cust.payment_advance;

rooms[i].status=1;

cout<<"\nEl cliente se registro correctamente..";
getch();
}
}


//muestra las habitaciones disponibles
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
cout<<"\n\nPresiona enter para la proxima habitacion";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nTodas las habitaciones están reservadas.";
getch();
}
}


//Muestra a todas las personas que han reservado una habitación
void HotelMgnt::searchCustomer(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
cout<<"\nNombre del cliente: "<<rooms[i].cust.name;
cout<<"\nNúmero de habitación: "<<rooms[i].roomNumber;

cout<<"\n\nPresiona enter para el siguiente registro";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\nPersona no encontrada.";
getch();
}
}


// factura de los gastos
void HotelMgnt::checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//rno = rooms[i].roomNumber;
found=1;
//getch();
break;
}
}
if(found==1)
{
cout<<"\nIngrese el numero de dias:\t";
cin>>days;
billAmount=days * rooms[i].rent;

cout<<"\n\t######## Detalles de pago ########\n";
cout<<"\nNombre del cliente : "<<rooms[i].cust.name;
cout<<"\nNumero de habitacion : "<<rooms[i].roomNumber;
cout<<"\nDireccion : "<<rooms[i].cust.address;
cout<<"\nTelefono : "<<rooms[i].cust.phone;
cout<<"\nImporte total adeudado : "<<billAmount<<" /";
cout<<"\nAdelanto pagado: "<<rooms[i].cust.payment_advance<<" /";
cout<<"\n*** Total a pagar: "<<billAmount-rooms[i].cust.payment_advance<<"/ only";

rooms[i].status=0;
}
getch();
}


//administrar habitaciones (agregar y buscar habitaciones disponibles)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
cout<<"\n### Administrar habitaciones ###";
cout<<"\n1. Anadir habitacion";
cout<<"\n2. Sala de búsqueda";
cout<<"\n3. Volver al menu principa";
cout<<"\n\nIntroducir opcion: ";
cin>>opt;


//declaración de cambio
switch(opt)
{
case 1:
cout<<"\nIntroduzca el numero de habitacion: ";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
cout<<"\nEl numero de habitacion esta presente.\nIngrese un numero unico";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
cout<<"\nIngrese el numero de la habitacion: ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//
break;
default:
cout<<"\nIngrese la opcion correcta";
break;
}
}while(opt!=3);
}
using namespace std;
int main()

{	
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];

system("cls");

do
{
system("cls");
cout<<"######## Gestion Hotelera #########\n";
cout<<"\n1. Administrar habitaciones";
cout<<"\n2. Habitacion de registro";
cout<<"\n3. Cuartos disponibles";
cout<<"\n4. Buscar cliente";
cout<<"\n5. Sala de Salida";
cout<<"\n6. Informe de resumen de invitados";
cout<<"\n7. Salida";
cout<<"\n\nIntroducir opcion: ";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\nLos datos de las habitaciones no estan disponibles.\nAgregue las habitaciones primero.";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout<<"\nLos datos de las habitaciones no estan disponibles.\nAgregue las habitaciones primero.";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\nLas habitaciones no estan disponibles.\nAgregue las habitaciones primero.";
getch();
}
else
{
cout<<"Ingrese el nombre del cliente: ";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\nLas habitaciones no estan disponibles.\nAgregue las habitaciones primero.";
getch();
}
else
{
cout<<"Ingrese el numero de habitacion : ";
cin>>rno;
hm.checkOut(rno);
}
break;
case 6:
hm.guestSummaryReport();	
break;
case 7:
cout<<"\n¡GRACIAS! PARA UTILIZAR MY SOFTWARE";
break;
default:
cout<<"\nIngrese la opcion correcta";
break;
}
}while(opt!=7);

getch();
system("pause");
return 0;
}
