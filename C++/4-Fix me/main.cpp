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
    int n = qty / divisor * 1000;
    char** result = (char**) malloc(n);
    for (int i=0; i<n; i++) {
        int len = rand() % MAX;
        result[i] = (char *) malloc(len);
        gen_random(result[i], len);
    }
    return result;
}

BigDataStorage* getBigDataStorage(char** data, int qty) {
    auto storage = BigDataStorage();
    storage.addData(data, qty);
    return &storage;
}


int main(int argc, char** argv) {
    int qtyToGenerate = argc >= 1 ? std::atoi(argv[0]) : 1;
    int divisor = argc >= 2 ? std::atoi(argv[1]) : 1;
    char** data = generateTestData(qtyToGenerate, divisor);
    BigDataStorage* storage = getBigDataStorage(data, qtyToGenerate);

    auto handler = StringHandler(*storage);
    handler.operation1();

    free(data);
}
