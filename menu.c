
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"

int menu(){
	int opcao;

	printf("\n\tMenu de Opcoes Sistema Lava Autos - Funcionarios");
	printf("\n\t\t1 - Cadastrar");
	printf("\n\t\t2 - Alterar");
	printf("\n\t\t3 - Excluir");
	printf("\n\t\t4 - Pesquisar");
	printf("\n\t\t5 - Imprimir Arquivo");
	printf("\n\t\t6 - Apagar Arquivo");
	printf("\n\t\t0 - Sair");
	printf("\n\tDigite a opcao desejada: ");
	scanf("%d", &opcao);

	return opcao;
}
