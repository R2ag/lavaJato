#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"

//Ps: Falta criar um modo de nomear o arquivo com a data e hora da criação do backup
/*A função backup funciona copiando os dados presentes no arquivo original para o arquivo
de backup. A função abre o arquivo original em modo de leitura, cria o arquivo copia e vai
percorrendo dado por dado e salvando em uma variavel auxiliar temporario.

 Criar função pra recuperar backup
*/
void backupSeguranca(){
    dados bkpBuffer; //Variavel auxiliar utilizada para armazenar temporariamente os dados lidos do arquivo original

    char modo[] = "rb";
  	char nomeArquivo[] = "funcionarios.dat"

    char modoBkp[] = "a+b";
  	char nomeArquivoBkp[] = "backup.dat"

    FILE *master = openFile(nomeArquivo, modo);
    if(master == NULL){
  		return; // Operação de abertura/criação do arquivo NÃO foi realizada com sucesso.
  	}
    FILE *bkp = openFile(nomeArquivoBkp, modoBkp);

    if(bkp == NULL){
  		return; // Operação de abertura/criação do arquivo NÃO foi realizada com sucesso.
  	}

    fseek(master, 0, SEEK_SET);

    while (fread(&bkpBuffer, sizeof(dados), 1, master)) {
      fwrite(&bkpBuffer, sizeof(dados), 1, bkp);

    }

    fclose(master);
    fclose(bkp);
}
