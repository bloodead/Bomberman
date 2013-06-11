#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	checkfile(int fd,char* buff)
{
	return read(fd,buff,1);

}

void	checkmap()
{
	int	fd;
	char	buff;

	fd = open("./src.txt",0);

	while(checkfile(fd,&buff) != 0)
		printf("%c \n",buff);

}
