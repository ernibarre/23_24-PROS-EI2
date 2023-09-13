#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main ()
{
    pid_t pid;
	int numChild = 4;

    for(int i = 0; i<=numChild; i++){
    	pid = fork();
    	if (pid == -1)
    	{
			printf("No se ha podido crear el proceso hijo...");
			exit (-1);
    	} 
		
		if (pid != 0){
			// Nos encontramos en el proceso padre
			pid = wait(NULL);
			//Avisar que ha terminado bien su ejecución
			exit(0);
		} else {
			// Estamos en el proceso hijo
			// En la primera vuelta dice que es el padre
			if (i == 0){
				printf("Soy el proceso padre mi PID es %d\n", getpid());
			}else {
				printf ("Soy el hijo %d, mi PID es %d y el PID de mi padre es %d\n", i, getpid(), getppid());	
			}
		}

    }
	
}


