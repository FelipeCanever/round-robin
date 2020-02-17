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

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Process.hpp"
using roundRobin::Process;
using roundRobin::Time;

#include "Timestamp.hpp"
using roundRobin::Timestamp;

using Processes = vector<Process>;
using Timestamps = vector<Timestamp>;

auto operator << (std::ostream& ostream, Processes const& processes) -> std::ostream&;
auto operator << (std::ostream& ostream, Timestamps const& timestamps) -> std::ostream&;

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
		cout << "Id" << ":\t\t\t" << process.id << "\n";
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
			return a.arrivalTime < b.arrivalTime;
		}
	);

	auto remainingExecuteTimes = vector<Time>(n);

	for (auto i = 0; i < n; ++i)
		remainingExecuteTimes[i] = processes[i].executeTime;

	auto time = Time{};
	auto numberZeros = 0;

	cout << "Quantum (ms): ";
	auto quantum = Time{};
	cin >> quantum;
	cout << "\n";

	auto timestamps = Timestamps{};

	do
	{
		numberZeros = 0;

		for (auto i = 0; i < n; ++i)
		{
			auto const difference = static_cast<Time::T>(remainingExecuteTimes[i]) - static_cast<Time::T>(quantum);
			auto const deltaT = difference > 0 ? quantum : remainingExecuteTimes[i];

			remainingExecuteTimes[i] -= deltaT;
			time += deltaT;

			if (difference <= 0)
			{
				if (deltaT != 0)
				{
					processes[i].endTime = time;
					processes[i].waitTime = processes[i].endTime - processes[i].arrivalTime - processes[i].executeTime;
				}

				++numberZeros;
			}

			if (deltaT != 0)
				timestamps.push_back({processes[i], deltaT});
		}
	}
	while (numberZeros < n);

	cout << "\n\n";

	cout << "GANTT CHART" << "\n";
	cout << timestamps << "\n\n";
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
		ostream << setw(columnWidth) << process.id;
		ostream << setw(columnWidth) << process.priority;
		ostream << setw(columnWidth) << process.executeTime;
		ostream << setw(columnWidth) << process.arrivalTime;

		ostream << "\n";
	}

	return ostream;
}

auto operator << (std::ostream& ostream, Timestamps const& timestamps) -> std::ostream&
{
	static auto const delimiter = string{"|"};
	static auto const toBeRenamed = string{" - "};

	// Processes

	for (auto _ : delimiter)
		ostream << " ";

	for (auto const& timestamp : timestamps)
	{
		for (auto i = 0; i < timestamp.time; ++i)
			if (i == timestamp.time / 2)
				ostream << " " << timestamp.process.id << " ";
			else
				for (auto _ : toBeRenamed)
					ostream << " ";

		for (auto _ : delimiter)
			ostream << " ";
	}

	ostream << "\n";

	// Timeline

	ostream << delimiter;

	for (auto const& timestamp : timestamps)
	{
		for (auto i = 0; i < timestamp.time; ++i)
			ostream << toBeRenamed;

		ostream << delimiter;
	}

	ostream << "\n";

	// Times
	
	auto time = Time{0};
	ostream << time;

	auto constexpr numberDigits = [](auto number)
	{
		auto n = 0;

		do
		{
			number /= 10;
			++n;
		}
		while (number > 0);

		return n;
	};

	auto size = numberDigits(static_cast<Time::T>(time));

	for (auto const& timestamp : timestamps)
	{
		time += timestamp.time;

		for (auto i = 0; i < timestamp.time; ++i)
			for (auto j = 0; j < toBeRenamed.size() - (i == 0 ? size - 1 : 0); ++j)
				ostream << " ";

		size = numberDigits(static_cast<Time::T>(time));
		ostream << time;
	}

	return ostream << " (ms)";
}