// Fill out your copyright notice in the Description page of Project Settings.


#include "Client.h"

Client::Client()
{
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("192.168.43.61"); // replace the ip with your futur server ip address. If server AND client are running on the same computer, you can use the local ip 127.0.0.1
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));
	//cout << "Connected to server!" << endl;

	char buffer[2048] = { 'h', 'e', 'l', 'l', 'o', '.' };
	send(server, buffer, sizeof(buffer), 0);
	recv(server, buffer, sizeof(buffer), 0);
	cout << "Message sent!" << endl;
}

Client::~Client()
{
}

void Client::sendS(FString message) {
	auto twoHundredAnsi = StringCast<ANSICHAR>(*message);
	const char* buffer = twoHundredAnsi.Get();
	send(server, buffer, sizeof(buffer), 0);
}

FString Client::receiveS() {
	char buffer[2048];
	recv(server, buffer, sizeof(buffer), 0);
	FString Fs = FString(ANSI_TO_TCHAR(buffer));
	return Fs;
}

void Client::close(){
	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;
}
