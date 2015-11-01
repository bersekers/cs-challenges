#include <cstdlib>
#include <cstring>
#include "myclass.h"

void BigDataStorage::addData(char** data, int count) {
    for (int i=1; i<count; i++) {
        m_data.push_back(data[i]);
    }

}

StringHandler::StringHandler(BigDataStorage data) {
    m_data = data;
}


/*
 * Copie la string sur elle même décalée de deux:
 * ex: patate -> papatate
 */
void StringHandler::operation1() {
    for(auto* i: m_data.m_data) {
        std::memcpy(i, i+2, strlen(i)); 
    }
}

/*
 * Concatène la première string avec _test
 * ex, m_data[0] = patate
 * retour = patate_test
 */
char* StringHandler::operation2() {
    char* result = (char*) malloc(strlen(m_data.m_data[0] + 5)); 
    strcpy(result, m_data.m_data[0]);
    strcpy(result+6, "_test");  
    return result; 
}

