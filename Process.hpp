#pragma once

#include "Time.hpp"

namespace roundRobin
{
	class Process
	{
	private:
		static int numberOfProcesses;

	public:
		using Priority = int;

		Process(Priority priority, Time executeTime, Time arrivalTime);

		auto operator = (Process const& process) -> Process&;

		auto id() const -> int;

		auto priority() const -> Priority;
		auto priority(Priority priority) -> void;

		auto executeTime() const -> Time;
		auto arrivalTime() const -> Time;

	private:
		int _id;

		Priority _priority;

		Time _executeTime;
		Time _arrivalTime;
	};
}
