#pragma once
#include <stdexcept>
#include "Neuron.h"

template <operational T>
class net {
public:
	std::vector<neuron* > input_neurons; 
	std::vector<neuron* > neurons; // neurons = input_neurons + (inner neurons) + output_neurons
	std::vector<neuron* > output_neurons;
	
	net() = default;
	net(std::vector<neuron*>& _input) :input_neurons(_input) {}
	net(std::vector<int>& _struct);
	~net() { for (const auto& i : neurons) { delete i; } input_neurons.clear(); neurons.clear(); output_neurons.clear(); }

	void set_input_data(std::vector<T>&);
	void feed_forward();
	std::vector<T> get_result();
};
template <operational T>
net<T>::net(std::vector<int>& _struct) {
	int index = 0;
	for (int layer = 0; layer < _struct.size(); layer++) {
		for (int i = 0; i < _struct[layer]; i++) {
			neurons.push_back(new neuron);
			if (layer == 0) { 
				input_neurons.emplace_back(neurons[index]); }
			if (layer == _struct.size() - 1) { 
				output_neurons.emplace_back(neurons[index]); }
			index++;
		}
	}
    index = 0;
    for (int layer = 0; layer < _struct.size() - 1; layer++) {
        for (int i = 0; i < _struct[layer]; i++) {
            for (int j = 0; j < _struct[layer + 1]; j++) {
                neurons[index + i]->add_connection(neurons[index + _struct[layer] + j]);
            }
        }
        index += _struct[layer];
    }
}
template <operational T>
void net<T>::feed_forward() {
	for(int i = 0; i < input_neurons.size(); i++){
		if(input_neurons[i]->inputs.size()  == 0) {
			throw std::runtime_error("ERROR: Not enough input data");}}
	if(neurons.size() > 0){
		for(int i = 0; i < neurons.size(); i++){
			neurons[i]->feed_forward();
	 	}
	}
}
template <operational T>
void net<T>::set_input_data(std::vector<T>& data){
	if(data.size() != input_neurons.size()){ 
		throw std::runtime_error("ERROR: Data size does not match input neurons size");}
	for(int i = 0; i < data.size(); i++){
		input_neurons[i]->inputs.push_back(data[i]);}
	return;
}
template <operational T>
std::vector<T> net<T>::get_result(){
	std::vector<double> result;
	for(auto& i : output_neurons){
		result.emplace_back(i->get_value());
	}
	return result;}