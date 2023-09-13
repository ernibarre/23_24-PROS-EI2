#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main ()
{
   pid_t pid;
   int num = 6;
	printf("Valor inicial de la variable: %d\n",num);
	pid = fork();
	if (pid == -1)
	{
		printf("No se ha podido crear el proceso hijo...");
		exit (-1);
	}
	if (pid == 0) // Nos encontramos en el proceso hijo
	{
		printf ("Variable en proceso hijo: %d\n",num-5);
	}else{
		// Nos encontramos en el proceso padre
		wait(NULL);	
		printf ("Variable en proceso padre: %d\n",num+5);
		exit(0);
	}
		
} 
	


