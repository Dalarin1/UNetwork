#pragma once
#include "Functions.h"

template<operational T>
class neuron {
public:
	T value = 0;
	T bias = 0;
	std::vector<T> inputs;
	T (*function)(T) = sigmoid;
	std::vector<std::pair<neuron*, T>> connections;

	inline T get_value() {
		value = bias + function(sum<T>(&inputs));
		return value;
	}
	void feed_forward() {
		T val = get_value();
		for (auto& connection: connections) {
			connection.first->inputs.push_back(val * connection.second);
		}
	}

	inline void add_connection(neuron* _next, T weight = 0) {
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
	neuron(T _bias, T(*_func)(T) = nullptr) :bias(_bias), function(_func), value(0) {}
	~neuron() { inputs.clear(); connections.clear(); }

};