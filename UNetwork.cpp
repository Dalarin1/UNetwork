#include "UNetwork.h"
#include "include/Unet/Network.h"
#include <iostream>

void print_neuron(neuron* nrn) {
	std::cout << nrn << ":\n";
	std::cout << '\t' << "value= " << nrn->value << '\n';
	for (auto i : nrn->connections) {
		std::cout << '\t' << i.first << ' ' << i.second << '\n';
	}
}
int main() {
	net ai = net({2,2,1});
	for (auto i : ai.neurons) {
		print_neuron(i);
	}
	std::cout << std::endl;
	ai.set_input_data({1,1});
	for (auto i : ai.neurons) {
		print_neuron(i);
	}
	std::cout << std::endl;
	ai.feed_forward();
	for (auto i : ai.neurons) {
		print_neuron(i);
	}
	return 0;
}
