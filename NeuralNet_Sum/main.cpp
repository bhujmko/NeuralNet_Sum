#include "Neuron.h"

void MakeWeb(std::vector<Neuron>& neurons, const int cnt) {
	for (int i = 0; i < cnt; i++) {
		neurons.emplace_back(Neuron(i));
		neurons.back().setWeights();
	}

	return;
}

double kv(const double& a, const double& b) {
	return (a - b)*(a - b);
}

int UseWeb(std::vector<Neuron>& neurons, std::vector<double>& v) {
	int ans;
	double val = 0;
	double cur_res;

	for (auto&i : neurons) {
		i.inputValues(v);
		cur_res = i.sygmoid(i.multiplie());

		if (cur_res > val) {
			val = cur_res;
			ans = i.output();
		}
	}

	return ans;
}

void MakeInputValues(std::vector<double>& v) {
	if (v[0] < 500) v[0]++;
	else if (v[1] < 500) v[1]++;
	else {
		v[0] = 0; v[1] = 0;
	}
	return;
}

int main() {
#define LR double(0.1)
#define LayerSize int(1001)
	std::ios::sync_with_stdio(false);
	srand(time(NULL));

	std::vector<Neuron> neurons;

	MakeWeb(neurons, LayerSize);

	std::vector<double> input(2,0);

	double last_error = 10000;
	double error = 10000;
	int ans_rate = 0;
	int true_ans;
	int cur_ans;

	while (true) {	//net's learn
		true_ans = input[0] + input[1];

		for (auto&i : input) i /= 500.;

		if (error < 5 && error > 3) break;

		error = 0;

		cur_ans = UseWeb(neurons, input);

		if (cur_ans != true_ans) {
			std::vector<double> answers(LayerSize);

			answers[true_ans] = 1;

			for (int i = true_ans; i < answers.size() - 1; i++) answers[i + 1] = answers[i] - 0.001;
			for (int i = true_ans; i > 0; i--) answers[i - 1] = answers[i] - 0.001;

			for (auto&i : neurons) {
				error += kv(answers[i.output()], i.sygmoid(i.multiplie()));

				i.learn(answers[i.output()], LR);
			}

			ans_rate = 0;
		}
		else ans_rate++;

		for (auto&i : input) i *= 500.;

		MakeInputValues(input);

		//system("cls");
		std::cout << error << '\n';
	}

	_sleep(1000);

	system("cls");

	std::vector<double> val(2);

	while (std::cin >> val[0]>>val[1]) {

		std::cout << UseWeb(neurons, val);

		_sleep(1000);

		system("cls");
	}

	return 0;
}