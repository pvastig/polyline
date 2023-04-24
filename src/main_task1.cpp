#include <iostream>

#include "Utils.h"

int main(const int argc, char** argv)
{
	try
	{
		if (argc != 3)
		{
			throw std::invalid_argument("Wrong number of arguments, using: " + std::string(argv[0]) + " points.txt \"1 1 1\"");
		}

		pa::solveFirstTask(argv[1], argv[2]);

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
	catch (...)
	{
		std::cerr << "Unknown error";
	}

	return 1;
}
