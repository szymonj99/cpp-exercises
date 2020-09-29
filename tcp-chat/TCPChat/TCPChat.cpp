#include <thread>
#include <string>
#include <iostream>
#include <cmath>
#include <SFML/Network.hpp>

namespace TCPChat
{
	constexpr int BUFFER_SIZE = 1024;

	// The LocalUser class represents the current user that is using the program.
	// The LocalUser will encrypt their message with the RemoteUser's public key.
	// The LocalUser will decrypt the RemoteUser's message with LocalUser's private key.
	class LocalUser
	{
	private:
		std::string m_privateKey;

	public:
		std::string AskForRemoteUserAddress() const
		{
			std::cout << "Please input the address of the other person you wish to talk with: ";
			std::string address;
			std::cin >> address;
			return address;
		}

		unsigned short AskForRemoteUserPort() const
		{
			std::cout << "Please input the port (1-65535): ";
			unsigned short port;
			std::cin >> port;
			return port;
		}

		void SetPrivateKey(const std::string PRIVATE_KEY)
		{
			this->m_privateKey = PRIVATE_KEY;
		}

		std::string AskForPrivateKey() const
		{
			std::cout << "Please input your private key: ";
			std::string privateKey;
			std::cin >> privateKey;
			return privateKey;
		}

		const std::string GetPrivateKey() const
		{
			return this->m_privateKey;
		}
	};

	// The RemoteUser class represents the other user that LocalUser will exchange messages with.
	// The RemoteUser will encrypt their message with the LocalUser's public key.
	// The RemoteUser will decrypt the LocalUser's message with RemoteUser's private key.
	class RemoteUser
	{
	private:
		std::string m_publicKey;
		std::string m_address;
		unsigned short m_port = 0;

	public:
		const std::string GetAddress() const
		{
			return this->m_address;
		}
		void SetAddress(const std::string& ADDRESS)
		{
			this->m_address = ADDRESS;
		}

		const unsigned short GetPort() const
		{
			return this->m_port;
		}
		void SetPort(const unsigned short PORT)
		{
			this->m_port = PORT;
		}

		void SetPublicKey(const std::string PUBLIC_KEY)
		{
			this->m_publicKey = PUBLIC_KEY;
		}
		const std::string GetPublicKey() const
		{
			return this->m_publicKey;
		}
	};

	// Check if the port on the specified address is open.
	const bool IsPortOpen(const std::string& ADDRESS, const unsigned short PORT)
	{
		return (sf::TcpSocket().connect(ADDRESS, PORT) == sf::Socket::Done);
	}

	void BeginReceivingMessages(const unsigned short REMOTE_PORT, sf::TcpListener& receiver)
	{
		// Create a receiver to wait for incoming connections.
		//sf::TcpListener receiver;
		receiver.listen(REMOTE_PORT);

		// Wait for a connection
		sf::TcpSocket connection;
		receiver.accept(connection);

		//std::cout << "Client " << connection.getRemoteAddress() << " connected." << std::endl;

		while (true)
		{
			char buffer[BUFFER_SIZE];
			std::size_t received = 0;
			connection.receive(buffer, sizeof(buffer), received);
			std::cout << "Remote user said: " << buffer << std::endl;
		}
	}

	void BeginSendingMessages(const std::string& REMOTE_ADDRESS, const unsigned short REMOTE_PORT)
	{
		// Create a socket and connect it to the remote user address and port
		sf::TcpSocket socket;
		socket.connect(REMOTE_ADDRESS, REMOTE_PORT);

		while (true)
		{
			std::string message;
			std::cin >> message;
			socket.send(message.c_str(), message.size() + 1);
			//std::cout << "Message sent: " << message << std::endl;
		}
	}
}

int main()
{
	// The localUser is the user that interacts with the application on the computer that is running the application.
	TCPChat::LocalUser localUser;
	// The remoteUser is the user that the localUser wants to interact with on a different machine.
	TCPChat::RemoteUser remoteUser;

	// On launch, ask the LocalUser for the RemoteUser address and port.
	remoteUser.SetAddress(localUser.AskForRemoteUserAddress());
	remoteUser.SetPort(localUser.AskForRemoteUserPort());

	// Create socket before attempting to establish any connections.
	// This ensures the port is open and listening and can be accessed over the network.
	sf::TcpListener listener;
	listener.listen(remoteUser.GetPort());

	// Then check if the port is open.
	if (!TCPChat::IsPortOpen(remoteUser.GetAddress(), remoteUser.GetPort()))
	{
		std::cout << "The port is not open.\n";
		return 0;
	}
	else
	{
		std::cout << "The port is open.\n";		
	}

	// Create a thread to send messages.
	std::thread sendThread(TCPChat::BeginSendingMessages, remoteUser.GetAddress(), remoteUser.GetPort());

	// Create a thread to receive messages.
	std::thread receiveThread (TCPChat::BeginReceivingMessages, remoteUser.GetPort(), std::ref(listener));
	
	std::cout << "You can now send and receive messages." << std::endl;

	receiveThread.join();
	sendThread.join();

	return 0;
}