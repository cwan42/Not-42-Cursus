#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_access(int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (access("test1.txt", R_OK) != -1)
		printf("I have permission\n");
	else
		printf("I don't have permission\n");
}

int	main()
{
	int	fd;
	int	origstdout;

	fd = open("test1.txt", O_WRONLY | O_CREAT, 0644);
	origstdout = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("EXAMPLE TO BE PUT IN!\n");
	ft_access(origstdout);
}

/*
	Works because open opens an fd to create test1.txt
	close fd, but reference to fd still exists via STDOUT redirect, hence printf returns to it.
	Need to close last fd reference to close completely.
*/
