#pragma once
#include <cmath>
#include <vector>

template <typename T>
concept operation = requires (T item){ item + item; };

template<operation T>
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
