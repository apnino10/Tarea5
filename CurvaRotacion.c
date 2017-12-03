#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	/*Definiendo las constantes*/
	double bb=0.2497;
	double bd=5.16;
	double ad=0.3105;
	double ah=64.3
	int G=1;
	
	/*el numero para saber el tamaño del puntero y creandolos*/
	int n, contador=300;

	double *RADIO=malloc(n*sizeof(double));
    	double *VELOCIDAD=malloc(n*sizeof(double));
	
	/*Leyendo el archivo*/
	FILE*archivo = fopen("RadialVelocities.dat", "r");

	/*Leyendo las 2 columnas*/
	//while (!feof(archivo))

	for (contador=0; contador<n; contador++){
	/*Recorriendo cada elemento del  archivo y guardandolo en las variables, %lf indica que es un numero decimal flotante*/
	fscanf(archivo, "%lf %lf", &RADIO[contador], &VELOCIDAD[contador]);
	//printf("radio = %f, velocidad = %f\n", RADIO[contador], VELOCIDAD[contador]);
	}

	fclose(archivo);
		
return 0;

}
