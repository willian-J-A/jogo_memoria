#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

extern const char *baralho_copiatxt;
extern const char *baralhotxt;

int numberplayers();
int varrebaralho(char *carta);
void removecarta(char *linha_a_remover);
void baralho();
void copiabaralho();
void nomejogadores();
int over();

#endif