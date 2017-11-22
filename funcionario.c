
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"


int cadastraFunc(){

	// Declaração da variável do tipo registro.
	dados func;

	// Ponteiro para o arquivo.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "a+b";
	char nomeArquivo[] = "funcionarios.dat"
	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Verifica se o arquivo foi aberto corretamente. Caso negativo, sai da função.
	if(fp == NULL){
		return 0; // Operação de abertura/criação do arquivo NÃO foi realizada com sucesso.
	}

	// Faz a leitura dos dados a serem cadastrados.
	leDadosFunc(&func);

	// Grava as informações no arquivo.
	fwrite(&func, sizeof(func), 1, fp);

	// Fecha o arquivo.
	fclose(fp);

	// Operação realizada com sucesso.
	return 1;
}

void leDadosFunc(dados *funcLe){
	// Lendo informações de um funcionário.
	printf("\n\tDigite a matricula: ");
	scanf("%d", &funcLe->matricula);

	getchar();
	printf("\n\tDigite o nome: ");
	gets(funcLe->nome);

	printf("\n\tDigite a primeira letra do estado civil: ");
	scanf("%c", &funcLe->estadoCivil);

	printf("\n\tDigite o salario: ");
	scanf("%f", &funcLe->salario);

	// Ativa o status do registro
	funcLe->status = 1;
}

// Função que imprime os dados de todos os funcionários cadastrados.
int imprimeFunc(){
	// Variável que conta o número de registros.
	int qtdeReg = 0;

	// Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
	dados func;

	// Ponteiro para o arquivo.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "rb";
	char nomeArquivo[] = "funcionarios.dat"

	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Verifica se o arquivo foi aberto corretamente. Caso negativo, sai da função.
	if(fp == NULL){
		return 0; // Operação de abertura do arquivo NÃO foi realizada com sucesso.
	}


	while(fread(&func, sizeof(func), 1, fp)){
		if(func.status == 1){
			// Imprime as informações dos registros ativos no sistema.
			printf("\n\n\t###### Dados do %do funcionario ######", ++qtdeReg);
			printf("\n\t\tMatricula: %d", func.matricula);
			printf("\n\t\tNome: %s", func.nome);
			printf("\n\t\tEstado civil: %c", func.estadoCivil);
			printf("\n\t\tSalario: %0.2f\n\n", func.salario);
		}

	}

	// Fecha o arquivo após as operações.
	fclose(fp);

	// Operação realizada com sucesso.
	return 1;
}

int pesquisaFunc(){
	// Variável auxiliar que indica se o registro procurado existe no arquivo.
	int achou = -1;

	// Variável que armazena a posição do registro procurado dentro do arquivo.
	int posRegFunc = 0;

	// Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
	dados func;

	// Variável auxiliar que recebe o nome a ser pesquisado no arquivo.
	char nomeAux[51];

	// Ponteiro para o arquivo físico.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "rb";
	char nomeArquivo[] = "funcionarios.dat"
	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Verifica se o arquivo foi aberto corretamente. Caso negativo, sai da função.
	if(fp == NULL){
		return 0; // Operação de abertura do arquivo NÃO foi realizada com sucesso.
	}

	// Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
	getchar();
	printf("\n\tDigite o nome do funcionario a ser pesquisado: ");
	gets(nomeAux);


	// Laço de leitura do arquivo.
	while(fread(&func, sizeof(func), 1, fp) && (achou == -1)){
		if( (strcmp(func.nome, nomeAux) == 0) && (func.status == 1) ){
			achou = 1;
		}

		if(achou == -1){
			posRegFunc++;
		}
	}

	if(achou == -1){
		return -1;
	}

	// Fecha o arquivo após as operações.
	fclose(fp);

	// Retorna a posição do registro procurado no arquivo.
	return posRegFunc;
}

