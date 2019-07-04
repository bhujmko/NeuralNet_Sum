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

		if (res == 0) return 0;
		else if (res > 0 && res <= 0.05) return 1;
		else if (res > 0.05 && res <= 0.1) return 2;
		else if (res > 0.1 && res <= 0.15) return 3;
		else if (res > 0.15 && res <= 0.2) return 4;
		else if (res > 0.2 && res <= 0.25) return 5;
		else if (res > 0.25 && res <= 0.3) return 6;
		else if (res > 0.3 && res <= 0.35) return 7;
		else if (res > 0.35 && res <= 0.4) return 8;
		else if (res > 0.4 && res <= 0.45) return 9;
		else if (res > 0.45 && res <= 0.5) return 10;
		else if (res > 0.5 && res <= 0.55) return 11;
		else if (res > 0.55 && res <= 0.6) return 12;
		else if (res > 0.6 && res <= 0.65) return 13;
		else if (res > 0.65 && res <= 0.7) return 14;
		else if (res > 0.7 && res <= 0.75) return 15;
		else if (res > 0.75 && res <= 0.8) return 16;
		else if (res > 0.8 && res <= 0.85) return 17;
		else if (res > 0.85) return 18;
	}

private:
	std::vector<double> weights;
	std::vector<double> inputs;
};
