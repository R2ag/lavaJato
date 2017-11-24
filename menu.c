#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"
#include "autenticacao.h"

int menu(){
	int op;
	printf("\n\tMenu de Opcoes Sistema Lava Autos");
	printf("\n\t\t1 - Usuarios");
	printf("\n\t\t2 - Funcionarios");
	printf("\n\tDigite a opcao desejada: ");
	scanf("%d", &op);

	return op;
}

int menu3(){
	int opcao;

	printf("\n\tMenu de Opcoes Sistema Lava Autos - Funcionarios");
	printf("\n\t\t1 - Cadastrar Funcionario");
	printf("\n\t\t2 - Alterar Funcionario");
	printf("\n\t\t3 - Pesquisar Funcionario");
	printf("\n\t\t4 - Imprimir Registros de Funcionarios");
	printf("\n\t\t0 - voltar");
	printf("\n\tDigite a opcao desejada: ");
	scanf("%d", &opcao);

	return opcao;
}

int menu2(){
	int opcao;

	printf("\n\tMenu de Opcoes Sistema Lava Autos - Funcionarios");
	printf("\n\t\t1 - Cadastrar Funcionario");
	printf("\n\t\t2 - Alterar Funcionario");
	printf("\n\t\t3 - Pesquisar Funcionario");
	printf("\n\t\t4 - Imprimir Registros de Funcionarios");
	printf("\n\t\t5 - Excluir Funcionario");
	printf("\n\t\t6 - Apagar Registros de Funcionarios");
	printf("\n\t\t0 - voltar");
	printf("\n\tDigite a opcao desejada: ");
	scanf("%d", &opcao);

	return opcao;
}

int menu1(){
	int opcao;

	printf("\n\tMenu de Opcoes Sistema Lava Autos - Usuarios");
	printf("\n\t\t1 - Cadastrar Usuario");
	printf("\n\t\t2 - Alterar Usuario");
	printf("\n\t\t3 - Excluir Usuario");
	printf("\n\t\t4 - Listar Usuarios Cadastrados");
	printf("\n\t\t5 - Resetar Registros de Usuario");
	printf("\n\t\t0 - voltar");
	printf("\n\tDigite a opcao desejada: ");
	scanf("%d", &opcao);

	return opcao;

}



int telaLogin(){
	usuario bufferEntrada;
	int sucesso;

	do {
		printf("\n\tSistema Lava Autos - Login");
		printf("\n\t\tUsuário: ");
		gets(bufferEntrada.login);
		printf("\n\t\tSenha: ");
		gets(bufferEntrada.senha);

		sucesso = entrar(bufferEntrada);

		system("cls||clear");

		if(sucesso > 0){
			return sucesso;
		}

		printf("Usuario e senha incorretos!\nPressione Enter para continuar...");
		getchar();

	}while(sucesso < 0);


}
