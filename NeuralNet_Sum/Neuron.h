#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>

class Neuron
{
public:
	Neuron(int num) {
		number = num;
		inputs.resize(2);
		weights.resize(2);
	}

	void inputValues(std::vector<double> val) {
		for (int i = 0; i < val.size(); i++) inputs[i] = val[i];
	}

	void setWeights() {
		weights[0]= double(rand() % 99 + 1) / 100.;
		weights[1] = weights[0];
	}

	double multiplie() {
		double sum = 0;

		for (short i = 0; i < inputs.size(); i++) sum += inputs[i] * weights[i];

		return sum;
	}

	bool activate(double val) {
		double res = 1 / (1 + exp(-2 * val));
		return res >= 0.75;
	}

	int output() {return number;}

	double sygmoid(double x) {
		return 1 / (1 + exp(-2 * x));
	}

	double sygmoid_dX(double x) {
		return sygmoid(x)*(1 - sygmoid(x));
	}

	void learn(double ExpRes,double LearningRate) {
		double x = multiplie();
		double CurRes = sygmoid(x);
		double error = CurRes - ExpRes;
		double WeightsDelta = error * sygmoid_dX(x);

		for (int i = 0; i < weights.size(); i++)
			weights[i] = weights[i] - inputs[i] * WeightsDelta * LearningRate;

		return;
	}

private:
	std::vector<double> weights;
	std::vector<double> inputs;
	short number;
};
