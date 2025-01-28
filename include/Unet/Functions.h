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

template<typename T>
std::vector<T> remove(std::vector<T>* arr, int index) {
	for (int i = index; i < arr->size() - 1; i++) {
		arr->operator[](i) = arr->operator[](i + 1);
	}
	arr->pop_back();
}

double sigmoid(double val) {
	return 1 / (1 + std::exp(-val));
}
double ddx_sigmoid(double val) {
	return std::exp(val) / ( (1 + std::exp(-val)) * (1 + std::exp(-val)));
}
