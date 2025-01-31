#pragma once
#include <cmath>
#include <vector>



template <typename T>
concept Summable = requires (T item){ item + item; };

template<typename T, typename U>
concept Multiplicable = requires(T a, U b) {
    { a * b } -> std::convertible_to<decltype(a * b)>;
};

template<typename T>
concept operational = Multiplicable<T, double> && Summable<T>;
 
template<Summable T>
T sum(std::vector<T>* arr) {
	T res = T();
	for (int i = 0; i < arr->size(); i++) {
		res = res + (*arr)[i];}
	return res;
};

double relu(double val) {
    return std::max(0.0, val);
}
double ddx_relu(double val) {
    return val > 0 ? 1.0 : 0.0;
}
double sigmoid(double val) {
	return 1 / (1 + std::exp(-val));
}
double ddx_sigmoid(double val) {
	return sigmoid(val) * (1 - sigmoid(val));
}
double softmax(const std::vector<double>& values, size_t i) {
    double max_val = *std::max_element(values.begin(), values.end());
    double sum = 0.0;
    for (double val : values) {
        sum += exp(val - max_val);
    }
    return exp(values[i] - max_val) / sum;
}