#include "Neuron.h"

void MakeWeb(std::vector<std::vector<Neuron>>& neurons) {
	neurons.emplace_back(std::vector<Neuron>());
	neurons.emplace_back(std::vector<Neuron>());
	
	for (int i = 0; i < 3; i++) neurons[0].emplace_back(Neuron(2)); //first hiden layer initialization

	neurons[1].emplace_back(Neuron(2));  //second hiden layer initialization
	neurons[1].emplace_back(Neuron(2));
	neurons[1].emplace_back(Neuron(1));

	for (int i = 0; i < 2; i++) //add random value of weights
		for (int j = 0; j < neurons[i].size(); j++) neurons[i][j].setWeights();

	return;
}

int UseWeb(std::vector<std::vector<Neuron>>& neurons, int val1, int val2) {
	std::vector<double> hundredsRank = { double(val1 / 100),double(val2 / 100) };
	std::vector<double> tensRank = { double(val1 / 10 % 10),double(val2 / 10 % 10) };
	std::vector<double> unitsRank = { double(val1 % 10),double(val2 % 10) };

	//FIRST LAYER

	neurons[0][0].input_values(hundredsRank);	//input
	neurons[0][1].input_values(tensRank);
	neurons[0][2].input_values(unitsRank);

	std::vector<double> output(3); //output of first layer

	for (int i = 0; i < neurons[0].size(); i++)
		output[i] = neurons[0][i].activate(neurons[0][i].multiplie());

	//SECOND LAYER

	std::vector<double> inp0 = { output[0],output[1] };
	std::vector<double> inp1 = { output[1],output[2] };
	std::vector<double> inp2 = { output[2] };

	neurons[1][0].input_values(inp0);	//input
	neurons[1][1].input_values(inp1);
	neurons[1][2].input_values(inp2);

	for (int i = 0; i < neurons[1].size(); i++)	//output of second layer
		output[i] = neurons[1][i].activate(neurons[1][i].multiplie());

	//MAKE RESULT

	int res = 100 * int(output[0] * 2 * 100) % 10 + 
		10 * int(output[1] * 2 * 100) % 10 + 
		int(output[2] * 2 * 100) % 10;

	return res;
}

void MakeDataSet() {
	int a;
	int b;
	int sum;

	srand(NULL);

	for (int i = 0; i < 100; i++) {
		a = rand() % 500;
		b = rand() % 500;
		sum = a + b;
		std::cout << a << ' ' << b << ' ' << sum << '\n';
	}

	return;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	std::vector<std::vector<Neuron>> neurons;

	MakeWeb(neurons);

	int val1;
	int val2;
	int result;
	int cnt = 1;

	while (std::cin >> val1 >> val2 >>result) {
		if (UseWeb(neurons, val1, val2) != result) {
			std::cout << cnt++ << ") -\n";

			//learn
		}
		else std::cout << cnt++ << ") +\n";
	}

	return 0;
}