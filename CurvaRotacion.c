#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	/*definiendo las constantes del enunciado*/
	double bb=0.2497;
	double bd=5.16;
	double ad=0.3105;
	double ah=64.3;
	double G=1;
	
	/*el numero para saber el tamaño del puntero y creandolos, definiendo las variables*/
	int i = 300;
	int n = 300; 
	int contador = 300;
	int numit = 100000;
	double factor = 0.5;

	double radio, velocidad, se_parece_a;
	double Mb_viejo, Mb_nuevo, Md_viejo, Md_nuevo, Mh_viejo, Mh_nuevo, alpha, beta;

	double *RADIO = malloc(n*sizeof(double));
    	double *VELOCIDAD = malloc(n*sizeof(double));
	
	/*Leyendo el archivo*/
	/*Leyendo las 2 columnas*/	
	/*Recorriendo cada elemento del  archivo y guardandolo en las variables, %lf indica que es un numero decimal flotante*/
	FILE*archivo = fopen("RadialVelocities.dat", "r");
	//while (!feof(archivo))
	for(contador=0; contador<n; contador++){
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
	beta = drand48();


	double minimo, valor;

	minimo = (((pow(Mb_viejo,1.0/2))*RADIO[0])/(pow(pow(RADIO[0],2)+pow(bb,2),3.0/4.0))) + (((pow(Md_viejo, 1.0/2.0))*RADIO[0])/(pow(pow(RADIO[0],2)+pow(bd+ad,2),3.0/4.0))) + ((pow(Mh_viejo, 1.0/2.0))/(pow(pow(RADIO[0],2)+pow(ah,2),1.0/4.0)));
	
	for(i=1; i<n; i++){
		valor = (((pow(Mb_viejo,1.0/2))*RADIO[i])/(pow(pow(RADIO[i],2)+pow(bb,2),3.0/4.0))) + (((pow(Md_viejo, 1.0/2.0))*RADIO[i])/(pow(pow(RADIO[i],2)+pow(bd+ad,2),3.0/4.0))) + ((pow(Mh_viejo, 1.0/2.0))/(pow(pow(RADIO[i],2)+pow(ah,2),1.0/4.0)));

		if(valor<minimo) {

			minimo=valor;
		}
	} 

	for(i=0; i<numit; i++) {
	
		SE_PARECE_A[i] = pow(exp(-1*RADIO[i]), 1.0/4.0);

		Mb_nuevo = Mb_viejo + (2.0*drand48() - 1.0)*factor;	
		Md_nuevo = Md_viejo + (2.0*drand48() - 1.0)*factor;
		Mh_nuevo = Mh_viejo + (2.0*drand48() - 1.0)*factor;

		alpha=SE_PARECE_A[i]/valor;

		if(alpha > 1) {

		    alpha = 1;
		}

		if(beta < alpha) {

		    Mb_nuevo = Mb_viejo;
		    Md_nuevo = Md_viejo;
		    Mh_nuevo = Mh_viejo;
		}
	}

	 	

	/*Guardando los valores en un txt e imprimiendo en la consola*/
	
	FILE *modelo;
	modelo = fopen("Resultados_hw5.txt", "w");
	for(i=0; i<n; i++){
        	fprintf(modelo, "%f %f %f \n", Mb_viejo, Md_viejo, Mh_viejo);
	}

	printf("Mb = %f\n Md = %f\n Mh = %f\n", Mb_viejo, Md_viejo, Mh_viejo);

return 0;

}
