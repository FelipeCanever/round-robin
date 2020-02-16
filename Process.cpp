#include "Process.hpp"

#include <cassert>

namespace roundRobin
{
	int Process::numberOfProcesses = 0;

	Process::Process(Priority const priority, Time const executeTime, Time const arrivalTime):
		_id{this->numberOfProcesses++},
		_priority{priority},
		_executeTime{executeTime}, _arrivalTime{arrivalTime}
	{
		assert(this->id() >= 0);
	}

	auto Process::id() const -> int
	{
		return this->_id;
	}

	auto Process::priority() const -> Priority
	{
		return this->_priority;
	}

	auto Process::priority(Priority const priority) -> void
	{
		this->_priority = priority;
	}

	auto Process::executeTime() const -> Time
	{
		return this->_executeTime;
	}

	auto Process::arrivalTime() const -> Time
	{
		return this->_arrivalTime;
	}
}