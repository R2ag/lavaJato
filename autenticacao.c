#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"
#include "autenticacao.h"

int entrar(usuario aux){
  // Variável auxiliar que indica se o registro procurado existe no arquivo.
  int achou = -1;


  // Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
  usuario buffer;

    // Ponteiro para o arquivo físico.
  FILE *fp;

  // Define o modo de abertura do arquivo.
  char modo[] = "rb";
  char nomeArquivo[] = "usuarios.dat";

  // Abre o arquivo binário para leitura e gravação.
  fp = openFile(nomeArquivo, modo);

  // Verifica se o arquivo foi aberto corretamente. Caso negativo, sai da função.
  if(fp == NULL){
    return 0; // Operação de abertura do arquivo NÃO foi realizada com sucesso.
  }
  // Laço de leitura do arquivo.
  while(fread(&buffer, sizeof(buffer), 1, fp) && (achou == -1)){
    if( (strcmp(buffer.login, aux.login ) == 0) && (strcmp(buffer.senha, aux.senha)) ){
      achou = 1;
    }
  }

  if(achou == -1){
    return -1;
  }

  // Fecha o arquivo após as operações.
  fclose(fp);

  return buffer.nivelAcesso;
}

int cadastrarUsuario(){
  // Declaração da variável do tipo registro.
  usuario newUser;

  // Ponteiro para o arquivo.
  FILE *fp;

  // Define o modo de abertura do arquivo.
  char modo[] = "a+b";
  char nomeArquivo[] = "usuarios.dat";
  // Abre o arquivo binário para leitura e gravação.
  fp = openFile(nomeArquivo, modo);

  // Verifica se o arquivo foi aberto corretamente. Caso negativo, sai da função.
  if(fp == NULL){
    return 0; // Operação de abertura/criação do arquivo NÃO foi realizada com sucesso.
  }

  // Faz a leitura dos dados a serem cadastrados.
  leDadosUser(&newUser);

  // Grava as informações no arquivo.
  fwrite(&newUser, sizeof(newUser), 1, fp);

  // Fecha o arquivo.
  fclose(fp);

  // Operação realizada com sucesso.
  return 1;
}

void leDadosUser(usuario *bufferUser) {
    printf("\n\tDigite o Login: ");
    gets(bufferUser->login);

    printf("\n\tDigite a senha: ");
    gets(bufferUser->senha);

    printf("\n\t1 - Administrador; 2 - Gerente; 3 - Usuario");
    printf("\n\tDigite o codigo correspondente ao tipo de usuario a ser cadastrado: ");
    scanf("%d", &bufferUser->nivelAcesso);
}

int listarUsuarios(){

  // Variável do tipo registro que recebe os dados de cada funcionário, gravados no arquivo.
	usuario newUser;

	// Ponteiro para o arquivo.
	FILE *fp;

	// Define o modo de abertura do arquivo.
	char modo[] = "rb";
	char nomeArquivo[] = "usuarios.dat";

	// Abre o arquivo binário para leitura e gravação.
	fp = openFile(nomeArquivo, modo);

	// Verifica se o arquivo foi aberto corretamente. Caso negativo, sai da função.
	if(fp == NULL){
		return 0; // Operação de abertura do arquivo NÃO foi realizada com sucesso.
	}


	while(fread(&newUser, sizeof(newUser), 1, fp)){
		if(newUser.nivelAcesso == 1){
			// Imprime as informações dos registros ativos no sistema.
			printf("\n\n\t###### Dados do usuario ######");
			printf("\n\t\tLogin: %s", newUser.login);
			printf("\n\t\tNivel de Acesso: %d", newUser.nivelAcesso);
		}

	}

	// Fecha o arquivo após as operações.
	fclose(fp);

	// Operação realizada com sucesso.
	return 1;
}
