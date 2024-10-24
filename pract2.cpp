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
  char genero[1];
};


int main(){
  fstream FILE("./archivo.bin",ios::out|ios::binary);

  
  int cantidad;
  cout << "Ingrese la cantidad de registros que desea guardar: ";
  cin >> cantidad;
  cin.ignore();
  for(int i=0; i<cantidad; i++){
    Person person;
    cout<<"Ingrese el nombre de la persona: ";
    cin.getline(person.nombre, 50);
    cout<<"Ingrese su ID de registro: "; //No se si la ID se otorga o la introduce el usuario
    cin>>person.id_registro;
    cout<<"Ingrese su edad: ";
    cin>>person.edad;
    cout<<"Ingrese su peso: ";
    cin>>person.peso;
    cout<<"Ingrese su altura: ";
    cin>>person.altura;
    cout<< "Ingrese su genero (Utilice: ""M"" para masculino, ""F"" para femenino, ""O"" para otro.): ";
    cin >> person.genero;
    FILE.write(reinterpret_cast<char*>(&person), sizeof(Person));
    }
    FILE.close();


  return 0;
}