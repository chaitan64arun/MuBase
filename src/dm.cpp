#include "dm.h"

int DiskManager::getTotNoBlocks(){
   	return totNoBlocks;
}

void DiskManager::createDB(const char *dbName, int initialNumBlocks){

   	totNoBlocks = initialNumBlocks;
   	char stmt[50];
   	sprintf(stmt,"fallocate -l %d %s", 
			initialNumBlocks*BLOCK_SIZE,dbName);
   	system(stmt); 
}
   
void DiskManager::openDB(const char *dbName){
    	
   	try{
		dbPtr= fopen(dbName,"r+");
   		if (dbPtr == NULL)
   			throw exception();
   	}
   	catch(exception &){
   		cout << "Exception raised:";
		cout<<"File to be opened doesnot exist "<<endl;
	}    	
    }

void DiskManager::rawWrite(const char *dbName,
						 int blockId, char *buff){
	try{
		if (dbPtr == NULL)
			throw exception();

		fseek(dbPtr, blockId*BLOCK_SIZE, SEEK_SET);
		fwrite(buff,1,BLOCK_SIZE,dbPtr);
	}
	catch(exception &){
		cout << "Exception raised:";
		cout <<" File to be editted (rawWrite) doesnot exist "<<endl;
		}
}

void DiskManager::rawRead (const char *dbName,
							 int blockId, char *buff){
	try{
		if (dbPtr == NULL)
			throw exception();
		
		fseek(dbPtr, blockId*BLOCK_SIZE, SEEK_SET);
		fread(buff,BLOCK_SIZE,1,dbPtr);
	}
	catch(exception &){
		cout << "Exception raised:";
		cout<<" File to be read (rawRead) doesnot exist "<<endl;
	}
}

void DiskManager::closeDB(const char *dbName){
	try{
		if (dbPtr == NULL)
			throw exception();
		fclose(dbPtr);
	}
	catch(exception &){
			cout << "Exception raised:";
			cout <<" File to be closed doesnot exist "<<endl;
	}    	
}
FILE *DiskManager::dbPtr = NULL;
