#include <iostream>
#include <fstream>

using namespace std;


struct Person {
  int id_registro;
  char nombre[50];
  int cedula;
  int edad;
  float peso;
  float altura;
  char genero[2];
};


int main(){
  int s;
int cantidad;
  cout << "Ingrese la cantidad de registros que desea guardar: ";
  cin >> cantidad;
  cin.ignore();

  fstream FILE("./archivo.bin",ios::out|ios::binary);
  
  for(int i=0; i<cantidad; i++){
    Person person;
    int id = (i+1);
    person.id_registro = id;
    cout<<"ID de registro: "<<id<<endl;
    cout<<"Ingrese el nombre de la persona: ";
    cin.getline(person.nombre, 50);
    cout<<"Ingrese su cedula: ";
    cin>>person.cedula;
    cout<<"Ingrese su edad: ";
    cin>>person.edad;
    cout<<"Ingrese su peso (Kg): ";
    cin>>person.peso;
    cout<<"Ingrese su altura (M): ";
    cin>>person.altura;
    cout<< "Ingrese su genero (Utilice: ""M"" para masculino, ""F"" para femenino, ""O"" para otro.): ";
    cin >> person.genero;
    FILE.write(reinterpret_cast<char*>(&person), sizeof(Person));
    cout<<endl;
    cin.ignore();
    }
    FILE.close();

  do{
  int c;
  cout<<"Ingrese el ID del archivo que desea usar: ";
  cin>>c;
 Person x;
 fstream Archivo("./archivo.bin",ios::in|ios::binary);
 if (!Archivo){
  cout<<"Error en lectura del archivo"<<endl;
  return 1;
 }

 Archivo.seekg(sizeof(Person)* (c-1), ios::beg);
 Archivo.read(reinterpret_cast<char *>(&x),sizeof(Person));

 cout<<"Nombre: "<<x.nombre<<endl;
 cout<<"Cedula: "<<x.cedula<<endl;
 cout<<"Edad: "<<x.edad<<endl;
 cout<<"Peso: "<<x.peso<<" Kg"<<endl;
 cout<<"Altura: "<<x.altura<<" M"<<endl;
 cout<<"Genero: "<<x.genero<<endl;
 cout<<endl;

Archivo.close(); 


 cout<<"Desea buscar otro archivo? ";
 cout<<"(Presione 0 si ya ha terminado)"<<endl;
 cin>> s;
 cout<<endl;
  }while(s != 0);


  return 0;
}