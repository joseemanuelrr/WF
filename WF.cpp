#include "iostream"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void Modulo();
void Start();
void Bienvenida();
void Activar();
void Iniciar();
int MenuApp();
int get_verificador(int a);
int recibido = 0;

int main(){
	int numop;
	system("color 7");
	system("title WIF 1.0 BY: Jose Rojas");
	Bienvenida();
	MenuApp();
	if(get_verificador(recibido)==2){
			system ("DEL data.txt");
	}else{
		cout << ": " << endl;
	}
	Sleep(1500);
	return 0;
}

void Modulo(){
	cout << endl;
	FILE *arch = fopen("data.txt","w");
	char comando[]={"netsh wlan set hostednetwork mode=allow ssid="};
	fputs(comando,arch);
	char ssid[30];
	cout << endl;
	cout << "\tIngrese el nombre de la red a crear: ";
 	cin.get(ssid,30);
 	cout << "\t--------------------------------------------------------------" << endl; 
 	cout << "\tIngrese la clave de la red a crear \n \t(Mayor de 8 digitos entre numeros y letras): ";
	char key[30]; fflush(stdin);
	cin.get(key,30);
	fputs(ssid,arch);
	fputs(" key=",arch);
	fputs(key,arch);
	fclose(arch);
	Start();
}

void Start(){
	FILE *fp = fopen("data.txt","r");
	char programa[100];
	while (fgets(programa, 100, fp) != NULL){
		fputs(programa, fp);
	}
	/*fgets(programa,100,fp); */ //atajo para la linea de codigo 36 sub8
	cout << endl;
	fclose(fp);
	system(programa);
	Activar();
}

void Bienvenida(){
	Sleep(1000);
	cout << "\t\t\t---------------------------------" << endl; 
	cout << "\t\t\tº\t     Wif 1.0\t\tº\n \t\t\tº\t  By: Jose Rojas\tº" << endl; 
	Sleep(1000);
	cout << "\t\t\t---------------------------------" << endl; 
}

void Activar(){
	char opcion;
	cout << "Decea iniciar la red creada? (y/n): ";
	opcion = getch();
	switch (opcion){
		case 'y':
			cout << endl;
			Iniciar();
		case 'n':
			break;
		default:
			cout << "Opcion invalida";
			break;
	}
}

void Iniciar(){
	char confirmar[31]={"netsh wlan start hostednetwork"};
	system(confirmar);
}

int MenuApp(){
	char op;
	cout << "\t\t\t1. Crear red inalambrica " << endl;
	cout << "\t\t\t2. Eliminar red inalambrica " <<endl;
	cout << "\t\t\t---------------------------------" << endl; 
	cout << "\t\t\topcion: ";
	op = getch();
	cout << op;
	switch(op){
		case '1':
			Modulo();
			break;
		
		case '2':
			cout << endl;
			cout << "\t\t\t---------------------------------" << endl; 
			cout << "\t\t\t";
			system("netsh wlan stop hostednetwork");
			cout << "\t\t\tSaliendo del programa";
			Sleep(1300);
			//get_verificador(2);
			//return EXIT_SUCCESS;
			system("pause");
			system("exit");
			break;
			
		default:
			cout << "\n\t\t\tOpcion incorrecta " << endl;
			Sleep(1400);
			system("cls");
			main();
			break;
	}
}

int get_verificador(int a){
	if (a == 0){
		recibido = 2;	
	}
	return recibido;
}
