/* Autor: Guilherme de Abreu Barreto, nUSP: 12543033 */
# include <stdio.h>
# include <math.h>

int main () {
	int i;
	float lado[3], hipotenusa, cateto[2], p;
	
	printf ("Este programa descreve um triângulo com base nas medidas dos seus lados. Digite, separadas por espaço, três medidas positivas e não nulas:\n");
	if (!scanf("%f %f %f", &lado[0], &lado[1], &lado[2]) || lado[0] <= 0 || lado[1] <= 0 || lado[2] <= 0) {
			printf("Valor inválido detectado.\n");
			return 1;
	}

	printf("\nMedidas dos ângulos formam um triângulo ");
	if (lado [0] < fabs(lado[1] - lado [2]) || lado[0] > lado[1] + lado[2]) {
		printf("INVALIDO\n");
		return 1;
	}
	printf("VALIDO\n");

	printf("Classificação em função dos lados: ");
	if (lado[0] == lado[1] && lado[1] == lado[2])
		printf("EQUILATERO\n");
	else if (lado[0] == lado[1] || lado[1] == lado[2])
		printf("ISOSCELES\n");
	else
		printf("ESCALENO\n");

	printf("Classificação em função dos angulos: ");
	hipotenusa = lado[0];
	for (i = 1; i < 3; i++) {
		if (lado[i] > hipotenusa) {
			cateto[i - 1] = hipotenusa;
			hipotenusa = lado[i];
		}
		else
			cateto[i - 1] = lado[i];
	}
	if (pow(hipotenusa,2) < pow(cateto[0],2) + pow(cateto[1],2))
		printf("AGUDO\n");
	else if (pow(hipotenusa,2) == pow(cateto[0],2) + pow(cateto[1],2))
		printf("RETO\n");
	else
		printf("OBTUSO\n");

	p = (lado[0] + lado[1] + lado[2]) / 2;
	printf("Área do triângulo: %g\n", sqrt(p * (p - lado[0]) * (p - lado[1]) * (p - lado[2])));
	return 0;
}
