#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main ()
{
    pid_t pid;
    for(int i = 1; i<4; i++){
    	pid = fork();
    	if (pid == -1)
    	{
			printf("No se ha podido crear el proceso hijo...");
			exit (-1);
    	}
    	if (pid == 0)   ////////// Nos encontramos en el proceso hijo
		{
			printf ("Soy el hijo %d, Mi padre es %d y mi PID es %d\n",i , getppid(), getpid());
			exit(0);
		}
    }
	//Por cada hijo que se crea el padre tiene que esperar para que no salga el primero
	wait(NULL);	
	wait(NULL);	
	wait(NULL);	
	// No tienes que usar el getppid porque los que hablan antes son los hijos entonces el pid es el padre
	printf ("\nProceso padre %d\n", getpid());
}


