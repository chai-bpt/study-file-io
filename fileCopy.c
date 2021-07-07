#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BUF_SIZE 1024
int main(int argc, char* argv[])
{
	int fdSource = 0;
	int fdDest = 0;

	int readByteCount = 0;

	unsigned char buf[BUF_SIZE] = {0};

	// argument sanity check
	
	fdSource = open(argv[1], O_RDONLY, 0666);
	// error handling
	
	fdDest = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666);
	// error handling
	
	while(1)
	{
		readByteCount = read(fdSource, buf, BUF_SIZE);
		if(readByteCount <= 0)
			break;
		write(fdDest, buf, readByteCount);
		// error handling
	}

	close(fdSource);
	// error handling
	close(fdDest);
	// error handling
	return 0;
}
