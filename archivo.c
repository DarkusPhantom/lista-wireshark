#include <stdio.h>

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


	char cadena[250];
	while(fgets(cadena, 250, archivo) != NULL)
	{
		printf("%s\n", cadena);
	}
    
  return 0;
}
