#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]){
    int newLine = 1;
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-n") == 0){
            newLine = 0;
            continue;
        }
        printf("%s ", argv[i]);
    }
    if(newLine){
        printf("\n");
    }
}
