#include <iostream>
#include <string>

using namespace std;


std::string itoa(int value, unsigned int base) {
	const char digitMap[] = "0123456789abcdef";
	std::string buf;

	// Guard:
	if (base == 0 || base > 16)
    {
		// Error: may add more trace/log output here
		return buf;
	}

	// Take care of negative int:
	std::string sign;
	int _value = value;

	// Check for case when input is zero:
	if (_value == 0) return "0";
	if (value < 0)
	{
		_value = -value;
		sign = "-";
	}

	// Translating number to string with base:
	for (int i = 30; _value && i ; --i)
    {
		buf = digitMap[ _value % base ] + buf;
		_value /= base;
	}

	return sign.append(buf);
}

int main()
{
    int input, base;

    cout << "Input int: ";
    cin >> input;

    cout << "What base do you want to convert to?";
    cin >> base;

    cout << to_string(input) + " as base " + to_string(base) +  ": " + itoa(input, base) + "\n";

    return 0;
}
