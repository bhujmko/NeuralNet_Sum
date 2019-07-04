#include <iostream>
#include <vector>
#include <cmath>

class Neuron
{
public:
	Neuron(int num) {
		inputs.resize(num);
		weights.resize(num);
	}

	void setWeights() {
		for (auto& i : weights) i = double(rand() % 99 + 1) / 100.;
	}

	double multiplie() {
		double sum = 0;

		for (short i = 0; i < inputs.size(); i++) sum += inputs[i] * weights[i];

		return sum;
	}

	double activate(double val) {
		double res = 1 / (1 + exp(-1 * val));
		return res;
	}

private:
	std::vector<double> weights;
	std::vector<double> inputs;
};
