#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid, pid1, pid2, pid3, status;
    FILE *stream; 
    char frase[3][100];
    stream = fopen("output.txt", "w+");
    if(stream == NULL){
        printf("Il file non esiste");
        exit(0);
    }
    pid1=fork()
    if(pid1 == 0){
        sprintf(frase[0], "Non so ");
        fprintf(stream, "%s", frase[0]);
        sleep(1);
        exit(1);
    }
    else 
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            sprintf(frase[1], "cosa ");
            fprintf(stream, "%s", frase[1]);
            sleep(2);
            exit(2);
        }
        else
        {
            pid3 = fork();
            if (pid3 == 0)
            {
                sprintf(frase[2], "scrivere.");
                fprintf(stream, "%s", frase[2]);
                sleep(3);
                exit(3);
            }
            else
            {
                pid = waitpid(pid3, &status, 0);
                fclose(stream);
                FILE *stream;
                stream = fopen("output.txt", "r");
                int numeroParole = 0;      
                for (int i = 0; i < 3; i++)
                {
                    printf("%s ", frase[i]);
                }
                fclose(stream);
                exit(5);
            }
        }
    }
    return 0;
}