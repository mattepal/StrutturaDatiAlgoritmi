#define _CRT_SECURE_NO_WARNINGS_
#if !defined PREZZO_H
#define PREZZO_H

#include <stdlib.h>
#include <string.h> 
#include <stdio.h>

struct Articolo {
    char nome[11];
    int prezzo;
};
void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);

#endif // !defined PREZZO_h
