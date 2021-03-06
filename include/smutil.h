#ifndef SMUTIL_H
#define SMUTIL_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/**
 * Reads a 4 byte int value at block + offswt
 */
int readInt(char *block, short offset);

/**
 * Writes a 4 byte int value at block + offset
 */
void writeInt(char *block, short offset, int value);

/**
 * Writes a fragment in the byte array
 */
void writeBytes(char *block, short offset, char *rec);

/**
 * Returns a fragment of the byte array
 */
char *readBytes(char *block, short recOffset, short recLength);

/**
 * moves chunks of bytes from src char* to destination char*
 */ 
void moveBytes(char *offsetInSrcLeaf, 
				char *offsetInDestLeaf, 
				short chunkLength);

/**
 * makes the block compact after something in middle is removed
 */ 
void makeCompact(char *diskFirstblock, short destOffset, 
				short sourceOffset, short chunkLength);
#endif
