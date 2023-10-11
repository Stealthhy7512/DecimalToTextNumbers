#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cmath>
#include <map>

std::vector<std::vector<std::string>> decimals
{

	{"one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ",
				"fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "},

	{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}
};

std::string textify(int x) {

	std::string text{};

	if (x / 100 != 0) {
		text.append(decimals[0][x / 100 - 1]);
		text.append("hundred ");
		x %= 100;
	}
	if ((x / 10 != 0) && x >= 20) {
		text.append(decimals[1][x / 10 - 2]);
		text.append(" ");
		if (x % 10 != 0) {
			text.append("-");
			text.append(decimals[0][x % 10 - 1]);
		};
	}
	else {
		text.append(decimals[0][x - 1]);
	}

	return text;
}

std::string toText(long long int number)
{


	std::size_t i = std::to_string(number).length();
	std::string text{};

	if (number >= 1000) {

		if (number / 1'000 != 0) {
			text.append(textify(number % 1000));
			text.insert(0, "thousand ");
			text.insert(0, textify(number / 1000 % 1000));
			number /= 1'000'000;
		};

		if (number != 0) {
			text.insert(0, "million ");
			text.insert(0, textify(number % 1'000));
			number /= 1000;
		};

		if (number != 0) {
			text.insert(0, "billion ");
			text.insert(0, textify(number % 1'000));
		};
	}
	else {
		text.append(textify(number));
	};

		return text;
};

int main()
{
	long long int number{};
	do {
		std::cout << "Enter a number: ";
		std::cin >> number;
		if (0 <= number && number <= 999'999'999'999) {
			if (number == 0) {
				std::cout << "zero";
			}
			else {
				std::cout << toText(number) << std::endl;
			}
		}
		else {
			std::cerr << "Input out of range. Try again between 0-999'999'999'999\n" << std::endl;
		}
	} while (number < 0 || number > 999'999'999'999);
	
	

	return 0;
}