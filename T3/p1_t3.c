#include <stdio.h>

int main(){

	double failed_batteries[10] = {0.97, 0.4, 0.3, 0.84, 1.2, 0.7, 0.6, 0.9, 0.1, 0.25}; 
	double *pfb;

	pfb = failed_batteries;

	printf("\n baterias en falla (inicio): (");
	for(int i = 0; i < 9; ++i ){
		printf("V%d: %.2f, ", i+1, failed_batteries[i]);
	}
	printf("V10: %.2f) ", failed_batteries[9]);

	printf("\n\n direccion de V1: %p ", pfb);

	printf("\n\n moviendo puntero a V7...");
	pfb += 6;
	printf("\n direccion de V7: %p ", pfb);

	printf("\n\n incrementando V7...");
	*pfb += 3;
	printf("\n valor de V7 incrementado: %.2f ", *pfb);

	printf("\n\n asignando puntero a V8...");
	printf("\n actualizando V8...");
	*(pfb + 1) = 1;
	printf("\n valor de V8 actualizado: %.2f", *(pfb + 1));

	printf("\n\n moviendo puntero a V2...");
	pfb -= 5;
	printf("\n direccion de V2: %p ", pfb);

	printf("\n\n actualizando V2...");
	*pfb = 3.61;
	printf("\n valor de V2 actualizado: %.2f", *pfb);

	printf("\n\n moviendo puntero a V5...");
	pfb += 3;
	printf("\n direccion de V5: %p ", pfb);

	printf("\n\n actualizando V5 a funcionamiento correcto...");
	*pfb = 3.56;
	printf("\n valor de V5 en funcionamiento correcto: %.2f", *pfb);

	printf("\n\n baterias en falla (final): (");
	for(int i = 0; i < 9; ++i ){
		printf("V%d: %.2f, ", i+1, failed_batteries[i]);
	}
	printf("V10: %.2f) ", failed_batteries[9]);

	return 0;
}