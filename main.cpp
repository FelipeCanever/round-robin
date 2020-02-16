#include <algorithm>
using std::begin;
using std::end;
using std::sort;

#include <iomanip>
using std::left;
using std::setw;

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

	sort
	(
		begin(processes), end(processes),

		[](Process const& a, Process const& b)
		{
			return a.arrivalTime() < b.arrivalTime();
		}
	);
}

auto operator << (std::ostream& ostream, Processes const& processes) -> std::ostream&
{
	static constexpr auto columnWidth = 20;

	ostream << left;

	ostream << setw(columnWidth) << "PROCESS";
	ostream << setw(columnWidth) << "PRIORITY";
	ostream << setw(columnWidth) << "EXECUTE TIME (ms)";
	ostream << setw(columnWidth) << "ARRIVAL TIME (ms)";

	ostream << "\n";

	for (auto const& process : processes)
	{
		ostream << setw(columnWidth) << process.id();
		ostream << setw(columnWidth) << process.priority();
		ostream << setw(columnWidth) << process.executeTime();
		ostream << setw(columnWidth) << process.arrivalTime();

		ostream << "\n";
	}

	return ostream;
}