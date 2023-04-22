#include <filesystem>
#include <iostream>

#include "Utils.h"

int main(const int argc, char** argv)
{
	try
	{
		if (argc != 3)
		{
			throw std::invalid_argument("2 arguments should be input: file with polyline points and coordinates of the point to be projected.");
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
