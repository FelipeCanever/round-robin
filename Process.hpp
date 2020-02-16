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

		auto id() const -> int;

		auto priority() const->Priority;
		auto priority(Priority priority) -> void;

		auto executeTime() const->Time;
		auto arrivalTime() const -> Time;

	private:
		const int _id;

		Priority _priority;

		const Time _executeTime;
		const Time _arrivalTime;
	};
}
