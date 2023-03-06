#pragma once

#include <memory.h>

class Packet
{
public:
	Packet()
	{
		Init(DEFAULT_BUFFER_SIZE);
	}

	Packet(int bufferSize)
	{
		Init(bufferSize);
	}

	~Packet()
	{
		delete[] m_pExtendedBuffer;
	}

	void Clear()
	{
		m_pReadPos = m_pBuffer;
		m_pWritePos = m_pBuffer;

		m_useSize = 0;
	}

	int GetBufferSize() 
	{
		return m_bufferSize;
	}

	int GetUseSize() 
	{
		return m_useSize;
	}

	char* GetBufferPtr() 
	{ 
		return m_pBuffer; 
	}

	int MoveReadPos(int size)
	{
		if (size > m_useSize)
			size = m_useSize;

		m_pReadPos += size;
		m_useSize -= size;
		return size;

	}
	int MoveWritePos(int size)
	{
		int freeSize = m_bufferSize - m_useSize;
		if (size > freeSize)
			size = freeSize;

		m_pWritePos += size;
		m_useSize += size;
		return size;
	}

	int GetData(void* dst, int size)
	{
		if (m_useSize < size)
			size = m_useSize;

		memcpy(dst, m_pReadPos, size);
		m_pReadPos += size;
		m_useSize -= size;

		return size;
	}

	int PutData(void* src, int size)
	{
		int freeSize = m_bufferSize - m_useSize;
		if (freeSize < size)
			size = freeSize;

		memcpy(m_pWritePos, src, size);
		m_pWritePos += size;
		m_useSize += size;

		return size;
	}

	//Packet& operator =(Packet& srcPacket);

	Packet& operator <<(unsigned __int8 value)
	{
		*(unsigned __int8*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int8 value)
	{
		*(__int8*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}

	Packet& operator <<(unsigned __int16 value)
	{
		*(unsigned __int16*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int16 value)
	{
		*(__int16*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}

	Packet& operator <<(unsigned __int32 value)
	{
		*(unsigned __int32*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int32 value)
	{
		*(__int32*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator << (float value)
	{
		*(float*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(long value)
	{
		*(long*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(unsigned long value)
	{
		*(unsigned long*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}

	Packet& operator <<(unsigned __int64 value)
	{
		*(unsigned __int64*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int64 value)
	{
		*(__int64*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}
	Packet& operator <<(double value)
	{
		*(double*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int8& value)
	{
		value = *(unsigned __int8*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(__int8& value)
	{
		value = *(__int8*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int16& value) {
		value = *(unsigned __int16*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(__int16& value)
	{
		value = *(__int16*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int32& value)
	{
		value = *(unsigned __int32*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(__int32& value)
	{
		value = *(__int32*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >> (float& value)
	{
		value = *(float*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(long& value)
	{
		value = *(long*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(unsigned long& value)
	{
		value = *(unsigned long*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int64& value)
	{
		value = *(unsigned __int64*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(__int64& value)
	{
		value = *(__int64*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}
	Packet& operator >>(double& value)
	{
		value = *(double*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}

private:
	void Init(int bufferSize)
	{
		m_bufferSize = bufferSize;
		m_useSize = 0;

		if (DEFAULT_BUFFER_SIZE < m_bufferSize)
		{
			m_pExtendedBuffer = new char[m_bufferSize];
			m_pBuffer = m_pExtendedBuffer;			
		}
		else
		{
			m_pExtendedBuffer = nullptr;			
			m_pBuffer = m_defaultBuffer;			
		}

		m_pEndOfBuffer = m_pBuffer + m_bufferSize;

		m_pReadPos = m_pBuffer;
		m_pWritePos = m_pBuffer;
	}

	template <typename T>
	Packet& Input(T value)
	{
		*(T*)m_pWritePos = value;
		m_pWritePos += sizeof(value);
		m_useSize += sizeof(value);
		return *this;
	}

	template <typename T>
	Packet& OperatorOut(T& value)
	{
		value = *(T*)m_pReadPos;
		m_pReadPos += sizeof(value);
		m_useSize -= sizeof(value);
		return *this;
	}

private:
	constexpr static int DEFAULT_BUFFER_SIZE = 1400;

	char m_defaultBuffer[DEFAULT_BUFFER_SIZE];
	char* m_pExtendedBuffer;

	char* m_pBuffer;
	char* m_pEndOfBuffer;

	char* m_pReadPos;
	char* m_pWritePos;

	int m_bufferSize;
	int m_useSize;
};

