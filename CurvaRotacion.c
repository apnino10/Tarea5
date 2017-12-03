#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	/*el numero para saber el tamaño del puntero y creandolos, definiendo las variables*/
	int i = 300;
	int n = 300; 
	int contador = 300;
	int numit = 100000;
	double delta = 0.5;

	double radio, velocidad, se_parece_a;
	double Mb_viejo, Mb_nuevo, Md_viejo, Md_nuevo, Mh_viejo, Mh_nuevo, alpha;

	double *RADIO = malloc(n*sizeof(double));
    	double *VELOCIDAD = malloc(n*sizeof(double));
	
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
	/*alpha permite saber cuando se abanza, si alpha > 1 no sirve y hay que buscar otro*/

	double *VELOCIDAD_2 = malloc(n*sizeof(double));
	double *SE_PARECE_A = malloc(n*sizeof(double));

	Mb_viejo = 2.0*drand48() - 1.0;	
	Md_viejo = 2.0*drand48() - 1.0;
	Mh_viejo = 2.0*drand48() - 1.0;

	for( i=0; i<numit; i++ ) {

		Mb_nuevo = Mb_viejo + (2.0*drand48() - 1.0);	
		Md_nuevo = Md_viejo + (2.0*drand48() - 1.0);
		Mh_nuevo = Mh_viejo + (2.0*drand48() - 1.0);

		if(alpha > 1)
		{
		    alpha = 1;
		}
		if(alpha > drandom48())
		{
		    Mb_nuevo = Mb_viejo;
		    Md_nuevo = Md_viejo;
		    Mh_nuevo = Mh_viejo;
		}



		se_parece_a = exp(-1*radio);
		

		RADIO[i] = radio;	
		VELOCIDAD[i] = velocidad;	
		SE_PARECE_A[i] = se_parece_a;

	}

	 velocidad_2[i]= pow

((((Mb)**(1/2))*radio[i])/((radio[i]+bb**2)**(3/4)))+((((Md)**(1/2))*radio[i])/(((radio[i])**2 + (bd +ad)**2)**(3/4)))+(((Mh)**(1/2))/((((radio[i])**2) + ah**2)**(1/4)))

	

	/*Guardando los valores en un txt e imprimiendo en la consola*/
	
	FILE *modelo;
	modelo = fopen("Resultados_hw5.txt", "w");
	for(i=0; i<n; i++){
        	fprintf(modelo, "%f %f %f \n", Mb, Md, Mh);
	}

	printf("Mb = %f\n Md = %f\n Mh = %f\n", Mb, Md, Mh);

return 0;

}
