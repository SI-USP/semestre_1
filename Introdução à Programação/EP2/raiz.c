/* Autor: Guilherme de Abreu Barreto, nUSP: 12543033 */
# include <stdio.h>
# define N "\033[1m""n""\033[22m"
# define EPSILON "\033[1m""ε""\033[22m"

int main() {
	int i = 0;
	double n, epsilon, raiz, difabs = 0, limsup, liminf;

	printf("Este programa calcula a raiz quadrada de "N" com uma margem de erro menor que "EPSILON", sendo ambos números positivos e o último não nulo.\n");
	printf("\nDigite, separados por espaco, valores para "N" e "EPSILON", respectivamente: ");
	if (!scanf("%lf %lf", &n, &epsilon) || n < 0 || epsilon <= 0) {
		printf("Valor inválido detectado.\n");
		return 1;
	}
	raiz = n;

	if (n != 0 && n != 1) {
		limsup = (n > 1) ? n : 1;
		liminf = (n > 1) ? 1 : n;

		do {
			i++;
			raiz = (limsup - liminf) / 2 + liminf;
			difabs = raiz * raiz - n;
			if (difabs < 0)
				difabs = -difabs;
			if (raiz * raiz > n)
				limsup = raiz;
			else
				liminf = raiz;
		} while (difabs > epsilon);
	}

	printf ("\nNúmero de iteracoes: %d\n", i);
	printf ("Diferença absoluta: %.10f\n", difabs);
	printf ("Raiz quadrada: %.10f\n", raiz);
	return 0;
}
