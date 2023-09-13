#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main ()
{
   pid_t pid, pid2;
    for(int i = 1; i<3; i++){
    	pid = fork();
    	if (pid == -1)
    	{
			printf("No se ha podido crear el proceso hijo...");
			exit (-1);
    	}
    	if (pid == 0)   // Nos encontramos en el proceso hijo
		{
			printf ("Soy el hijo %d, mi padre es PID= %d, yo soy PID= %d\n",i , getppid(), getpid());
			if (i == 2){
				// Si es el hijo 2 crea un nuevo subproceso
				pid2 = fork();
				switch (pid2){
				case -1:
					printf("No se ha podido crear el proceso 3...");
					exit (-1);
					break;
				case 0:
					// Proceso hijo del proceso 2
					printf ("Soy el hijo 3, mi padre es PID= %d, yo soy PID= %d\n", getppid(), getpid());
					break;
				default:  // Proceso hijo que a la vez es padre
					wait (NULL);
				}
			}
			exit(0);
		}
    }
	//Por cada hijo que se crea el padre tiene que esperar
	wait(NULL);	
	wait(NULL);	
} 
	


