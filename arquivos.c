
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "bakup.h"
#include "tipoDados.h"
#include "funcionario.h"
#include "menu.h"


FILE *openFile(char *modo){
  FILE *fp = fopen("funcionarios.dat", modo);
    return fp;
}
