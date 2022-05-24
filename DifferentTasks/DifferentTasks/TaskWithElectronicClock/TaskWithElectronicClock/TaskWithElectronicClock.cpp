#include <iostream>
#include <windows.h> 
#include <conio.h>
#include<iomanip>

static size_t getUserInput();

class ElectronicClock
{
private:
	SYSTEMTIME m_localtime;
public:
	ElectronicClock() = default;

	SYSTEMTIME getTime()
	{
		return m_localtime;
	}

	void GetMyLocalTime()
	{
		GetLocalTime(&m_localtime);
	}

	friend std::ostream& operator<< (std::ostream& out, const ElectronicClock& electronicClock);
};

std::ostream& operator<< (std::ostream& out, const ElectronicClock& electronicClock)
{
	static char symbol = ':';

	out << " " << std::setw(2) << std::setfill('0') << electronicClock.m_localtime.wHour << symbol
		<< std::setw(2) << std::setfill('0') << electronicClock.m_localtime.wMinute << symbol
		<< std::setw(2) << std::setfill('0') << electronicClock.m_localtime.wSecond;

	symbol = symbol == ':' ? ' ' : ':';

	return out;
}

int main()
{
	ElectronicClock localTime;

	localTime.GetMyLocalTime();

	std::cout << localTime << std::endl;

	size_t minutes = getUserInput();

	size_t minutesForStop = localTime.getTime().wMinute + minutes;

	size_t secondsForStop = localTime.getTime().wSecond;

	while (!_kbhit())
	{
		localTime.GetMyLocalTime();

		std::cout << localTime << '\r';

		Sleep(1000);

		if ((localTime.getTime().wMinute == minutesForStop) && (localTime.getTime().wSecond == secondsForStop))
		{
			break;
		}
	}

	return 0;
}

size_t getUserInput()
{
	size_t minutes = 0;

	std::cout << "Enter minutes: ";

	std::cin >> minutes;

	return minutes;
}