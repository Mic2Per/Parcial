#include<iostream>
#include <fstream>
#include <windows.h>
using namespace std;

void ingresar();
void mostrar();
void buscar();
void eliminar();
void modificar();

bool evaluar(string cod){
	ifstream leer("Archivo.txt", ios::in);
	string nom;
	string cod2;
	string ape;
	string pues;
	string suel;
	string boni;
	leer>>nom;
	while(!leer.eof()){
	leer>>ape;
	leer>>cod2;
	
	if(cod2 == cod){
		leer.close();
		return false;
	}
	leer>>nom;
	}
	leer.close();
	return true;	
	}

void mostrar(ifstream &Lec){
	system("cls");
	string nom;
	string ape;
	string cod2;
	string pues;
	string suel;
	string boni;
	Lec.open("Archivo.txt", ios::in);
	cout<<"__________________________Registros__________________________"<<endl<<endl;
	Lec>>nom;
	while(!Lec.eof()){
		Lec>>ape;
		Lec>>cod2;
		Lec>>pues;
		Lec>>suel;
		Lec>>boni;
		cout<<"Codigo: "<<cod2<<endl;
		cout<<"Nombre: "<<nom<<endl;
		cout<<"Apellidos: "<<ape<<endl;
		cout<<"Puesto: "<<pues<<endl;
		cout<<"Sueldo: "<<suel<<endl;
		cout<<"Bonificacion: "<<boni<<endl;
		Lec>>nom;
		
	}
  	Lec.close();
	system("pause");
	}

void ingresar(ofstream &es){
	system("cls");
	string nom;
	string ape;
	string cod2;
	string pues;
	string suel;
	string boni;
	es.open("Archivo.txt", ios::out | ios::app);
	cout<<"__________________________Ingresar__________________________"<<endl;
	cout<<"Ingrese el Codigo del Empleado: ";
	cin>>cod2;
	cout<<"Ingrese el Nombre del Empleado: ";
	cin>>nom;
	cout<<"Ingrese el Apellido del Empleado: ";
	cin>>ape;
	cout<<"Ingrese el Puesto del Empleado: ";
	cin>>pues;
	cout<<"Ingrese el Sueldo del Empleado: ";
	cin>>suel;
	cout<<"Ingrese la Bonificacion del Empleado: ";
	cin>>boni;
	if(evaluar(cod2))
	es<<nom<<" "<<ape<<" "<<cod2<<" "<<pues<<" "<<suel<<" "<<boni<<"\n ";
	es.close();
}

void buscar(ifstream &Lec){
	system("cls");
	Lec.open("Archivo.txt", ios::in);
	string nom,ape,cod2,pues,suel,boni,cod3;
	bool ver=false;
	cout<<"Ingrese el codigo que desea Buscar: ";
	cin>>cod3;
	Lec>>nom;
	while(!Lec.eof()  &&  !ver){
	Lec>>ape;
	Lec>>cod2;
	Lec>>pues;
	Lec>>suel;
	Lec>>boni;
	if(cod2 == cod3){
		cout<<"__________________________Buscar__________________________"<<endl;
		cout<<"Codigo: "<<cod2<<endl;
		cout<<"Nombre: "<<nom<<endl;
		cout<<"Apellidos: "<<ape<<endl;
		cout<<"Puesto: "<<pues<<endl;
		cout<<"SuelBase: "<<suel<<endl;
		cout<<"Bonificacion: "<<boni<<endl;
		cout<<"_________________________________________________"<<endl;
		ver=true;
		
	}
	Lec>>nom;
	}
	Lec.close();
	if(!ver)
	cout<<"No se encuantra en registro"<<endl;
	system("pause");
}

void eliminar(ifstream &Lec){
	system("cls");
	string nom;
	string ape;
	string cod2;
	string cod3;
	string nom2;
	Lec.open("Archivo.txt", ios::in);
	ofstream rem("Archivo2.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Ingrese el codigo que desea eliminar: ";
		cin>>cod3;
		Lec>>nom;
		while(!Lec.eof()){
		Lec>>ape;
		Lec>>cod2;
	
		if(cod2 == cod3){
			cout<<"Registro Eliminado";
			Sleep(1500);	
		}else{
		rem<<nom<<" "<<ape<<" "<<cod2<<"\n";
		}
		Lec>>nom;
		}
		Lec.close();
		rem.close();
	}else
	cout<<"Error"<<endl;
	remove("Archivo.txt");
	rename("Archivo2.txt", "Archivo.txt");
}

void modificar(ifstream &Lec){
	system("cls");
	string nom;
	string cod2;
	string ape;
	string cod3;
	string nom2;
	Lec.open("Archivo.txt", ios::in);
	ofstream rem("Archivo2.txt", ios::out);
	if(Lec.is_open()){
		cout<<"Ingrese el codigo que desea modificar";
		cin>>cod3;
		Lec>>nom;
		while(!Lec.eof()){
			Lec>>ape;
			Lec>>cod2;
			if(cod2 == cod3){
				cout<<"Nuevo registro ";
				cin>>nom2;
				rem<<nom2<<" "<<ape<<" "<<cod2<<"\n";
				
			}else{
				rem<<nom<<" "<<ape<<" "<<cod2<<"\n";
			}
			Lec>>nom;
			}			
			Lec.close();
			rem.close();
		}else
		cout<<"Error"<<endl;
		remove("Archivo.txt");
		rename("Archivo2.txt", "Archivo.txt");
	
}

int main(){
	int codigo;
	char nombres;
	char apellidos;
	char puesto;
	int sueldo=0,bonificacion=0,suma=0,op,op2;
	float op3=0;
	
	do{
	cout<<"__________________________Menu__________________________"<<endl;
	cout<<"Elija una opcion"<<endl;
	cout<<"1) Ingrese el empleado"<<endl;
	cout<<"2) Buscar Empleado "<<endl;
	cout<<"3) Eliminar Registro"<<endl;
	cout<<"4) Modificar"<<endl;
	cin>>op;
	
	system("cls");
	
		ofstream Esc;
		ifstream Lec;
		system("cls");
		switch(op){
		case 1:
			ingresar(Esc);
			break;
			
		case 2:
			buscar(Lec);
			break;
			
		case 3:
			eliminar(Lec);
			break;
			
		case 4:
			modificar(Lec);
			break;
			
		case 5:
			mostrar(Lec);
			break;
	}
	}while(op!=6);
	
	return 0;
	
	
}




