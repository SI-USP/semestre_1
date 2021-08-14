/*////////////////////////////////////////////////////////////
//                                                          //
//  Exercicio Programa 3 de Desenho de Primativas Graficas  //
//  Guilherme de Abreu - nUSP 12543033                      //
//  Marcus Imazava Gianini - nUSP 12717669                  //
//                                                          //
////////////////////////////////////////////////////////////*/

/* Bibliotecas e definições */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define BRANCO 255
#define PRETO 0

/* Estruturas */
typedef struct {
	int x,y;
} coordenada;

/* Funções de desenho */
void libera_imagem(int ** imagem, int a){
	int lin;

	/* liberação de cada linha da matriz (cada linha é um vetor de int) */
	for(lin = 0; lin < a; lin++)
		free(imagem[lin]);
	free(imagem);
}

void reta (coordenada p1, coordenada p2, int cor, int ** imagem) {
	int dx, dy, p;

	/* Variação dos valores x e y das coordenadas de saida e chegada (delta x e delta y) */
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	/* p = parâmetro de decisão (para incrementar ou não o valor de x ou y em uma reta com declive), conforme a definição do algoritmo de bresenham */
	p = (abs(dx) >= abs(dy)) ? 2 * abs(dy) - abs(dx) : 2 * abs(dx) - abs(dy);

	imagem[p1.y][p1.x] = cor;

	while(p1.x != p2.x || p1.y != p2.y){

		/* Linha com coeficiente angular menor ou igual a 1: x sempre se altera */
		if (abs(dx) >= abs(dy))
			dx > 0 ? p1.x++ : p1.x--;

		/* Linha com coeficiente angular maior que 1: x se altera apenas se p >= 0 */
		else if (dx != 0){
			if (p >= 0){
				p -= 2 * abs(dy);
				dx > 0 ? p1.x++ : p1.x--;
			}
			p += 2 * abs(dx);
		}

		/* Linha com coeficiente angular maior ou igual a 1: y sempre se altera */
		if (abs(dy) >= abs(dx))
			dy > 0 ? p1.y++ : p1.y--;

		/* Linha com coeficiente angular menor que 1: y se altera apenas se p >= 0 */
		else if (dy != 0){
			if (p >= 0){
				p -= 2 * abs(dx);
				dy > 0 ? p1.y++ : p1.y--;
			}
			p += 2 * abs(dy);
		}
		imagem[p1.y][p1.x] = cor;
	}
}

void retangulo_contorno (coordenada p1, coordenada p2, int cor, int ** imagem) {

	/* Definição de cantos p3 e p4 adjacentes ao p1 e p2 */
	coordenada p3, p4;
	p3.x = p2.x; p3.y = p1.y;
	p4.x = p1.x; p4.y = p2.y;

	/* Execução das 4 retas de contorno com base nos 4 pontos */
	reta (p1, p3, cor, imagem);
	reta (p3, p2, cor, imagem);
	reta (p2, p4, cor, imagem);
	reta (p4, p1, cor, imagem);
}

void retangulo_preenchido (coordenada p1, coordenada p2, int cor, int ** imagem){

	/* Definição de ponto adjacente ao p1 para construção de linhas de preenchimento */
	int dy = p2.y - p1.y;
	coordenada p3;
	p3.x = p2.x;
	p3.y = p1.y;

	/* Execução de todas as retas horizontais para preenchimento da imagem */
	reta(p1, p3, cor, imagem);
	while (p1.y != p2.y) {
		if (dy < 0) {
			p1.y--;
			p3.y--;
		}
		else {
			p1.y++;
			p3.y++;
		}
		reta(p1, p3, cor, imagem);
	}
}

void clona (coordenada p1, coordenada p2, coordenada p3, int ** imagem, int altura, int largura){
	int dx, dy, a, l;

	/* Definição das dimensoes da área a ser clonada */
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	/* Clonagem do retangulo (p1,p2) para o retangulo que se inicia em p3 */
	for (a = 0; a <= dy; a++){
		if (p3.y + a >= altura) /* Evitar sair da área da imagem */
			break;
		for (l = 0; l <= dx; l++){
			if (p3.x + l >= largura) /* Evitar sair da área da imagem */
				break;
			imagem[p3.y + a][p3.x + l] = imagem[p1.y + a][p1.x + l];
		}
	}
}

void clona_inverte_cor (coordenada p1, coordenada p2, coordenada p3, int ** imagem, int altura, int largura){
	int dx, dy, a, l;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	for (a = 0; a <= dy; a++){
		if (p3.y + a >= altura)
			break;
		for (l = 0; l <= dx; l++){
			if (p3.x + l >= largura)
				break;
			imagem[p3.y + a][p3.x + l] = abs(BRANCO - imagem[p1.y + a][p1.x + l]); /* Clonagem do retangulo com cor complementar ao branco */
		}
	}
}

