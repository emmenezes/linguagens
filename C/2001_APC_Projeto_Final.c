#include <stdio.h> /*  biblioteca padrão  */
#include <stdlib.h> /*  usada para a função getchar()  */
#include <string.h> /*  usada para as funções de string, como [^/n]  */
#include <time.h> /*  usada para a geração de números aleatórios  */

typedef struct{
    char nome[21], historia[401];
    int completo, vida, indole, alinhamento, profissao, meta, moradia, van;
    /*  o atributo int completo serve para confirmar que todas as características foram preenchidas  */
} personagem;

personagem piloto;

/*    Seção de funções tipo void que contém apenas textos    */

void introducao();
void menu();
void saida();
void entradaincorreta();
void sempiloto();
void fimdejogoruim();
void fimdejogobom();

/*    Seção de funções interativas    */

void criacao();
void trescharadas();
void placadavan();

int main(){
    piloto.vida = 100;
    char opcao[1] = {'0'};

    system("clear");
    introducao();
    
    /* getchar() - espera o enter para prosseguir */
    getchar(); 

    while (1){
        system("clear");
        menu();
        scanf("%s", opcao);
        /*  aqui o getchar() le o ENTER para evitar que ele seja lido dentro das opções  */
        getchar();
        switch (opcao[0]) {
        case '1':
        /*  criação de personagem  */
            system("clear");
            criacao();
            break;
        
        case '2':
        /*  iniciar o jogo, mas confere primeiro se há um piloto  */
            system("clear");
            if (piloto.completo == 0){
                sempiloto();
            }
            getchar();
            break;
        
        case '3':
        /*  sair do jogo  */
            system("clear");
            saida();
            return 0;
            break;

        default:
            system("clear");
            entradaincorreta();
            getchar(); 
            break;
        }


    }
    
    return 0;
}

/*  Seção de funções tipo void que contém apenas textos  */

void introducao (){
    printf( "\nSeja bem-vinde ao Choque de Cultura, o RPG\n\n"
            "Clique em ENTER para continuar\n");
}

void menu(){
    printf( "\nHoje, é diaa 21/09/19, dia da grande manifestação\n"
            "dos motoristas do transporte alternativo.\n"
            "E é claro que os pilotos do Choque de Cultura\n"
            "não poderiam estar de fora\n\n");

    /* Menu */
    printf( "1. Criar um piloto\n"
            "2. Iniciar a missão\n"
            "3. Sair\n\n");
}

void saida(){
    printf( "\nRogerinho: achou que a gente ia perseguir você?\n"
            "Achou errado otário!\n"
            "Pode vazar.\n\n");
}

void entradaincorreta(){
    printf( "\nRogerinho: que isso rapá!?\n"
            "Tá achando que isso aqui é um jogo, é?\n"
            "Escolhe uma opção que existe\n\n"
            "Clique em ENTER para continuar\n");

}

void sempiloto(){
    printf( "\nRenan: até Renanzinho é alguém e tu não\n"
            "Se quiser jogar tem que existir primeiro\n\n"
            "Clique em ENTER para continuar\n");
}

/*  Seção de funções interativas  */

void criacao(){
    char opcao[1];
    printf( "Os pilotos do Choque olham para você do outro lado da manifestação\n"
            "Infelizmente você parece ser a única pessoa a ter uma van\n"
            "E ser facilmente intimidada\n"
            "Se quiser fugir, é só digitar 0 e clicar em ENTER\n"
            "Tudo pronto? Podemos continuar?\n\n"
            "Clique em ENTER para continuar\n\n");
    getchar();

    int nomePersonagem(){
        system("clear");
        printf( "\nRogerinho: Ei, rapá, qual o teu nome?\n\n"
                "Simone pelo seu fone de ouvido: ei, aqui tem limite de caractere\n"
                "não passe dos 20, que se for maior que isso, ele vão esquecer\n"
                "haha\n\n");
        scanf("%[^\n]", piloto.nome);
        if (piloto.nome[0] == '0'){
            system("clear");
            printf( "Simone: Ihhh, vai sair mesmo?\n"
                    "Não julgo, faria o mesmo\n"
                    "haha\n\n"
                    "Digite 0 e clique ENTER para confirmar\n"
                    "Se quiser continuar, pode digitar qualquer outra coisa\n\n");
            scanf("%s", opcao);
            if (opcao[0] == '0'){
                strcpy(piloto.nome, "");
                return -1;
            } else {
                nomePersonagem();
            }
        } else {
            system("clear");
            printf("Renan: %s...... esse é mesmo o seu nome?\n\n", piloto.nome);
            printf( "Simone: É esse mesmo?\n\n"
                    "Digite 0 e clique ENTER para mudar\n"
                    "Se quiser continuar, pode digitar qualquer outra coisa\n\n");
            scanf("%s", opcao);
            printf("%s\n", opcao);
            if (opcao[0] == '0'){
                strcpy(piloto.nome, "");
                getchar();
                nomePersonagem();
            }
        }
        return 1;
    }    

    int indolePersonagem(){
        system("clear");
        printf( "\nMaurílio: Mas fala ai, quem que é você?\n\n"
                "Simone: Bem, aqui você só tem 3 opções,\n"
                "então escolha com cuidado,\n"
                "Tô de olho!\n\n");
        printf( "1. Só falo com tranquilidade\n"
                "2. Me chamam de palestrinha\n"
                "3. Só trabalho pra dar conforto pro meu filhote\n\n");
        scanf("%d", &piloto.indole);
        if (piloto.indole < 1 || piloto.indole > 3){
            system("clear");
            printf( "Simone: Ihhh, tá querendo sair?\n"
                    "Errou na digitação?\n"
                    "Diz ai o que você quer\n\n"
                    "Digite 0 e clique ENTER para sair\n"
                    "Se quiser continuar, pode digitar qualquer outra coisa\n\n");
            scanf("%s", opcao);
            if (opcao[0] == '0'){
                piloto.indole = 0;
                return -1;
            } else {
                indolePersonagem();
            }
        }
    }

    int alinhamentoPersonagem(){
        system("clear");
        printf( "\nRenan: Esse cara parece muito estranho, Rogerinho, não confio nele não\n\n"
                "Simone: Outras 3 opções, você sabe como funciona\n"
                "Mas fala só para mim, quem é você? De verdade!\n\n");
        printf( "1. Piloto de van, ué?\n"
                "2. Ciclista disfarçado...\n"
                "3. Ex (ou não) motorista de Uber\n\n");
        scanf("%d", &piloto.alinhamento);
        if (piloto.alinhamento < 1 || piloto.alinhamento > 3){
            system("clear");
            printf( "Simone: Vai sair agora?\n"
                    "Foi engano?\n"
                    "O que foi?\n\n"
                    "Digite 0 e clique ENTER para sair\n"
                    "Se quiser continuar, pode digitar qualquer outra coisa\n\n");
            scanf("%s", opcao);
            if (opcao[0] == '0'){
                piloto.alinhamento = 0;
                return -1;
            } else {
                indolePersonagem();
            }
        }
    }

    if (nomePersonagem() < 0){
        getchar();
        return;
    }
    if (indolePersonagem() < 0){
        getchar();
        return;
    }
    if (alinhamentoPersonagem() < 0){
        getchar();
        return;
    }
}