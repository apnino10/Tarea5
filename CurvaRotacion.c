#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	
	
	/*el numero para saber el tamaño del puntero y creandolos*/
	int i = 300;
	int n = 300; 
	int contador = 300;

	double radio, velocidad, se_parece_a;

	double *RADIO=malloc(n*sizeof(double));
    	double *VELOCIDAD=malloc(n*sizeof(double));
	
	/*Leyendo el archivo*/
	/*Leyendo las 2 columnas*/	
	/*Recorriendo cada elemento del  archivo y guardandolo en las variables, %lf indica que es un numero decimal flotante*/
	FILE*archivo = fopen("RadialVelocities.dat", "r");
	//while (!feof(archivo))
	for (contador=0; contador<n; contador++){
	fscanf(archivo, "%lf %lf", &RADIO[contador], &VELOCIDAD[contador]);
	//printf("radio = %f, velocidad = %f\n", RADIO[contador], VELOCIDAD[contador]);
	}

	fclose(archivo);

	/*Creando el pointer donde se guardaran los nuevos valores de velocidad calculados*/
	/*Al graficar los datos del archivo, la tendencia general de estos es similar a e^-x*/
	/*Generando los numeros aleatorios para calcular los parametros*/

	double *VELOCIDAD_2=malloc(n*sizeof(double));
	double Mb, Md, Mh;
	double *SE_PARECE_A = malloc(n*sizeof(double));

	for( i=0; i< n; i++ ) {

		se_parece_a = exp(-1*radio);
		Mb=drand48();	
		Md=drand48();
		Mh=drand48();

		RADIO[i] = radio;	
		VELOCIDAD[i] = velocidad;	
		SE_PARECE_A[i] = se_parece_a;

	}

	/*Guardando los valores en un txt e imprimiendo en la consola*/
	
	FILE *modelo;
	modelo=fopen("Resultados_hw5.txt", "w");
	for(i=0; i<n; i++){
        	fprintf(modelo, "%f %f %f \n", Mb, Md, Mh);
	}

	printf("Mb = %f\n Md = %f\n Mh = %f\n", Mb, Md, Mh);

return 0;

}
