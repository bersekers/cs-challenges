#include <iostream>
#include "Matrix.h"

using namespace std;

typedef float NumberFormat;

typedef Matrix<NumberFormat> MatrixType;

const unsigned int COL_NBR = 25000;
const unsigned int ROW_NBR = 25000;

int main() 
{
    std::cout << "generating..." << std::endl;
    MatrixType a(ROW_NBR, COL_NBR);

    // a.print();
    
    std::cout << "calculating..." << std::endl;
    auto result = a.cellsSum();
    std::cout << "Matrix cells' sum is: " << result << std::endl;

    return 0;
}
