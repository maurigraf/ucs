#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char id_twitter[25];
	char usuario[40];
	char mensagem[300];
	char data[10];
	char hashtag[50];
} registro;

//char busca_binaria_string(char x[], registro v[][30], int n);

int main(void) {
	setbuf(stdout, NULL);
	registro conteudo[4000];
	FILE *dados, *dadosorg, *arqind, *arqindhash;
	int i = 0, j = 0, cont = 0, cont1 = 0, contpont = 0;
	char palavrapesquisada[30];
	dados = fopen(
			"E:\\UCS Trab\\Sem 4 - Alg e Est de Dados 2\\Arquivo 5 regs.txt",
			"rb");
	dadosorg =
			fopen(
					"E:\\UCS Trab\\Sem 4 - Alg e Est de Dados 2\\Dados Organizadossss.txt",
					"wb");
	arqind = fopen("E:\\UCS Trab\\Sem 4 - Alg e Est de Dados 2\\Arqind.txt",
			"wb");

	arqindhash = fopen(
			"E:\\UCS Trab\\Sem 4 - Alg e Est de Dados 2\\Arqindhash.txt", "wb");

	if (dados == NULL)
		exit(0);
	fprintf(dadosorg, "IdTwitter; Mensagem; Usuário; Data; Hashtag;\n");
	while (i < 4000) {
		while (contpont < 5) {
			j = 0;
			while (contpont == 0) {
				if (contpont == 0) {
					while (cont < 5) {
						if (fgetc(dados) == '/')
							cont++;
					}
					conteudo[i].id_twitter[j] = fgetc(dados);
					if (conteudo[i].id_twitter[j] == ';') {
						//if (conteudo[i].id_twitter[j + 1] == '\0') {
						while (j < 24) {
							conteudo[i].id_twitter[j + 1] = ' ';
							j++;
						}
						//}
						fprintf(arqind, "%s | %d\n", conteudo[i].id_twitter,
								*conteudo[i].id_twitter);
						contpont++;
					}
					j++;
				}
			}
			j = 0;
			while (contpont == 1) {
				if (contpont == 1) {
					conteudo[i].mensagem[j] = fgetc(dados);
					if (conteudo[i].mensagem[j] == ';') {
						//if (conteudo[i].mensagem[j + 1] == '\0') {
						while (j < 299) {
							conteudo[i].mensagem[j + 1] = ' ';
							j++;
						}
						//}
						contpont++;
					}
					j++;
				}
			}
			j = 0;
			while (contpont == 2) {
				if (contpont == 2) {
					while (cont1 < 3) {
						if (fgetc(dados) == '/')
							cont1++;
					}
					conteudo[i].usuario[j] = fgetc(dados);
					if (conteudo[i].usuario[j] == ';') {
						//if (conteudo[i].usuario[j + 1] == '\0') {
						while (j < 39) {
							conteudo[i].usuario[j + 1] = ' ';
							j++;
						}
						//}
						contpont++;
					}
					j++;
				}
			}
			j = 0;
			while (contpont == 3) {
				if (contpont == 3) {
					conteudo[i].data[j] = fgetc(dados);
					if (conteudo[i].data[j] == ';') {
						//if (conteudo[i].data[j + 1] == '\0') {
						while (j < 9) {
							conteudo[i].data[j + 1] = ' ';
							j++;
						}
						//}
						contpont++;
					}
					j++;
				}
			}
			j = 0;
			while (contpont == 4) {
				if (contpont == 4) {
					conteudo[i].hashtag[j] = fgetc(dados);
					if (conteudo[i].hashtag[j] == ';') {
						//if (conteudo[i].hashtag[j + 1] == '\0') {
						while (j < 49) {
							conteudo[i].hashtag[j + 1] = ' ';
							j++;
						}
						//}
						fprintf(arqindhash, "%s | %d\n", conteudo[i].hashtag,
								*conteudo[i].hashtag);
						contpont++;
					}
					j++;
				}
			}

		}
		fprintf(dadosorg, "%s %s %s %s %s\n\n", conteudo[i].id_twitter,
				conteudo[i].mensagem, conteudo[i].usuario, conteudo[i].data,
				conteudo[i].hashtag);
		i++;
		contpont = 0;
		cont = 0;
		cont1 = 0;
	}

	fclose(dados);
	fclose(dadosorg);

	//printf("Digite um IdTwitter a ser pesquisado:");
	//gets(palavrapesquisada);

	//busca_binaria_string(palavrapesquisada, conteudo, 1000);
	return EXIT_SUCCESS;
}

/*char busca_binaria_string(char x[], registro v[][30], int n) {
	int in, m, f;

	in = 0;
	f = n - 1;

	while (in <= f) {
		m = (in + f) / 2;
		if (stricmp(x, v[m].id_twitter) == 0) {
			printf("%s", x);
			// consultar dados a partir da pesquisa binária
			printf("%s %s %s %s", x->mensagem, x->usuario, x->data, x->hashtag);
			return x;
		} else if (stricmp(x, v[m].id_twitter) < 0)
			f = m - 1;
		else
			in = m + 1;

	}
}*/

