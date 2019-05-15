// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <errno.h>
#include <sys/types.h>
#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>


#define TRUE   1
#define FALSE  0

#define PORT 8080

using namespace std;
class Client {
public:
	Client();
	~Client();
	void sendS(FString message);
	string receiveS();
	void close();
private:
	//char buffer[2048];
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;

};
