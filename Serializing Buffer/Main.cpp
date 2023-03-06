#include <Windows.h>

#include "Packet.h"

int wmain()
{
	DWORD id = 3;
	BYTE dir = 1;
	SHORT x = 200;
	SHORT y = 300;

	Packet packet;

	packet << id << dir << x << y;

	return 0;
}
