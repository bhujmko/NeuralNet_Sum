#include "Neuron.h"

void MakeWeb(std::vector<Neuron>& neurons) {
	for (int i = 0; i < 1000; i++) {
		neurons.emplace_back(Neuron(1000 - i));
		neurons.back().setWeights();
	}

	return;
}

int UseWeb(std::vector<Neuron>& neurons, int val1, int val2) {
	std::vector<double> vals = { double(val1),double(val2) };

	for (auto& i : neurons) {
		i.inputValues(vals);
		
		if (i.activate(i.multiplie())) return i.output();
	}
	
	return 0;
}

void MakeInputValues(int& v1, int& v2) {
	if (v1 > 0) v1--;
	else if (v2 > 0) v2--;
	else {
		v1 = 500; v2 = 500;
	}
	return;
}

int main() {
	/*freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);*/

#define LR double(0.1)

	std::ios::sync_with_stdio(false);
	srand(time(NULL));

	std::vector<Neuron> neurons;

	MakeWeb(neurons);

	int val1 = 500;
	int val2 = 500;
	int cnt = 0;
	int mx = cnt;

	while (true) {
		int ans = UseWeb(neurons, val1, val2);
		int TrueResult = val1 + val2;

		if (ans != TrueResult) {
			cnt = 0;

			for (auto& i : neurons) {
				if (i.output() > TrueResult)
					if (i.activate(i.multiplie())) i.learn(0, LR);
				else if (!i.activate(i.multiplie())) i.learn(0.75, LR);
			}
		}
		else if (cnt >= 1000) break;
		else cnt++;

		system("cls");
		if (mx < cnt) mx = cnt;
		std::cout << mx;

		MakeInputValues(val1, val2);
	}

	while (std::cin >> val1 >> val2)
		std::cout << UseWeb(neurons, val1, val2) << '\n';

	return 0;
}