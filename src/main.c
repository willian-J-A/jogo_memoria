#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "game_logic.h"
#include "main.h"


int main(){
   teste();
nomejogadores();
copiabaralho();

   do {

printf("digite 1 para sortear uma carta: ");
int testebaralho;
scanf("%d", &testebaralho);

if (testebaralho == 1)
{
    baralho();
}


} while (over() == 1 );
    
    return 0;
}
