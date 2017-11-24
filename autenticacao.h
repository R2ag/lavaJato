#ifndef AUTENTICACAO_HEADER
#define  AUTENTICACAO_HEADER

int entrar(usuario aux);
int cadastrarUsuario();
void leDadosUser(usuario *bufferUser);
void alterarUsuario();
void excluirUsuario();
int listarUsuarios();
void reset();

#endif
