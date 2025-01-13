#define MAX_PLAYERS 5
#define MIN_PLAYERS 2
#define MAX_CARACTERES 15
#define MAX_CARACTERES_CARTAS 70
#define MAX_NUMEROS_DE_CARTAS 12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "game_logic.h"


char usuario [MAX_PLAYERS] [MAX_CARACTERES];
char bralho [MAX_CARACTERES_CARTAS] [MAX_NUMEROS_DE_CARTAS];
const char *baralho_copiatxt = "baralho_copia.txt";
const char *baralhotxt = "baralho.txt";

int numberplayers(){
    int numberofplayers;

    printf ("Seja bem vindo ao *Jogo de cartas*\n\n" );
    int quebraloop = 0;
    
    do {
    
        printf ("Digite o numero de jogadores %d-%d: ", MIN_PLAYERS, MAX_PLAYERS);
   
        if (scanf("%d", &numberofplayers) != 1) { // Verifica se a entrada foi um número
            
            printf("Entrada invalida! Por favor, digite um numero.\n");
            
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
     }

    if (numberofplayers > MAX_PLAYERS || numberofplayers < MIN_PLAYERS ){
        printf("\n\nPor favor digite um numero entre %d-%d\n\n", MIN_PLAYERS, MAX_PLAYERS);

    } else quebraloop = 1;
    

} while (!quebraloop);
     
    return numberofplayers;
}

int over(){
    return 1;
}

void nomejogadores(){
    int numberofplayer = numberplayers();
    for (int i = 0; i < numberofplayer; i++)
    {
       printf("Digite o nome do %d Jogador : ", i+1);
       scanf("%s", usuario[i] );
    }

      for (int i = 0; i < numberofplayer; i++)
    {
       printf("%s Jogador numero %d \n",usuario[i], i+1);
       
    }
    
}

void copiabaralho(){

    FILE *origem = fopen(baralhotxt, "r");
    FILE *destino = fopen(baralho_copiatxt, "w");

    // Verifica se os arquivos foram abertos com sucesso
    if (origem == 0 ) {
        printf("Erro ao abrir o arquivo de origem: %s\n", baralhotxt);
        exit(1);
    }
    if (destino == 0) {
        printf("Erro ao abrir: %s\n", baralho_copiatxt);
        fclose(origem);
        exit(1);

    }

char ch;
    while ((ch = fgetc(origem)) != EOF) {  // Lê um caractere do arquivo de origem
    fputc(ch, destino);               // Escreve esse caractere no arquivo de destino
}

    fclose(origem);
    fclose(destino);

}

void baralho(){

    char carta[70];
    FILE* f;
    f = fopen(baralho_copiatxt, "r");
    if(f == 0) {
		printf("Erro na leitura do banco de dados");
		exit(1);
	}

    int qtddecartas;
    fscanf(f, "%d", &qtddecartas);

    if (qtddecartas == 1)
    {
        copiabaralho();
    }
     
    srand(time(0));
    int randomico = rand() % qtddecartas;
    
    printf("\no numero randomico e o %d ", randomico);

    for (int i = 0; i < randomico + 1 ; i++)
    {
        fscanf(f, "%69s", carta);
        
    }

    printf("exibe a carta, %s", carta);


    fclose(f);
 
    removecarta(carta);
}

void removecarta(char *linha_a_remover){
    
    FILE *origem = fopen(baralho_copiatxt, "r");
    if (origem == NULL) {
        printf("Erro ao abrir o arquivo de origem\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário\n");
        fclose(origem);
        return;
    }

    char linha[256];
    int qtddecartas;
    fscanf(origem, "%d", &qtddecartas);

    fprintf(temp, "%d\n", qtddecartas - 1);
    // Lê cada linha do arquivo original
    while (fgets(linha, sizeof(linha), origem)) {
        linha[strcspn(linha, "\n")] = 0;

        // Se a linha lida não for a linha a ser removida, escreve no arquivo temporário
        if (strcmp(linha, linha_a_remover) != 0) {
            fputs(linha, temp);
            fputs("\n", temp);
        }
    }

    fclose(origem);
    fclose(temp);

    // Remove o arquivo original
    remove(baralho_copiatxt);

    // Renomeia o arquivo temporário para o nome do arquivo original
    rename("temp.txt", "baralho_copia.txt");
}

int varrebaralho(char *carta){
    int cartanova = 0;
    for (int i = 0; i < MAX_NUMEROS_DE_CARTAS; i++)
    {
      if (strcmp(bralho[i], carta) == 0)
      break;
      
      if (bralho[i][0] == 0)
        {
            strcpy(bralho[i], carta);
            cartanova = 1;
            break;
        }
        
    }
    return cartanova;
}



