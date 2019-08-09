#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

class Neuron
{
public:
	Neuron(int num) {
		number = num;
		inputs.resize(5);
		weights.resize(5);
	}

	void inputValues(std::vector<double>& v) { for (int i = 0; i < v.size(); i++) inputs[i] = v[i]; }

	void setWeights() { for (auto&i : weights) i = double(rand() % 99 + 1) / 100.; }

	double multiplie() {
		double sum = 0;

		for (short i = 0; i < inputs.size(); i++) sum += inputs[i] * weights[i];

		return sum;
	}

	int output() { return number; }

	double sygmoid(double x) {
		return 1 / (1 + exp(-1 * x));
	}

	double sygmoid_dX(double x) { return sygmoid(x)*(1 - sygmoid(x)); }

	void learn(double ExpRes, double LearningRate) {
		double x = multiplie();
		double CurRes = sygmoid(x);
		double error = CurRes - ExpRes;
		double dX = sygmoid_dX(x);
		double WeightsDelta = error * dX;

		for (int i = 0; i < weights.size(); i++)
			weights[i] = weights[i] - inputs[i] * WeightsDelta * LearningRate;

		return;
	}

	double weights_output(const int point) { return weights[point]; }

private:
	std::vector<double> weights;
	std::vector<double> inputs;
	short number;
};
