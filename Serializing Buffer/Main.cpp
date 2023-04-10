#include <Windows.h>

#include <iostream>

#include "Packet.h"

struct PacketHeader
{
	BYTE Code;
	BYTE Size;
	BYTE Type;
};

void mpCreateMyCharacter(CPacket* pPacket, DWORD id, BYTE dir, SHORT x, SHORT y)
{
	PacketHeader header;
	header.Code = 0x89;
	header.Size = sizeof(id) + sizeof(dir) + sizeof(x) + sizeof(y);
	header.Type = 1;

	pPacket->PutData(&header, sizeof(header));
	(*pPacket) << id << dir << x << y;
}

void ProcCreateMyCharacter(CPacket* pPacket)
{
	PacketHeader header;
	DWORD id;
	BYTE dir;
	SHORT x;
	SHORT y;

	pPacket->GetData(&header, sizeof(header));
	std::wcout << L"Header Code: " << header.Code << L" Size: " << header.Size << L" Type: " << header.Type << std::endl;

	(*pPacket) >> id >> dir >> x >> y;
	std::wcout << L"ID: " << id << L" Dir: " << dir << L" X: " << x << L" Y: " << y;
}

void Marshalling(CPacket& packet)
{
	CHAR a;
	UCHAR b;
	SHORT c;
	USHORT d;
	INT e;
	UINT f;
	LONG g;
	ULONG h;
	INT64 i;
	UINT64 j;
	BYTE k;
	WORD l;
	DWORD m;

	packet >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m;

	std::wcout << (int)a << L" " << (int)b << L" " << c << L" " << d << L" " << e << L" " << f << L" " 
		<< g << L" " << h << L" " << i << L" " << j << L" " << k << L" " << l << L" " << m << L"\n";

	if (packet.GetUseSize() != 45)
		__debugbreak();

	packet >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m;

	std::wcout << (int)a << L" " << (int)b << L" " << c << L" " << d << L" " << e << L" " << f << L" "
		<< g << L" " << h << L" " << i << L" " << j << L" " << k << L" " << l << L" " << m << L"\n";

	if (packet.GetUseSize() != 0)
		__debugbreak();
}

int wmain()
{
	CHAR a1 = CHAR_MIN;
	CHAR a2 = CHAR_MAX;

	UCHAR b1 = 0;
	UCHAR b2 = UCHAR_MAX;

	SHORT c1 = SHRT_MIN;
	SHORT c2 = SHRT_MAX;

	USHORT d1 = 0;
	USHORT d2 = USHRT_MAX;

	INT e1 = INT_MIN;
	INT e2 = INT_MAX;

	UINT f1 = 0;
	UINT f2 = UINT_MAX;

	LONG g1 = LONG_MIN;
	LONG g2 = LONG_MAX;

	ULONG h1 = 0;
	ULONG h2 = ULONG_MAX;

	INT64 i1 = INT64_MIN;
	INT64 i2 = INT64_MAX;

	UINT64 j1 = 0;
	UINT64 j2 = UINT64_MAX;

	BYTE k1 = 0;
	BYTE k2 = 0xff;

	WORD l1 = 0;
	WORD l2 = 0xffff;

	DWORD m1 = 0;
	DWORD m2 = 0xffffffff;

	CPacket packet;

	packet << a1 << b1 << c1 << d1 << e1 << f1 << g1 << h1 << i1 << j1 << k1 << l1 << m1;

	if (packet.GetUseSize() != 45)
		__debugbreak();

	packet << a2 << b2 << c2 << d2 << e2 << f2 << g2 << h2 << i2 << j2 << k2 << l2 << m2;

	if (packet.GetUseSize() != 90)
		__debugbreak();

	Marshalling(packet);

	packet.Clear();

	mpCreateMyCharacter(&packet, 1, 2, 200, 300);

	ProcCreateMyCharacter(&packet);

	return 0;
}
