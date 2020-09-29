#include <SFML/Network.hpp>
#include <vector>
#include <iostream>
#include <thread>

namespace PortScanner
{
	const std::string ADDRESS_MESSAGE = "Network Address: ";
	const std::string PORT_MESSAGE = "Port: ";

	bool IsTCPSocketOpen(const std::string& ADDRESS, const unsigned short PORT) // The port is 16 bit. A reference is 64 bit, so we pass by value.
	{
		return (sf::TcpSocket().connect(ADDRESS, PORT) == sf::TcpSocket::Done);
	}

	std::string GetAddressFromUser()
	{
		std::cout << ADDRESS_MESSAGE;
		std::string userString;
		std::cin >> userString;
		return userString;
	}

	unsigned short GetPortFromUser()
	{
		std::cout << PORT_MESSAGE;
		unsigned short port;
		std::cin >> port;
		return port;
	}

	int Start()
	{
		const std::string ADDRESS = GetAddressFromUser();
		const unsigned short PORT = GetPortFromUser();
		if (IsTCPSocketOpen(ADDRESS, PORT))
		{
			std::cout << "OPEN\n";
		}
		else
		{
			std::cout << "CLOSED\n";
		}
		return 0;
	}
}

int main()
{
	PortScanner::Start();
	return 0;
}