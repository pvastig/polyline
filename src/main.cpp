#include <filesystem>
#include <iostream>

#include "Utils.h"

int main(const int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "2 arguments should be input: file with polyline points and coordinates of the point to be projected.";
		return 1;
	}

	const std::filesystem::path file(argv[1]);
	if (!std::filesystem::exists(file))
	{
		std::cerr << file << "does not exist";
		return 1;
	}

	pa::solveFirstTask(file.string(), argv[2]);

	return 0;
}
