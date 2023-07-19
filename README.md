# polyline
Describes working with polyline in case of self-study. In order to compile the project compiler has to support C++20.

# how to compile

Command line:

1. Create folder build and go to there
2. Type cmake ..
3. Open solution polyline.sln

cmake-gui

1. Select root folder
2. Select folder where sources will be built
3. Configure soulution polyline.sln

4. #include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <unordered_map>
#include <set>
#include <regex>

void strTolower(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::tolower(c); } );
}

int main()
{
	const std::string words = "The time has come, the Warlis sad to talk of many things... aaa aaa b b b";
	std::map<std::string, int> wordsToCount;
	std::istringstream stream(words);
	const std::regex regex("\\w+");
	int num = 0;
	int num2 = 0;
	while (!stream.eof())
	{
		std::string str;
		stream >> str;
		strTolower(str);
		std::cout << ++num << '\n';

		for (std::sregex_iterator it(str.begin(), str.end(), regex), end; it != end; ++it)
		{
			std::cout << ++num << '\n';
			std::smatch match(*it);
			if (auto [it, inserted] = wordsToCount.try_emplace(match.str(), 1);
				!inserted)
			{
				++it->second;
			}
		}
	}

	std::multimap<int, std::string> values;
	std::set<int, std::greater<>> intValues;
	for (const auto& [str, count] : wordsToCount)
	{
		values.emplace(count, str);
		intValues.emplace(count);
	}
	
	using MapIterator = std::multimap<int, std::string>::iterator;
	std::vector<std::pair<MapIterator, MapIterator>> iters;

	for (auto num : intValues)
	{
		auto iterator = values.equal_range(num);
		iters.push_back(std::move(iterator));
	}

	for (const auto& item : iters)
	{
		for (auto it = item.first; it != item.second; ++it)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
}
