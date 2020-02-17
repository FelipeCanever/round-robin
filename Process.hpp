#pragma once

#include "Time.hpp"

namespace roundRobin
{
	struct Process
	{
	private:
		static int numberOfProcesses;

	public:
		using Priority = int;

		int id;

		Priority priority;

		Time executeTime;
		Time arrivalTime;

		Time waitTime;
		Time endTime;

		Process(Priority priority, Time executeTime, Time arrivalTime);
		auto operator = (Process const& process) -> Process&;
	};
}
