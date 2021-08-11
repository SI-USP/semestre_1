# include <stdio.h>

int main () {
	int valor, valores[] = {50, 20, 5, 1}, notas[] = {0, 0, 0, 0}, i = 0;
	printf ("Este programa calcula o número mínimo de cédulas necessário para satisfazer um determinado valor em Bits (B$), considerando cédulas de B$ 50,00, B$ 20,00, B$ 5,00 e B$ 1,00\n");
	printf ("Digite um valor inteiro, positivo e não nulo: ");

	if (scanf ("%d", &valor) == 0 || valor <= 0) {
		printf("Valor inválido.\n");
		return 1;
	}

	while (valor) {
		if (valor >= valores[i]) {
			valor -= valores[i];
			notas[i]++;
		}
		else
			i++;
	}

	for (i = 0; i < 4; i++) {
		if (notas[i] > 1)
			printf ("%d notas de B$ %.2f\n", notas[i], (float) valores[i]);
		else if (notas[i] == 1)
			printf ("1 nota de B$ %.2f\n", (float) valores[i]);		
	}
	return 0;
}
