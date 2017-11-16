#ifndef DADOS_HEADER_
#define DADOS_HEADER_

#include <stdio.h>
#include <stdlib.h>

typedef struct Dados{
	int matricula;
	int status;
	char estadoCivil;
	char nome[51];
	float salario;
}dados;

typedef struct Usuario {
	char login[16];
	char senha[16];
	char tipoUsuario;
}usuario;
#endif
