#include<vector>
#ifndef ALGEBRA_H
#define ALGEBRA_H 

class Algebra
{

public:
    double dot(std::vector<double> vec1,std::vector<double> vec2);

    std::vector<double> dot(std::vector<std::vector<double>> matrix, std::vector<double> vec);

    std::vector<std::vector<double>> dot(std::vector<std::vector<double>> mat1,std::vector<std::vector<double>> mat2);
    
};

#endif
