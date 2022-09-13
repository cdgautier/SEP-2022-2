#include <stdio.h>
#include <stdlib.h>

// header
void suma_total(double *p_reg[], double *p_suma, int m, int n);
void suma_por_auto(double *p_reg[], double *p_con[], int m, int n);

int main(){
	
	int i, j, m;
	int counter;
	int column = 7;
	double registro_autos[10][7];
	double consumo_autos[10][2];
	double *ptr_1[10];
	double *ptr_2[10];
	double suma = 0.0;
	
	for (m = 0; m < 10; ++m)
	{
	    ptr_1[m] = &registro_autos[m][0];
	    ptr_2[m] = &consumo_autos[m][0];
	}
    printf("\n");
	printf(" Ingrese la cantidad de vehiculos para los que desea \n");
	printf(" calcular la energia y consumo promedio en kWh: ");
	do{
		//scanf("%d", &counter);
		if (scanf("%d", &counter) == 1) {
			if (counter < 1 || counter > 10){
			printf("\n Cantidad invalida. Debe estar entre 1 y 10\n");
			printf(" Intenta otra vez: \n");
			}
		}
		else{
			perror(" \nError - input invalido");
			abort();
		} 
	}while(counter < 1 || counter > 10);
	

	for (i = 0; i < counter; ++i)
	{
	    printf("\n");
		printf(" Ingrese los consumos del automovil %d en kWh para los 7 dias \n\n" \
		        , i + 1);
		for (j = 0; j < column; ++j)
		{
			printf(" dia %d: ", j + 1);
			do{
        		//scanf("%lf", &registro_autos[i][j]);
        		if (scanf("%lf", &registro_autos[i][j]) == 1) {
        			if (registro_autos[i][j] < 0 ){
        			printf("\n Cantidad invalida. Consumo debe ser positivo\n");
        			printf(" Intenta otra vez: \n");
        			}
        		}
        		else{
        			perror(" \nError - input invalido");
        			abort();
        		}
        	}while(registro_autos[i][j] < 0 );
		}
	}

	printf("\n\n");
	printf(" - - - - consumos diarios en kWh - - - - ");
	printf("\n\n");
	for (i = 0; i < counter; ++i)
	{	
		printf(" * automovil %d: ", i + 1);
		for (j = 0; j < column; ++j)
		{
			printf(" %.2f ", registro_autos[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf(" - - - - - - - - - - - - - - - - - - - - ");


	suma_total(ptr_1, &suma, counter, column);
	printf("\n\n");
	printf(" El resultado del calculo es: %.2f kWh", suma);
	suma_por_auto(ptr_1, ptr_2, counter, column);

	return 0;
}

void suma_total(double *p_reg[], double *p_suma, int m, int n)
{
	int i, j;
	double resultado = 0.0;
	
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			resultado += *(*(p_reg+i)+j);
		}
	}
	*p_suma = resultado;
}

void suma_por_auto(double *p_reg[], double *p_con[], int m, int n)
{
	int i, j;
	double tot_auto;
	double prom_auto;

	printf("\n\n");
	printf(" - - consumo semanal por automovil en kWh - - ");
	printf("\n\n");
	for (int i = 0; i < m; ++i)
	{
		tot_auto = 0.0;
		prom_auto = 0.0;
		for (int j = 0; j < n; ++j)
		{
			tot_auto += *(*(p_reg+i)+j);
		}
		prom_auto = tot_auto/n;
		p_con[i][0] = tot_auto;
		p_con[i][1] = prom_auto;
		printf(" - automovil %d - ", i + 1);
		printf(" total: %.2f, promedio: %.3f \n" \
		        , p_con[i][0], p_con[i][1]);
	}
}