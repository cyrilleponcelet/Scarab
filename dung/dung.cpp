#include "dung.h"

namespace dung
{
	static const wchar_t WREGISTRY_FILENAME[] = L"registry.txt";
	static const char REGISTRY_FILENAME[] = "registry.txt";
}

dung::nil_buf::nil_buf()
{
}

dung::nil_buf::~nil_buf()
{
}

int dung::nil_buf::overflow( int c_ )
{
	return 0;
}

int dung::nil_buf::sync()
{
	return 0;
}

void dung::nil_buf::put_buffer()
{
}

void dung::nil_buf::put_char( int c_ )
{
}


