#ifndef DADOS_HEADER_
#define DADOS_HEADER_

#include <stdio.h>
#include <stdlib.h>

//Declaração da estrutura de dados referente ao cadastro dos funcionarios
typedef struct Dados{
	int matricula;
	int status;
	char estadoCivil;
	char nome[51];
	float salario;
}dados;

//Declaração da estrutura de dados referente ao cadastro dos usuarios do sistema
typedef struct Usuario {
	char login[16];
	char senha[16];
	int  nivelAcesso;
}usuario;
#endif
