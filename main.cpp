#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include "Process.hpp"
using roundRobin::Process;
using roundRobin::Time;

using Processes = vector<Process>;

auto operator << (std::ostream& ostream, Processes const& processes) -> std::ostream&;

auto main() -> int
{
	cout << "ROUND-ROBIN SCHEDULING" << "\n\n";

	cout << "Number of processes: ";
	auto n = int{};
	cin >> n;
	cout << "\n";

	auto processes = Processes{};

	for (auto i = 0; i < n; ++i)
	{
		cout << "PROCESS #" << i << "\n";

		cout << "Priority" << ":\t\t";
		auto priority = Process::Priority{};
		cin >> priority;

		cout << "Execute time (ms)" << ":\t";
		auto executeTime = Time{};
		cin >> executeTime;

		cout << "Arrival time (ms)" << ":\t";
		auto arrivalTime = Time{};
		cin >> arrivalTime;

		auto process = Process{priority, executeTime, arrivalTime};
		cout << "Id" << ":\t\t\t" << process.id() << "\n";
		processes.push_back(process);

		cout << "\n";
	}

	cout << "\n";

	cout << processes << "\n";
}

auto operator << (std::ostream& ostream, Processes const& processes) -> std::ostream&
{
	ostream << "PROCESS" << "\t\t";
	ostream << "PRIORITY" << "\t";
	ostream << "EXECUTE TIME (ms)" << "\t";
	ostream << "ARRIVAL TIME (ms)" << "\n";

	for (auto const& process : processes)
	{
		ostream << process.id() << "\t\t";
		ostream << process.priority() << "\t\t";
		ostream << process.executeTime() << "\t\t\t";
		ostream << process.arrivalTime() << "\n";
	}

	return ostream;
}