#include <stdio.h>
#include <string.h>

typedef struct _Datos
{
	int id;
	int time;
	int source;
	int destination;
	char protocol[3];
	int lenght;
	char description[50];
};


typedef struct _Nodo {
   struct  _Datos info;
   struct _Nodo *siguiente;
} tipoNodo;

typedef tipoNodo *punteroNodo;
typedef tipoNodo *Lista;

FILE *archivo;

void verificarArchivo(FILE *archivo){
			if (archivo==NULL)
			{
				printf("No leyo el archivo\n");
			}else {
				printf("Todo fino :like:\n");
			}
}

int main(){
	FILE *archivo;
	archivo = fopen("Wiresha.txt", "r");
	verificarArchivo(archivo);


	char cadena[250], cadena2[20];
	int longuitud=250, i;

	/*while(fgets(cadena, longuitud, archivo) != NULL)
	{
		i = strlen(cadena);
		printf("%s\n", cadena[i]);
	}*/

	i=0;
	while(!feof(archivo)){
		if (fgetc(archivo) != '\n')
		{
			printf("linea %i\n", i);
		} else {
			i++;
		}
	}

	fclose(archivo);
  return 0;
}
