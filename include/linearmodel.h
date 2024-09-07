#include<vector>

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

class LinearModel {

private:
     double learning_rate;        
     int n_iters;                 
     std::vector<double> weights; 
     double bias; 
public:
    LinearModel(double learning_rate = 0.01, int n_iters = 1000);

    void fit(const std::vector<std::vector<double>>& X,const std::vector<double>& y) ;

     std::vector<double> predict(const std::vector<std::vector<double>>& X) ;

     double mse(const std::vector<double>& y_true,const std::vector<double>& y_pred);
};

#endif 
