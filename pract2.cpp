#include <iostream>
#include <fstream>

using namespace std;


struct Person {
  int id_registro;
  char nombre[50];
  float cedula;
  int edad;
  float peso;
  float altura;
  char genero[2];
};


int main(){
  int s;

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
 cout<<"Peso: "<<x.peso<<endl;
 cout<<"Altura: "<<x.altura<<endl;
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