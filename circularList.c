/*
   Estudiante: Luis Rodriguez
   Ci: 26 816 816

   -------------INSTRUCCIONES--------------
   Ejecucion del programa:
   1) gcc proyectList.c -o proyectList.o
   2) ./proyectList.o
*/

//--------------------   Librerias
#include <stdio.h>
#include <stdlib.h>


//--------------------   Estructuras y Definicion de tipos
typedef struct _Nodo {
   int valor;
   struct _Nodo *siguiente;
} tipoNodo;

typedef tipoNodo *punteroNodo;
typedef tipoNodo *Lista;

//--------------------   Funciones y Procedimientos
void InsertarElemento(Lista *lista, int elemento) {
   punteroNodo nodo;

   // Creamos un nodo para el nuevo valor a insertar en la lista
   nodo = (punteroNodo)malloc(sizeof(tipoNodo));
   nodo->valor = elemento;

   // Si la lista está vacía, la lista será el nuevo nodo
   // Caso contrario, el nuevo nodo es insertado en direccion apuntada en la lista
   if(*lista == NULL) *lista = nodo;
   else nodo->siguiente = (*lista)->siguiente;
   // En cualquier caso, cerramos la lista circular
   (*lista)->siguiente = nodo;
}

void BorrarElemento(Lista *lista, int elemento) {
   punteroNodo nodo;

   nodo = *lista;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if((*lista)->siguiente->valor != elemento) *lista = (*lista)->siguiente;
   } while((*lista)->siguiente->valor != elemento && *lista != nodo);
   // Si existe un nodo con el valor v:
   if((*lista)->siguiente->valor == elemento) {
      // Y si la lista sólo tiene un nodo
      if(*lista == (*lista)->siguiente) {
         // Borrar toda la lista
         free(*lista);
         *lista = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         nodo = (*lista)->siguiente;
         (*lista)->siguiente = nodo->siguiente;
         free(nodo);
      }
   }
}

void BorrarLista(Lista *lista) {
   punteroNodo nodo;

   // Mientras la lista tenga más de un nodo
   while((*lista)->siguiente != *lista) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = (*lista)->siguiente;
      (*lista)->siguiente = nodo->siguiente;
      free(nodo);
   }
   // Y borrar el último nodo
   free(*lista);
   *lista = NULL;
}

void MostrarLista(Lista lista) {
   punteroNodo nodo = lista;

   do {
      printf("%d -> ", nodo->valor);
      nodo = nodo->siguiente;
   } while(nodo != lista);
   printf("\n");
}

void menu() {
   int continuar=1, numero, opciones;
   Lista lista=NULL;

   printf("Bienvenido a la creacion de la Lista Circular. 'Que desea?");
   do {
      printf("\n-------Menu-------\n");
      printf("1. Insertar elemento en Lista\n");
      printf("2. Borrar elemento en Lista\n");
      printf("3. Buscar elemento en la Lista\n");
      printf("4. Mostrar Lista\n");
      printf("5. Salir\n");
      do{
         printf("Seleccione una Opcion (del 1-5):\n");
         scanf("%i", &opciones);
         //Verifica si el numero introducido es valido
         if (opciones > 5 || opciones < 1) printf("\nEl numero que introduciste no es valido. Intente de nuevo\n");
      } while (opciones > 5 || opciones < 1);

      //---------------------    Menu
      switch(opciones){
         //Insertar un elemento a la lista
         case 1:
                  printf("\nIngrese un numero decimal a insertar en la lista\n");
                  scanf("%i", &numero);
                  InsertarElemento(&lista, numero);
                  printf("Elemento insertado.\n");
               break;

         //Borrar un elemento de la lista
         case 2:
               if (lista != NULL){
                  MostrarLista(lista);
                  printf("\nSeleccione un numero de la lista a insertar en la lista\n");
                  scanf("%i", &numero);
                  BorrarElemento(&lista, numero);
                  printf("Elemento borrado.\n");
               } else {
                  printf("\nLa lista esta vacia\n");
               }
               break;

         //Buscar un elemento a la lista
         case 3:
                  printf("No disponible\n");
                  //printf("Ingrese un numero decimal a insertar en la lista\n");
                  //scanf("%i", &numero);
                  //printf("%i\n", numero);
               break;

         //Mostrar lista
         case 4:
               if (lista != NULL) {
                  printf("\nLista actual:\n");
                  MostrarLista(lista);
               } else {
                  printf("\nLa lista esta vacia\n");
               }
               break;

         //Salir del programa
         case 5:
               if(lista != NULL) {
                  printf("\nBorrando lista...");
                  BorrarLista(&lista);
               }
               printf("\nSaliendo del programa...\n");
               continuar = 0;
               break;
      }
   } while (continuar == 1);
}


int main() {
   int opciones, continuar;

   printf("************__________________*****************\n");
   printf("***********(                  )****************\n");
   printf("**********(                    )***************\n");
   printf("*********(                      )**************\n");
   printf("********(~~~~~~LISTA~CIRCULAR~~~~)*************\n");
   printf("*********(                      )**************\n");
   printf("**********(                    )***************\n");
   printf("***********(__________________)***************\n\n");
   printf("...Creando Lista...\n");
   printf("Lista Creada\n\n");
   menu();

   return 0;
}