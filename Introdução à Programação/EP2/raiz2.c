/* Autor: Guilherme de Abreu Barreto, nUSP: 12543033 */
# include <stdio.h>
# define N "\033[1m""n""\033[22m"
# define EPSILON "\033[1m""ε""\033[22m"

double average (double a, double b) {
	return (a + b) / 2;
}

double absoluteValue (double n) {
	return (n < 0) ? -n : n;
}

void displayRoot (double n, double epsilon) {
	int i;
	double root = n, delta, suplim, inflim;

	delta = i = 0;
	if (n != 0 && n != 1) {
		if (n > 1) {
			suplim = n;
			inflim = 1;
		}
		else {
			suplim = 1;
			inflim = n;
		}
		do {
			i++;
			root = average(suplim, inflim);
			delta = absoluteValue(root * root - n);
			if (root * root > n)
				suplim = root;
			else
				inflim = root;			
		} while (delta > epsilon);
	}
	printf ("\nNúmero de iteracoes: %d\n", i);
	printf ("Diferença absoluta: %.10f\n", delta);
	printf ("Raiz quadrada: %.10f\n", root);
}

int main() {
	double n, epsilon;

	printf("Este programa calcula a raiz quadrada de "N" com uma margem de erro menor que "EPSILON", sendo ambos números positivos e o último não nulo.\n");
	printf("\nDigite, separados por espaco, valores para "N" e "EPSILON", respectivamente: ");
	if (!scanf("%lf %lf", &n, &epsilon) || n < 0 || epsilon <= 0) {
		printf("Valor inválido detectado.\n");
		return 1;
	}
	displayRoot (n, epsilon);
	return 0;
}
