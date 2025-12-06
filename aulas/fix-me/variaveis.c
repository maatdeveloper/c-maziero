#include <stdio.h>

static int teto; // static indica que a variavel deve ser iniciada no inicio e no final da
                 // execucao, variaveis globais sao static por padrao
const int sla = 5; // const indica arquivos apenas para leitura

int soma(int n) // escopo da funcao
{ 
    return n + 10;
}

int main() {
    auto int juuj = soma(12);// auto indica que a variavel deve ser iniciada na chamada de uma
                              // funcao e liberada no seu fim, variaveis locais sao auto por padrao
    
    register int reg = 1; // register informa que a variaveis deve ser em um registrador da CPU
                          // para maior desempenho

    extern int sla; // extern indica que uma variavel global ja esta definida em outro arquivo e
                    // nao precisa ser alocada novamente (portando esta linha ira gerar um erro)
    
    return 0;
}