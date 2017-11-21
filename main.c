/*
	Exercício:
	Elabore um programa em C que armazene em arquivo binário os dados dos
	funcionários da empresa Lava Autos.
 	Este programa deve permitir ao usuário:

		-> pesquisar, por nome, se um funcionário está cadastrado; (implementado! MAS VOCÊ VAI MELHORÁ-LO :) )
		-> excluir o registro de um funcionário; (implementado, mas vamos pensar! :) )
		-> excluir o arquivo fisicamente. (VOCÊ VAI IMPLEMENTAR! :) )
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"


int main(int argc, char const *argv[]) {
  int opcaoMenu, resp, pos;
	// Laço que mantém o programa em execução, com opções de menu para o usuário.
	do{
		// Imprime o menu na tela e lê a opção escolhida pelo usuário.
		opcaoMenu = menu();

		// Chama a função de acordo com a opção digitada pelo usuário.
		switch(opcaoMenu){
			// Cadastra um funcionário.
			case 1:
        backupSeguranca();
				resp = cadastraFunc();

				// Verifica se o arquivo foi aberto corretamente.
				if(resp){
					printf("\n\tCadastro realizado com sucesso!!!\n\n");
				}
				else{
					printf("\n\tErro ao abrir o arquivo! Verifique as configuracoes do arquivo!\n\n");
				}
			break;

			// Altera dados de um funcionário.
			case 2:
        backupSeguranca();
				pos = pesquisaFunc();
				// Verifica se o arquivo foi aberto corretamente.
				if (pos >= 0){
					alteraFunc(pos);
					printf("\n\tO registro foi alterado com sucesso!\n\n");
				}
				else if(pos == -1){
					printf("\n\tNao foi encontrado o funcionario no arquivo!\n\n");
				}
				else{
					printf("\n\tErro ao abrir o arquivo! Verifique as configuracoes do arquivo!\n\n");
				}
			break;

			// Exclui dados de um funcionário.
			case 3:
				backupSeguranca();
				pos = pesquisaFunc();
				// Verifica se o arquivo foi aberto corretamente.
				if (pos >= 0){
					consultaFunc(pos);
					excluiFunc(pos);
					printf("\n\tO registro foi excluido com sucesso!\n\n");
				}
				else if(pos == -1){
					printf("\n\tNao foi encontrado o funcionario no arquivo!\n\n");
				}
				else{
					printf("\n\tErro ao abrir o arquivo! Verifique as configuracoes do arquivo!\n\n");
				}
			break;

			// Pesquisa dados de um funcionário.
			case 4:
				pos = pesquisaFunc();
				// Verifica se o arquivo foi aberto corretamente.
				if (pos >= 0){
					consultaFunc(pos);
				}
				else if(pos == -1){
					printf("\n\tNao foi encontrado o funcionario no arquivo!\n\n");
				}
				else{
					printf("\n\tErro ao abrir o arquivo! Verifique as configuracoes do arquivo!\n\n");
				}
			break;

			// Imprime todos os registros do arquivo.
			case 5:
				resp = imprimeFunc();

				// Verifica se o arquivo foi aberto corretamente.
				if(resp){
					printf("\n\tImpressao realizada com sucesso!!!\n\n");
				}
				else{
					printf("\n\tErro ao abrir o arquivo! Verifique as configuracoes do arquivo!\n\n");
				}
			break;

			// Apaga fisicamente o arquivo.
			case 6:
        backupSeguranca();
				printf("\n\tEm desenvolvimento....  Voce vai desenvolver! :-)\n\n");
			break;

			default:
				printf("\n\tOpcao invalida!\n\n");
		}
		printf("Pressione Enter para continuar...\n");
    getchar();
		system("clear||cls");

	}while(opcaoMenu != 0);
	return 0;
}