void clona_espelha_horizontal (coordenada p1, coordenada p2, coordenada p3, int ** imagem, int altura, int largura){
	int dx, dy, a, l;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	for (a = 0; a <= dy; a++){
		if (p3.y + a >= altura)
			break;
		for (l = 0; l <= dx; l++){
			if (p3.x + l >= largura)
				break;
			imagem[p3.y + a][p3.x + dx - l] = imagem[p1.y + a][p1.x + l]; /* Clonagem do retangulo no eixo horizontal */
		}
	}
}

void clona_espelha_vertical (coordenada p1, coordenada p2, coordenada p3, int ** imagem, int altura, int largura){
	int dx, dy, a, l;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	for (a = 0; a <= dy; a++){
		if (p3.y + a >= altura)
			break;
		for (l = 0; l <= dx; l++){
			if (p3.x + l >= largura)
				break;
			imagem[p3.y + dy - a][p3.x + l] = imagem[p1.y + a][p1.x + l]; /* Clonagem do retangulo no eixo vertical */
		}
	}
}

/* Função principal */
int main() {
	int largura, altura, l, a, cor, ** imagem;
	char operacao[32], nome_do_arquivo[256];
	coordenada p1, p2, p3;
	FILE * saida;

	/* Leitura do input */
	if (!scanf("%s %d %d", nome_do_arquivo, &largura, &altura))
		return 1;

	/* Criar no atual diretório um arquivo para escrita (w = write). */
	saida = fopen (nome_do_arquivo, "w");
	if (!saida){
		printf("Falha ao criar o arquivo. Verifique se voce possui permissão para fazer alterações no seu diretorio de trabalho.");
		return 1;
	}

	/* Descrever as propriedades da imagem: largura, altura, valor maximo da escala de cor. */
	fprintf(saida, "P2\n%d %d\n%d\n", largura, altura, BRANCO);

	/* Alocação dinamica da memória para dimencionar a matriz da imagem. */
	imagem = (int **) malloc (altura * sizeof(int *));
	for (a = 0; a < altura; a++)
		imagem[a] = (int *) malloc (largura * sizeof(int));

	/* Preencher a matriz da imagem com a cor preta. */
	for (a = 0; a < altura; a++)
		for (l = 0; l < largura; l++)
			imagem [a][l] = PRETO;

	/* Leitura e execução das operações de desenho */
	while (scanf("%s", operacao) == 1 && strcmp(operacao, "FIM") != 0){

		/* Verifica se ha erro no scan de variaveis */
		if(!scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y)
		|| p1.x < 0 || p1.x >= largura || p1.y < 0 || p1.y >= altura
		|| p2.x < 0 || p2.x >= largura || p2.y < 0 || p2.y >= largura){
			printf("Detectada coordenada inválida para operação %s\n", operacao);
			return 1;
		}
		if(strstr(operacao, "CLONA")){
			if(!scanf("%d %d", &p3.x, &p3.y)
			|| p3.x < 0 || p3.x >= largura || p3.y < 0 || p3.y >= altura){
				printf("Detectada coordenada inválida para operação %s\n", operacao);
				return 1;
			}
		}
		else if (!scanf("%d", &cor) || cor < PRETO || cor > BRANCO){
			printf("Valor de cor inválido passado para operação %s\n", operacao);
			return 1;
		}

		/* Chamada das funções de desenho */
		if (!strcmp(operacao, "RETA"))
			reta (p1, p2, cor, imagem);
		else if (!strcmp(operacao, "RETANGULO_CONTORNO"))
			retangulo_contorno (p1, p2, cor, imagem);
		else if (!strcmp(operacao, "RETANGULO_PREENCHIDO"))
			retangulo_preenchido (p1, p2, cor, imagem);
		else if (!strcmp(operacao, "CLONA"))
			clona (p1, p2, p3, imagem, altura, largura);
		else if (!strcmp(operacao, "CLONA_INV"))
			clona_inverte_cor (p1, p2, p3, imagem, altura, largura);
		else if (!strcmp(operacao, "CLONA_HOR"))
			clona_espelha_horizontal (p1, p2, p3, imagem, altura, largura);
		else if (!strcmp(operacao, "CLONA_VER"))
			clona_espelha_vertical (p1, p2, p3, imagem, altura, largura);
		else{
			printf("Operação \"%s\" desconhecida", operacao);
			return 1;
		}
	}

	/* Ler a matriz da imagem e descrevê-la no arquivo de saida. */
	for (a = 0; a < altura; a++) {
		for (l = 0; l < largura; l++)
			fprintf(saida, (l == 0 ? "%d" : " %d"), imagem[a][l]);
		fprintf(saida, "\n");
	}

	/* Finalização */
	fclose(saida);
	libera_imagem(imagem, altura);
	return 0;
}
