#pragma once
class ComputerStore
{
	public:

	ComputerStore();
	ComputerStore(const char* name, Computer** computers, size_t count);

	char* getName();
	size_t getCount();
	void setName(const char* name);
	void setCount(size_t count);
	void appendComputer(Computer* computer);
	void deleteComputer(Computer* computer);
	void deleteComputer(Computer** computers, size_t len, Computer* computer);
	void deleteComputerById(size_t id);
	Computer* getComputerById(size_t id);
	void clearComputerStore();
	void printComputersRAMGreaterThan(short min);
	void printComputersYearBetween(size_t minYear, size_t maxYear);
	Computer** getComputersByColor(const char* color);

	private:

	static size_t _staticId;
	size_t _id;
	char* _name;
	Computer** _computers;
	size_t _len;
};

size_t ComputerStore::_staticId = 0;

inline ComputerStore::ComputerStore()
{
	_id = ++_staticId;
	_name = nullptr;
	_computers = nullptr;
	_len = 0;
}

inline ComputerStore::ComputerStore(const char* name, Computer** computers, size_t count)
	:ComputerStore()
{
	setName(name);
	setCount(count);
	_computers = computers;
}

inline char* ComputerStore::getName() { return _name; }

inline size_t ComputerStore::getCount() { return _len; }

inline void ComputerStore::setName(const char* name)
{
	if (name == nullptr)
		assert(!"Name can't be null");
	if (_name != nullptr)
		delete[] _name;
	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}

inline void ComputerStore::setCount(size_t count)
{
	if (true)
	{
		_len = count;
		return;
	}
}

inline void ComputerStore::appendComputer(Computer* computer)
{
	if (_computers == nullptr)
	{
		_computers = new Computer * [_len + 1] {computer};
		return;
	}
	for (size_t i = 0; i < _len; i++)
	{
		if (_computers[i] == computer)
			assert(!"Computer already exits");
	}
	Computer** computers = new Computer * [_len + 1];
	for (size_t i = 0; i < _len; i++)
	{
		computers[i] = _computers[i];
	}
	computers[_len] = computer;
	_len++;
	delete[] _computers;
	_computers = computers;
}

inline void ComputerStore::deleteComputer(Computer* computer)
{
	if (_computers == nullptr)
		assert(!"Computer not exits");
	bool temp = true;
	for (size_t i = 0; i < _len; i++)
	{
		if (_computers[i] == computer)
		{
			temp = false;
			delete _computers[i];
			_computers[i] = nullptr;
			break;
		}
	}
	if (temp)
		assert(!"Computer not exits");
	Computer** computers = new Computer * [_len - 1];
	for (size_t i = 0; i < _len - 1; i++)
	{
		if (_computers[i] == nullptr)
			temp++;
		computers[i] = _computers[i + temp];
	}
	_len--;
	delete[] _computers;
	_computers = computers;
}

inline void ComputerStore::deleteComputer(Computer** computers, size_t len, Computer* computer)
{
	if (computers == nullptr)
		assert(!"Computer not exits");
	bool temp = true;
	for (size_t i = 0; i < len; i++)
	{
		if (computers[i] == computer)
		{
			temp = false;
			delete computers[i];
			computers[i] = nullptr;
			break;
		}
	}
	if (temp)
		assert(!"Computer not exits");
	Computer** tempcomputers = new Computer * [len - 1];
	for (size_t i = 0; i < len - 1; i++)
	{
		if (computers[i] == nullptr)
			temp++;
		tempcomputers[i] = computers[i + temp];
	}
	len--;
	delete[] computers;
	computers = tempcomputers;
}

inline void ComputerStore::deleteComputerById(size_t id)
{
	if (_computers == nullptr)
		assert(!"Computer not exits");
	for (size_t i = 0; i < _len; i++)
	{
		if (_computers[i]->getId() == id)
			return deleteComputer(_computers[i]);
	}
}

inline Computer* ComputerStore::getComputerById(size_t id)
{
	if (_computers == nullptr)
		assert(!"Computer not exits");
	for (size_t i = 0; i < _len; i++)
	{
		if (_computers[i]->getId() == id)
			return _computers[i];
	}
	assert(!"Computer not exits");
}

inline void ComputerStore::clearComputerStore()
{
	if (_computers == nullptr)
		return;
	for (size_t i = 0; i < _len; i++)
	{
		delete _computers[i];
		_computers[i] = nullptr;
	}
	delete[] _computers;
	_computers = nullptr;
	_len = 0;
}

inline void ComputerStore::printComputersRAMGreaterThan(short min)
{
	for (size_t i = 0; i < _len; i++)
	{
		if (_computers[i]->getRam() >= min)
		{
			_computers[i]->print();
		}
	}
}

inline void ComputerStore::printComputersYearBetween(size_t minYear, size_t maxYear)
{
	for (size_t i = 0; i < _len; i++)
	{
		if (_computers[i]->getYear() >= minYear && _computers[i]->getYear() <= minYear)
		{
			_computers[i]->print();
		}
	}
}

inline Computer** ComputerStore::getComputersByColor(const char* color)
{
	short lenght = 0;
	Computer** computers = new Computer * [lenght];
	for (size_t i = 0; i < _len; i++)
	{
		if (!strcmp(_computers[i]->getColor(), color))
		{
			lenght++;
			Computer** tempComputers = new Computer * [lenght];
			for (size_t j = 0; j < lenght; j++)
			{
				tempComputers[j] = computers[j];
			}
			tempComputers[lenght - 1] = _computers[i];
			delete[] computers;
			computers = tempComputers;
		}
	}
	return computers;
}