#include <iostream>

#include "Utils.h"

int main(const int argc, char** argv)
{
	try
	{
		if (argc != 2)
		{
			throw std::invalid_argument("Wrong number of arguments, using: " + std::string(argv[0]) + " points.txt");
		}

		pa::solveSecondTask(argv[1]);

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