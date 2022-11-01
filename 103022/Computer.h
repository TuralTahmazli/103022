#pragma once
class Computer
{
	public:

	Computer();
	Computer(const char* model, const char* color, size_t year, const char* CPU, short RAM, size_t space);
	~Computer();

	size_t getId();
	char* getModel();
	char* getColor();
	size_t getYear();
	char* getCpu();
	short getRam();
	size_t getSpace();
	void setModel(const char* model);
	void setColor(const char* color);
	void setYear(size_t year);
	void setCpu(const char* CPU);
	void setRam(short RAM);
	void setSpace(size_t space);
	void print();

	private:

	static size_t _staticId;
	size_t _id;
	char* _model;
	char* _color;
	size_t _year;
	char* _CPU;
	short _RAM;
	size_t _space;
};

size_t Computer::_staticId = 0;

inline Computer::Computer()
{
	_id = ++_staticId;
	_model = nullptr;
	_color = nullptr;
	_year = 0;
	_CPU = nullptr;
	_RAM = 0;
	_space = 0;
}

inline Computer::Computer(const char* model, const char* color, size_t year, const char* CPU, short RAM, size_t space)
	:Computer()
{
	setModel(model);
	setColor(color);
	setYear(year);
	setCpu(CPU);
	setRam(RAM);
	setSpace(space);
}

inline Computer::~Computer()
{
	delete[] _model;
	delete[] _color;
	delete[] _CPU;
	_model = _color = _CPU = nullptr;
}

inline size_t Computer::getId() { return _id; }

inline char* Computer::getModel() { return _model; }

inline char* Computer::getColor() { return _color; }

inline size_t Computer::getYear() { return _year; }

inline char* Computer::getCpu() { return _CPU; }

inline short Computer::getRam() { return _RAM; }

inline size_t Computer::getSpace() { return _space; }

inline void Computer::setModel(const char* model)
{
	if (model == nullptr)
		assert(!"Model can't be null");
	if (_model != nullptr)
		delete[] _model;
	size_t len = strlen(model) + 1;
	_model = new char[len];
	strcpy_s(_model, len, model);
}

inline void Computer::setColor(const char* color)
{
	if (color == nullptr)
		assert(!"Color can't be null");
	if (_color != nullptr)
		delete[] _color;
	size_t len = strlen(color) + 1;
	_color = new char[len];
	strcpy_s(_color, len, color);
}

inline void Computer::setYear(size_t year)
{
	if (true)
	{
		_year = year;
		return;
	}
}

inline void Computer::setCpu(const char* CPU)
{
	if (CPU == nullptr)
		assert(!"Cpu can't be null");
	if (_CPU != nullptr)
		delete[] _CPU;
	size_t len = strlen(CPU) + 1;
	_CPU = new char[len];
	strcpy_s(_CPU, len, CPU);
}

inline void Computer::setRam(short RAM)
{
	if (true)
	{
		_RAM = RAM;
		return;
	}
}

inline void Computer::setSpace(size_t space)
{
	if (true)
	{
		_space = space;
		return;
	}
}

inline void Computer::print()
{
	cout << "id" << _id << '\n';
	cout << "model" << _model << '\n';
	cout << "color" << _color << '\n';
	cout << "year" << _year << '\n';
	cout << "CPU" << _CPU << '\n';
	cout << "RAM" << _RAM << '\n';
	cout << "space" << _space << '\n';
}