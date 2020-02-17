#include "Process.hpp"

#include <cassert>

namespace roundRobin
{
	int Process::numberOfProcesses = 0;

	Process::Process(Priority const priority, Time const executeTime, Time const arrivalTime):
		id{this->numberOfProcesses++},
		priority{priority},
		executeTime{executeTime}, arrivalTime{arrivalTime}
	{
		assert(this->id >= 0);
	}

	auto Process::operator = (Process const& process) -> Process&
	{
		this->id = process.id;
		this->priority = process.priority;
		this->executeTime = process.executeTime;
		this->arrivalTime = process.arrivalTime;
		this->waitTime = process.waitTime;
		this->endTime = process.endTime;

		return *this;
	}
}