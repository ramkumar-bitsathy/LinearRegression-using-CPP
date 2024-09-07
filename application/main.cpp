#include <iostream>
#include <vector>
#include "../include/linearmodel.h"

int main() {

    std::vector<std::vector<double>> X = {
        {1, 2},   
        {2, 3},   
        {3, 4},  
        {4, 5},   
        {5, 6}   
    };

    std::vector<double> y = {5, 7, 9, 11, 13};  

    double learning_rate = 0.01;
    int n_iters = 1000;
    LinearModel model(learning_rate, n_iters);

    std::cout << "Training with Given data..." << std::endl;

    model.fit(X, y);

    std::cout << "Model trained successfully!" << std::endl;

    std::vector<double> predictions = model.predict(X);

    std::cout << "Predictions:" << std::endl;
    for (size_t i = 0; i < predictions.size(); i++) {
        std::cout << "For input " << X[i][0] << ", " << X[i][1] 
                  << " -> Predicted: " << predictions[i] << ", True: " << y[i] << std::endl;
    }

    double mse = 0.0;
    for (size_t i = 0; i < y.size(); i++) {
        mse += (y[i] - predictions[i]) * (y[i] - predictions[i]);
    }
    mse /= y.size();

    std::cout << "\nMean Squared Error (MSE): " << mse << std::endl;

    return 0;
}
