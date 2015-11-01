#include <cstdlib>
#include "myclass.h"

/*
 * Usage: main [qty divisor] 
 * qty et divisor doivent être des nombres entiers positifs
 * qty et divisor valent 1 si non-spécifiées
 */


static const int MAX = 30;

/* Génère une string aléatoire */
void gen_random(char *s, int len) {
        static const char alphanum[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";


        for (int i = 0; i < len; ++i) {
            s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        s[len] = 0;
}

/* 
 * Génère un nombre de données correspondant à:
 * n = qty * 1000 / divisor
 */
char** generateTestData(int qty, int divisor) {
    int n = qty / divisor * 1000;  // Division entière
    char** result = (char**) malloc(n); // Réserve l'espace de n octets plutôt que pour n pointeurs
    for (int i=0; i<n; i++) {
        int len = rand() % MAX;
        result[i] = (char *) malloc(len);
        gen_random(result[i], len); // Dépassement du tableau de char
    }
    return result;
}

BigDataStorage* getBigDataStorage(char** data, int qty) {
    auto storage = BigDataStorage();
    storage.addData(data, qty);
    return &storage;    // Retourne un pointeur sur le stack
}


int main(int argc, char** argv) {
    int qtyToGenerate = argc >= 1 ? std::atoi(argv[0]) : 1;    // Lit le paramètre 0 au lieu de 1, argc = nombre d'argument + 1
    int divisor = argc >= 2 ? std::atoi(argv[1]) : 1;    // Lit le paramètre 1 au lieu de 2, argc = nombre d'argument + 1
    char** data = generateTestData(qtyToGenerate, divisor);
    BigDataStorage* storage = getBigDataStorage(data, qtyToGenerate);

    auto handler = StringHandler(*storage);
    handler.operation1();

    free(data); // Libère l'espace mémoire de la liste de char[], mais pas chacun des char[]
}
