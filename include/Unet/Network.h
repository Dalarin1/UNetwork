#pragma once
#include "Neuron.h"

class net {
public:
	std::vector<neuron* > input_neurons;
	std::vector<neuron* > neurons;
	std::vector<neuron* > output_neurons;
	
	net() = default;
	net(std::vector<neuron*>& _input) :input_neurons(_input) {}
	net(std::vector<int>& _struct);
	~net() { for (const auto& i : neurons) { delete i; } input_neurons.clear(); neurons.clear(); output_neurons.clear(); }

	void set_input_data(std::vector<double>&);
	void feed_forward();
	std::vector<double> get_result();
};

net::net(std::vector<int>& _struct) {
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
	for(int i = 0; i < input_neurons.size(); i++){if(input_neurons[i]->inputs.size()  == 0) {throw("ERROR: Not enoug input data");}}
	if(neurons.size() > 0){
		for(int i = 0; i < neurons.size(); i++){
			neurons[i]->feed_forward();
	 	}
	}
}
void net::set_input_data(std::vector<double>& data){
	if(data.size() != input_neurons.size()){throw("ERROR: Data.size != input_neurons.size");}
	for(int i = 0; i < data.size(); i++){
		input_neurons[i]->inputs.push_back(data[i]);}
	return;
}