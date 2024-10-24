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
  fstream FILE("./archivo.bin",ios::out|ios::binary);

  
  int cantidad;
  cout << "Ingrese la cantidad de registros que desea guardar: ";
  cin >> cantidad;
  cin.ignore();
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
    cout<<"Ingrese su peso: ";
    cin>>person.peso;
    cout<<"Ingrese su altura: ";
    cin>>person.altura;
    cout<< "Ingrese su genero (Utilice: ""M"" para masculino, ""F"" para femenino, ""O"" para otro.): ";
    cin >> person.genero;
    FILE.write(reinterpret_cast<char*>(&person), sizeof(Person));
    cout<<endl;
    cin.ignore();
    }
    FILE.close();


  return 0;
}