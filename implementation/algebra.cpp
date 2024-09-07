#include "../include/algebra.h"
#include <iostream>
#include <stdexcept>


double dot(std::vector<double> vec1,std::vector<double> vec2){
    if(vec1.size()!=vec2.size()) throw std::invalid_argument("Excepection: Vectors must be of the same size.");
    double result = 0.0;
    for(long i = 0;i<vec1.size();i++){
        result+= vec1[i]*vec2[i];
    }
    return result;
}

std::vector<double> dot(std::vector<std::vector<double>> matrix, std::vector<double> vec){
    if (matrix[0].size() != vec.size()) throw std::invalid_argument("Exception: Matrix col must match vector size.");
    std::vector<double> result(matrix.size(),0.0);
    for(long i = 0;i<matrix.size();i++){
        for(long j  = 0;j<vec.size();j++){
            result[i] += matrix[i][j]*vec[j];
        }
    }
    return result;
}

std::vector<std::vector<double>> dot(std::vector<std::vector<double>> mat1,std::vector<std::vector<double>> mat2){
    if (mat1[0].size() != mat2.size()) throw std::invalid_argument("Matrix dimensions must match for multiplication.");
    std::vector<std::vector<double>> result(mat1.size(),std::vector<double>(mat2[0].size(),0.0));
    for(long i = 0;i<mat1.size();i++){
        for(long j = 0;j<mat2[0].size();j++){
            for(long k = 0;k<mat2.size();k++){
                result[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    return result;
}
    




