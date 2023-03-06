#pragma once

class Packet
{
public:
	Packet() {}
	~Packet() {}

	void Clear()
	{
		m_pFront = m_buffer;
		m_pRear = m_buffer;
	}

	int GetBufferSize() {
		return m_bufferSize;
	}

	int GetDataSize() {
		return m_dataSize;
	}

	char* GetBufferPtr() { return m_buffer; }

	int MoveFront(int size);
	int MoveRear(int size);

	int GetData(void* dst, int size);
	int PutData(void* src, int size);

	Packet& operator =(Packet& srcPacket);

	Packet& operator <<(unsigned __int8 value)
	{
		*(unsigned __int8*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int8 value)
	{
		*(__int8*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}

	Packet& operator <<(unsigned __int16 value)
	{
		*(unsigned __int16*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int16 value)
	{
		*(__int16*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}

	Packet& operator <<(unsigned __int32 value)
	{
		*(unsigned __int32*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int32 value)
	{
		*(__int32*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator << (float value)
	{
		*(float*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(long value)
	{
		*(long*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(unsigned long value)
	{
		*(unsigned long*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}

	Packet& operator <<(unsigned __int64 value)
	{
		*(unsigned __int64*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(__int64 value)
	{
		*(__int64*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}
	Packet& operator <<(double value)
	{
		*(double*)m_pRear = value;
		m_pRear += sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int8& value)
	{
		value = *(unsigned __int8*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}
	Packet& operator >>(__int8& value)
	{
		value = *(__int8*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int16 value) {
		value = *(unsigned __int16*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}
	Packet& operator >>(__int16 value)
	{
		value = *(__int16*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int32 value)
	{
		value = *(unsigned __int32*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}
	Packet& operator >>(__int32 value)
	{
		value = *(__int32*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}
	Packet& operator >> (float value)
	{
		value = *(float*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}

	Packet& operator >>(unsigned __int64 value)
	{
		value = *(unsigned __int64*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}
	Packet& operator >>(__int64 value)
	{
		value = *(__int64*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}
	Packet& operator >>(double value)
	{
		value = *(double*)m_pFront;
		m_pFront += sizeof(value);
		return *this;
	}


private:
	constexpr static int DEFAULT_BUFFER_SIZE = 1400;

	char m_buffer[DEFAULT_BUFFER_SIZE];
	char* m_pFront = m_buffer;
	char* m_pRear = m_buffer;
	int m_bufferSize = DEFAULT_BUFFER_SIZE;
	int m_dataSize = 0;
};

