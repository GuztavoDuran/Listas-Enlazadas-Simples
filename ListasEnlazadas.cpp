#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
//se crea el nuevo nodo
struct Nodo{
  int valor;
  Nodo *siguiente;
};
//prototipo de funcion
void menu();
void insertarLista(int);
void mostrarlista();
void buscarLista(int);
void eliminarNodo(int);
Nodo *Lista = NULL; // se crea un puntero y se iguala a NULL
int main(int argc, char const *argv[]) {
  int opcion;
  do {
    menu();
    cin >> opcion;
    switch (opcion) {
      case 1:
        system("cls");
        cout << "INSERTANDO ELEMENTOS DE LA LISTA:" << endl;
        cout << "\n";
        insertarLista(10);
        insertarLista(20);
        insertarLista(5);
        cout << endl;
        system("pause");
        break;
      case 2:
        system("cls");
        cout << "\n\n";
        cout << "MOSTRABDO ELEMENTOS DE LA LISTA" << endl;
        cout << "\n";
        mostrarlista();
        cout << '\n';
        system("pause");
        break;
      case 3:
        system("cls");
        cout << "BUSCAR EN LISTA" << endl;
        int b;
        cout << "inserte elemento a buscar: ";
        cin >> b;
        buscarLista(b);
        cout << '\n';
        system("pause");
        break;
      case 4:
        int d;
        cout << "digite elemento a eliminarNodo: ";
        cin >> d;
        eliminarNodo(d);
        break;
      case 5:
        break;
      default:
        system("cls");
        cout << "opcion no valida: " << '\n';
        system("pause");
        break;
    }
  } while(opcion != 5);
  /*delete aux1;
  delete aux2;
  delete actual;*/
  getch();
  return 0;
}//fin de main

void menu() {
  cout << "MENU" << endl;
  cout << "1.- insertarLista" << endl;
  cout << "2.- mostrarlista" << endl;
  cout << "3.- buscarLista" << endl;
  cout << "4.- eliminarNodo" << endl;
  cout << "5.- SALIR" << endl;
  cout << "inserte opcion:  ";
}

void insertarLista(int n){
  Nodo *inicio = new Nodo();//crear el nuevo nodo
  inicio->valor = n;//se asigna el valor a dato
  //se crean los dos auxiliares
  Nodo *aux1 = Lista;
  Nodo *aux2;
  //while para que se inserten los elementos de forma ordenada
  while((aux1 != NULL) && (aux1 -> valor < n)){
    aux2 = aux1;
    aux1 = aux1 -> siguiente;
  }//fin de while
/*
  si el siguiente condicional se cumple, significa que no ha entrado
  a el while, por lo tanto el elemento va al principio
*/
  if(Lista == aux1){
    Lista = inicio;
  }
/*
  si entra el else, significa que ha entrado al while
  por lo tanto se ha recorrido una posicion
*/
  else{
    aux2 -> siguiente = inicio;
  }
  inicio -> siguiente = aux1;
  cout << "-> " << n ;
}//fin de la funcion insertarLista

void mostrarlista(){
  //se crea un nuevo nodo
  Nodo *actual = new Nodo ();
  //se le asigna al nodo Lista
  actual = Lista;
  while (actual != NULL) {
    //imprime el valor del primer nodo
    cout << " -> " <<actual -> valor ;
    //avanza hasta que actual sea igual a NULL
    actual = actual -> siguiente;
  }
}

void buscarLista(int n){
  Nodo *actual = new Nodo ();
  actual = Lista;
  bool band = false;
  while ((actual != NULL) && (actual -> valor <= n)) {
    if (actual -> valor == n) {
      band = true;
    }
    actual = actual -> siguiente;
  }

  if (band == true) {
    cout << "elemento encontrado..." << endl;
  }else{
    cout << "elemento no encontrado..." << endl;
  }
}//fin de buscarLista

void eliminarNodo(int n){
  //preguntar si la lista no esta vacia
  if (Lista != NULL) {
    Nodo *aux_borrar;
    Nodo *anterior = NULL;

    aux_borrar = Lista;

    //recorremos la Lista
    while ((aux_borrar != NULL) && (aux_borrar -> valor != n)) {
      anterior = aux_borrar;
      aux_borrar = aux_borrar -> siguiente;
    }

    //el elemento no ha sido encontrado
    if(aux_borrar == NULL){
      cout << "No encontrado " << endl;
    }
    //el primer elemento es que se va a aux_borra
    else if (anterior == NULL) {
      Lista = Lista -> siguiente;
      delete aux_borrar;
    }
    //el elemento a borrar no es el primer nodo
    else{
      anterior -> siguiente = aux_borrar -> siguiente;
      delete aux_borrar;

    }

  }
}
