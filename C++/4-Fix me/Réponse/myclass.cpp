#include <cstdlib>
#include <cstring>
#include "myclass.h"

void BigDataStorage::addData(char** data, int count) {
    for (int i=1; i<count; i++) {
        m_data.push_back(data[i]);
    }

}

StringHandler::StringHandler(BigDataStorage data) { // Copie par valeur d'un gros objet
    m_data = data;
}


/*
 * Copie la string sur elle même décalée de deux:
 * ex: patate -> papatate
 */
void StringHandler::operation1() {
    for(auto* i: m_data.m_data) {
        std::memcpy(i, i+2, strlen(i));  // Les deux plages copiées sont superposées, le \0 n'est pas copié, dépassement la plage mémoire
    }
}

/*
 * Concatène la première string avec _test
 * ex, m_data[0] = patate
 * retour = patate_test
 */
char* StringHandler::operation2() {
    char* result = (char*) malloc(strlen(m_data.m_data[0] + 5)); // strlen ne prend pas en compte les \0
    strcpy(result, m_data.m_data[0]);   // Copie le \0 de la string
    strcpy(result+6, "_test");  
    return result;  // Fuite de mémoire
}

