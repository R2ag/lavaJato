#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"

void bakupSeguranca(FILE *arquivo){
    dados bkpBuffer;

    FILE *bkp = fopen("bakup.dat","a+b");
    fseek(arquivo, 0, SEEK_SET);

    while (fread(&bkpBuffer, sizeof(dados), 1, arquivo)) {
      fwrite(&bkpBuffer, sizeof(dados), 1, arquivo);

    }
}
