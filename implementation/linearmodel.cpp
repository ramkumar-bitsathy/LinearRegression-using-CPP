#include "../include/linearmodel.h"
#include "../include/algebra.h"
#include <iostream>
#include <vector>
#include <math.h>

LinearModel::LinearModel(double learning_rate, int n_iters)
    : learning_rate(learning_rate), n_iters(n_iters), bias(0.0) {
}

void LinearModel::fit(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
    int n_samples = X.size();
    int n_features = X[0].size();
    weights = std::vector<double>(n_features, 0.0); 

    for (int iter = 0; iter < n_iters; iter++) {
        std::vector<double> y_predicted = predict(X);
        std::vector<double> dw(n_features, 0.0);  
        double db = 0.0;                 
        for (int i = 0; i < n_samples; i++) {
            double error = y_predicted[i] - y[i];
            for (int j = 0; j < n_features; j++) {
                dw[j] += error * X[i][j];
            }
            db += error;
        }

        for (int j = 0; j < n_features; j++) {
            dw[j] /= n_samples;
        }
        db /= n_samples;

        for (int j = 0; j < n_features; j++) {
            weights[j] -= learning_rate * dw[j];
        }
        bias -= learning_rate * db;
        if(iter%100==0)
        std::cout<<"Training under Process Error(Current): " <<mse(y,y_predicted)<<"\n";
    }
}

double LinearModel::mse(const std::vector<double>& y_true, const std::vector<double>& y_pred)  {
    double mse = 0.0;
    for (size_t i = 0; i < y_true.size(); ++i) {
        mse += std::pow(y_true[i] - y_pred[i], 2);
    }
    return mse / y_true.size();
}

std::vector<double> LinearModel::predict(const std::vector<std::vector<double>>& X)  {
    int n_samples = X.size();
    std::vector<double> y_pred(n_samples);

    for (int i = 0; i < n_samples; i++) {
        y_pred[i] = bias; 
        for (int j = 0; j < X[i].size(); j++) {
            y_pred[i] += X[i][j] * weights[j];
        }
    }
    return y_pred;
}