void consultaFunc(int posRegFunc){
	// Variável que conta o número de registros.
	int qtdeReg = 0;

	// Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
	dados func;

	// Ponteiro para o arquivo físico.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "r+b";
	char nomeArquivo[] = "funcionarios.dat"

	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Acessa o registro específico, com base na posição recebida pela função.
	fseek(fp, posRegFunc * sizeof(func), SEEK_SET);

	// Lê as informações do arquivo, para inicializar o laço.
	fread(&func, sizeof(func), 1, fp);

	// Imprime as informações do registro pesquisado.
	printf("\n\t###### Dados do funcionario pesquisado ######");
	printf("\n\t\tMatricula: %d", func.matricula);
	printf("\n\t\tNome: %s", func.nome);
	printf("\n\t\tEstado civil: %c", func.estadoCivil);
	printf("\n\t\tSalario: %0.2f\n\n", func.salario);

	// Fecha o arquivo após as operações.
	fclose(fp);
}

// Função que permite alterar os dados de um registro do arquivo.
void alteraFunc(int posRegFunc){
	// Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
	dados func;

	// Ponteiro para o arquivo físico.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "r+b";
	char nomeArquivo[] = "funcionarios.dat"

	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Acessa o registro específico, com base na posição recebida pela função.
	fseek(fp, posRegFunc * sizeof(func), SEEK_SET);

	// Lê as informações do registro a ser alterado.
	fread(&func, sizeof(func), 1, fp);

	// Função auxiliar que realiza as alterações no registro.
	confirmaAlteracoes(&func);

	// Acessa o registro específico, para atualizá-lo.
	fseek(fp, posRegFunc * sizeof(func), SEEK_SET);

	// Grava as informações do registro após as alterações.
	fwrite(&func, sizeof(func), 1, fp);

	// Fecha o arquivo após as operações.
	fclose(fp);
}

// Função que lê do usuários os campos a serem alterados.
void confirmaAlteracoes(dados *func){
	// Variável auxiliar para confirmar alteração de cada campo.
	char op;

	// Imprime as informações do registro pesquisado.
	printf("\n\t###### Dados do funcionario a serem alterados ######");
	printf("\n\tMatricula atual: %d", func->matricula);
	printf("\n\tDeseja alterar? (S=Sim/N=Nao): ");
	scanf("%c", &op);
	if((op == 's') || (op == 'S')){
		printf("\tDigite a nova matricula: ");
		scanf("%d", &func->matricula); // Altera a matrícula do funcionário.
	}

	getchar(); // Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
	printf("\n\tNome atual: %s", func->nome);
	printf("\n\tDeseja alterar? (S=Sim/N=Nao): ");
	getchar(); // Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
	scanf("%c", &op);
	if((op == 's') || (op == 'S')){
		getchar(); // Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
		printf("\tDigite o novo nome: ");
		gets(func->nome); // Altera o nome do funcionário.
	}

	printf("\n\tEstado civil atual: %c", func->estadoCivil);
	printf("\n\tDeseja alterar? (S=Sim/N=Nao): ");
	getchar(); // Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
	scanf("%c", &op);
	if((op == 's') || (op == 'S')){
		getchar(); // Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
		printf("\tDigite o novo estado civil: ");
		scanf("%c", &func->estadoCivil); // Altera o estado civil do funcionário.
	}

	printf("\n\tSalario atual: %0.2f", func->salario);
	printf("\n\tDeseja alterar? (S=Sim/N=Nao): ");
	getchar(); // Limpa o buffer do teclado para evitar "saltos" na leitura de dados.
	scanf("%c", &op);
	if((op == 's') || (op == 'S')){
		printf("\tDigite o novo salario: ");
		scanf("%f", &func->salario); // Altera o salário do funcionário.
	}
}

// Função que altera o valor do campo status para zero ("exclui")
void excluiFunc(int posRegFunc){
	// Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
	dados func;

	// Ponteiro para o arquivo físico.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "r+b";
	char nomeArquivo[] = "funcionarios.dat"

	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Acessa o registro específico, com base na posição recebida pela função.
	fseek(fp, posRegFunc * sizeof(func), SEEK_SET);

	// Lê as informações do registro a ser alterado.
	fread(&func, sizeof(func), 1, fp);

	// Altera o campo status para zero, "excluindo" o registro.
	func.status = 0;

	// Acessa o registro específico, para atualizá-lo.
	fseek(fp, posRegFunc * sizeof(func), SEEK_SET);

	// Grava as informações do registro após as alterações.
	fwrite(&func, sizeof(func), 1, fp);

	// Fecha o arquivo após as operações.
	fclose(fp);
}
