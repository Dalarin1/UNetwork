#pragma once
#include "Functions.h"


class neuron {
public:
<<<<<<< HEAD
	double value;
	double bias;
	std::vector<double> inputs;
	double (*function)(double);
=======
	double value = 1;
	double bias = 1;
	std::vector<double> inputs;
	double (*function)(double) = sigmoid;
>>>>>>> d0e5b6c (Nothing happened at 27.01.2024)
	std::vector<std::pair<neuron*, double>> connections;

	double get_value() {
		value = bias + function(sum<double>(&inputs));
		return value;
	}
	void feed_forward() {
		double val = get_value();
		for (size_t i = 0; i < connections.size(); i++) {
			connections[i].first->inputs.push_back(val * connections[i].second);
		}
	}

	void add_connection(neuron* _next, double weight = 1) {
		connections.push_back(std::pair(_next, weight));
	}
	void remove_connection(neuron* _neuron) {
		for (size_t i = 0; i < connections.size(); i++) {
			if (connections[i].first == _neuron) { remove(&connections, i); break; }}

	}
	neuron() = default;
	neuron(double _bias, double(*_func)(double) = nullptr) :bias(_bias), function(_func), value(0) {}
	~neuron() { inputs.clear(); connections.clear(); }

};