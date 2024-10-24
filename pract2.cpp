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
  int c;
  cout<<"Ingrese el ID del archivo que desea usar: ";
  cin>>c;
 Person x;
 fstream FILE("./archivo.bin",ios::in|ios::binary);
 FILE.seekg(sizeoof(Person)* c, ios::beg);
 cout<<FILE.tellg()<<endl;
 FILE.read(reinterpret_cast<char *>(&x),sizeof(Person));

 cout<<x.nombre;
 cout<<x.cedula;
 cout<<x.edad;
 cout<<x.altura;
 cout<<x.genero;

 FILE.close()



  return 0;
}