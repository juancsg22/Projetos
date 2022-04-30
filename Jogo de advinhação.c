#include <stdio.h>
#include <stdlib.h> // biblioteca para usar o abs
#include <time.h> //biblioteca para usar time(0)
//#define NUMERO_DE_TENTATIVAS 5 // DEFINIR CONSTANTES

int main () {
    //função main é o core, primeira coisa que lê.
    //imprime o cabeçalho do jogo
  printf("\n\n");
  printf("  ;;;;;;;;;,_______________,;;;;;;;                        \n");
  printf("  ;;;;;;;;;;;:,___________, :;;;;;;;;;,                    \n");
  printf("  :;;;;;;;;;;;;__________, :;;;;;;;;;;;,                   \n");
  printf("  _ :;;;;;;;;;;;, , _______, :;;;;;;;;;;;,                 \n");
  printf("  ___:;;;;;;;;;;;;_______, ;;;;;;;;;;;;:                   \n");
  printf(" ____.•¸:;;;;;;;;;,_____,;;;;;;;;;;       SEJAM BEM VINDOS \n");
  printf("  _______•.:;;;;;;,_____,;;;;;;;:'          AO NOSSO JOGO  \n");
  printf("  ___________•.:;;;;.., ..;;;;;;•         DE ADVINHACAO    \n");
  printf("  ______..•;;;;;;;;;;;;;;;;;;;;;;;                         \n");
  printf("  ____.';;;;;'D;;;;;;;;;;;;;;;;;;;                         \n");
  printf("  ____;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;                       \n");
  printf("  _____:;;;;;;;;;;;;;;;;;;;;;;;;;;                         \n");
  printf("  _______•.;;;;;;;;;;;;;;;;;;;;                            \n");
  printf("  __________.;;;;;;;;;;;;;;;;;.                            \n");
  printf("  ______(*•.. (*•.. ..•*') ..•* )                      \n\n\n");



    int segundos = time (0);   //marcação dos segundos desde 01/01/1970 até o momento atual
    srand(segundos);        //srand é que vai ditar a função para o rand rodar um numero aleatorio

    int numerorandomico = rand();         //rand () função para ter numeros aleatorios

    int numerosecreto = numerorandomico % 100;    // % é o valor do resto da divisão
    int chute;                   //long é para armazenar numeros maiores que 2^32 8 bytes short usa 2 bytes
    int tentativas = 1;                     
    double pontos = 1000;       //variavel decimal de 8 bytes e ai usa %f para lincar  float é para decimais de 4 bytes
    int acertou = 0;
    int nivel;
    printf("Qaul o nivel de dificuldade?\n ");
    printf("(1) facil (2) medio (3) dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch (nivel) { //funciona como um if e os cases são os else if e esle, só que para executar apenas 1 case tem que colocar break neles
      case 1:
        numerodetentativas = 20;
        break;
      
      case 2: 
        numerodetentativas = 15;
        break;
      
      default:
        numerodetentativas = 6;
        break;
    }


    for (int i = 1; i <= numerodetentativas; i++ ){ //PARA LOOPS CONTADOS //while(1) {"enquanto"...para loops sem definição de tentativas   0 para falsop e 1 para verdadeiro

        printf("Tentativa %d\n", tentativas);
        printf("Qual e o numero?  ");
        scanf("%d", &chute);                                   //%d serve para lincar com a variável inteira desejada
        printf("Seu chute foi %d\n", chute);

        if(chute <0) {
            printf("Voce nao pode chutar numeros negativos!\n");

            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);
        

        if(acertou) {
            break;
        }
   
       else if(maior) {
          printf("Seu chute foi maior que o numero secreto\n");
        }

       else {
         printf("Seu chute foi menor que o numero secreto\n");
        }

        tentativas = tentativas + 1;

        double pontosperdidos = abs(chute - numerosecreto) / 2.0;
        pontos = pontos - pontosperdidos;
    }


    printf("Fim de Jogo\n");

    if(acertou) {
      printf("\n\n");
      printf("      _.-'''''-._             \n");
      printf("    .'  _     _  '.           \n");
      printf("   /   (_)   (_)   \\         \n");
      printf("  |  ,           ,  |         \n");
      printf("  |  \\`.       .`/  |        \n");
      printf("   \\  '.`'''''`.'  /         \n");
      printf("    '.  `'---'`  .'           \n");
      printf("      '-._____.-'             \n\n\n");


      printf("Voce ganhou\n");
      printf("Voce acertou em %d tentativas\n", tentativas);
      printf("Total de pontos %.2f\n", pontos); //.1 quantidade de casagccs decimais

    } else {
      printf("\n\n");
      printf("  , ; ,   .-''''''-.   , ; ,     \n");
      printf("  \\|/  .'           '.  \\|//   \n");
      printf("   \\\\-/   ()   ()     \\-;-/   \n");
      printf("   // ;               ; \\\\     \n");
      printf("  //__; :.         .; ;__\\\\    \n");
      printf(" `-----\'.'-.....-'.'/-----'     \n");
      printf("        '.'.-.-,_.'.'            \n");
      printf("          '(  (..-'              \n");
      printf("            '-'              \n\n\n"); 
      printf("Voce perdeu! Tente novamente\n");
    }
 
}
