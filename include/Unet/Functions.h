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
	T res;
	for (int i = 0; i < arr->size(); i++) {
		res = res + (*arr)[i];}
	return res;
};

double sigmoid(double val) {
	return 1 / (1 + std::exp(-val));
}
double ddx_sigmoid(double val) {
	return std::exp(val) / ( (1 + std::exp(-val)) * (1 + std::exp(-val)));
}
