#include <iostream>
#include <array>

#include "mat_inf.h"

int main(){

    mat_inf<int, 3> mat(1);

    auto f = mat[2];

    std:: cout << f << std::endl;

    return 0;
}