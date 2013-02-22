#include "memoryblock.h"

#include <fstream>

dung::MemoryBlock::MemoryBlock()
	: pBlock()
	, size()
{
}

dung::MemoryBlock::MemoryBlock( size_t size )
	: pBlock()
	, size( size )
{
	pBlock = SCARAB_NEW Byte_t[ size ];
}

dung::MemoryBlock::~MemoryBlock()
{
	delete[] pBlock;
}

bool dung::Equals( MemoryBlock const& block1, MemoryBlock const& block2 )
{
	if( block1.size != block2.size )
		return false;

	return memcmp( block1.pBlock, block2.pBlock, block1.size ) == 0;
}

bool dung::ReadWholeFile( String_t const& fullPath, MemoryBlock& memoryBlock )
{
	std::ifstream file ( fullPath, std::ios::in|std::ios::binary|std::ios::ate );
	if( !file.is_open() )
		return false;

	memoryBlock.size = (size_t)file.tellg();

	memoryBlock.pBlock = SCARAB_NEW Byte_t [memoryBlock.size];

	file.seekg( 0, std::ios::beg );
	file.read( (char*)memoryBlock.pBlock, memoryBlock.size );
	file.close();

	return true;
}

bool dung::WriteWholeFile( String_t const& fullPath, MemoryBlock& memoryBlock )
{
	std::ofstream file ( fullPath, std::ios::out|std::ios::binary|std::ios::trunc );
	if( !file.is_open() )
		return false;

	file.write( (const char*)memoryBlock.pBlock, memoryBlock.size );
	file.close();
	return true;
}
