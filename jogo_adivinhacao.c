#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    char jogardenovo = 's';
    while(jogardenovo == 's'){
    // explicação do jogo
    printf("*********************************\n");
    printf("Bem vindo ao jogo de adivinhacao.*\n");
    printf("*********************************\n");
    printf("Nesse jogo um numero sera escolhido aleatoriamente, e voce tera que tentar acertar qual e esse numero.\n");
    // declaração de variáveis
    int segundos = time(0);
    srand(segundos);
    int tentativas = 1;
    int numero = rand();
    int numero_secreto = numero % 100;
    int chute;
    double pontos = 1000;

    int acertou = 0;
    int nivel;
     // escolha do nível de dificuldade
    printf("Qual o nivel de dificuldade? \n");
    printf("(1) Facil, (2) Medio, (3)Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    int numerotentativas;
   // condição de cada nível de dificuldade
    if(nivel == 1){
        numerotentativas = 20;
    }
    else if(nivel == 2){
        numerotentativas = 15;
    }
    else if(nivel == 3){
        numerotentativas = 6;
    }

    for(int i=1; i <= numerotentativas; i++){
        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute ?\n");
        scanf("%d", &chute);
        printf("Seu chute foi: %d \n", chute);

        // condição que restringe o usuário de usar números negativos
         if(chute < 0){
            printf("Voce nao pode chutar numeros negativos.\n");
            continue;
        }
        
        int maior = chute > numero_secreto;
        acertou = chute == numero_secreto;
        if(acertou){
            break;
        }
        if(maior){
                printf("O seu chute e maior do que o numero secreto.\n");
        
        }
        else{
                printf("Seu chute e menor do que o numero secreto.\n");
        }
        tentativas++;
        // função abs() converte o número para positivo.
        double pontosperdidos = abs(chute - numero_secreto) / (double)2;
        pontos = pontos - pontosperdidos;
    
    }
    printf("Fim de jogo!\n");
    // mensagem de vitória
    if(acertou){
        printf("Voce venceu !\n");
        printf("Voce acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f \n", pontos);
    }  
    // mensagem de derrota 
    else{
        printf("Voce perdeu ! Tente novamente.\n");
        printf("O numero correto era: %d\n", numero_secreto);
    }
    printf("Deseja jogar novamente ? (Escreva s para sim ou n para nao): \n");
    scanf(" %c", &jogardenovo);
    }
    printf("Obrigado por jogar !\n");
}