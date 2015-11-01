#include "fonction.h"


int fonction(unsigned int number) {
	return __builtin_popcount(number);
}
