#include "Neuron.h"

void MakeWeb(std::vector<std::vector<Neuron>>& neurons) {
	neurons.emplace_back(std::vector<Neuron>(3));
	neurons.emplace_back(std::vector<Neuron>(3));
	
	for (int i = 0; i < 3; i++) neurons[0][i] = Neuron(2); //first hiden layer initialization

	neurons[1][0] = Neuron(2);
	neurons[1][1] = Neuron(2);
	neurons[1][0] = Neuron(1);

	for (int i = 0; i < 2; i++) for (int j = 0; j < neurons[i].size(); j++) neurons[i][j].setWeights();

	return;
}

void UseWeb(std::vector<std::vector<Neuron>>& neurons, int val1, int val2) {
	
	
	return;
}

int main() {
	std::vector<std::vector<Neuron>> neurons;

	MakeWeb(neurons);

	int val1;
	int val2;

	std::cin >> val1 >> val2;

	UseWeb(neurons, val1, val2);

	return 0;
}