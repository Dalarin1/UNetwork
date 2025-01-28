#pragma once
#include "Neuron.h"

class net {
<<<<<<< HEAD
	std::vector<neuron* > input_neurons;
	std::vector<neuron* > output_neurons;
	
	net() = default;
	net(std::vector<neuron*>& _input) {
		input_neurons = _input;}

	std::vector<double> get_result() {

	}
};
=======
public:
	std::vector<neuron* > input_neurons;
	std::vector<neuron* > neurons;
	std::vector<neuron* > output_neurons;
	
	net() = default;
	net(std::vector<neuron*>& _input) :input_neurons(_input) {}
	net(std::vector<int> _struct);
	~net() { for (const auto& i : neurons) { delete i; } input_neurons.clear(); neurons.clear(); output_neurons.clear(); }

	void set_input_data(std::vector<double>);
	void feed_forward();
	std::vector<double> get_result();
	
};

net::net(std::vector<int> _struct) {
	for (int layer = 0; layer < _struct.size(); layer++) {
		for (int i = 0; i < _struct[layer]; i++) {
			neurons.push_back(new neuron);
			if (layer == 0) { input_neurons.emplace_back(neurons[i]); }
			if (layer == _struct.size() - 1) { output_neurons.emplace_back(neurons[i]); }
		}
	}
	for (int layer = 0; layer < _struct.size() - 1; layer++) {
		for (int i = 0; i < _struct[layer]; i++) {
			for (int j = 0; j < _struct[layer + 1]; j++) {
				neurons[layer + i]->add_connection(neurons[layer + 1 + j]);}
		}
	}
}
void net::feed_forward() {
	std::vector<neuron* >* current_neurons = &input_neurons;


	delete current_neurons;
}
>>>>>>> d0e5b6c (Nothing happened at 27.01.2024)
