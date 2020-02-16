#include <iostream>
using std::cin;
using std::cout;

auto main() -> int
{
	cout << "ROUND-ROBIN SCHEDULING" << "\n\n";

	cout << "Quantum (ms): ";
	auto quantum = int{};
	cin >> quantum;
	cout << "\n";

	cout << "Number of processes: ";
	auto n = int{};
	cin >> n;
	cout << "\n";
}