#pragma once
#include "Functions.h"


class neuron {
public:
	double value = 0;
	double bias = 0;
	std::vector<double> inputs;
	double (*function)(double) = sigmoid;
	std::vector<std::pair<neuron*, double>> connections;

	double get_value() {
		value = bias + function(sum<double>(&inputs));
		return value;
	}
	void feed_forward() {
		double val = get_value();
		for (auto& connection: connections) {
			connection.first->inputs.push_back(val * connection.second);
		}
	}

	void add_connection(neuron* _next, double weight = 0) {
		connections.push_back(std::pair(_next, weight));
	}
	void remove_connection(neuron* _neuron) {
		auto it = std::remove_if(connections.begin(), connections.end(),
								[_neuron](const std::pair<neuron*, double>& conn) {
									return conn.first == _neuron;
								});
		connections.erase(it, connections.end());
	}
	neuron() = default;
	neuron(double _bias, double(*_func)(double) = nullptr) :bias(_bias), function(_func), value(0) {}
	~neuron() { inputs.clear(); connections.clear(); }

};