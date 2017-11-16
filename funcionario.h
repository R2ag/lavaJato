#ifndef FUNCIONARIO_HEADER
#define  FUNCIONARIO_HEADER

int cadastraFunc();
void leDadosFunc(dados *funcLe);
int imprimeFunc();
int pesquisaFunc();
void consultaFunc(int posRegFunc);
void alteraFunc(int posRegFunc);
void confirmaAlteracoes(dados *func);
void excluiFunc(int posRegFunc);

#endif
