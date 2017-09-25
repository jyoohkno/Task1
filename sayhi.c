#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int len(char str[]){
int length = 0;
while(str[length] != '\0'){
length += 1;
}
return length;
}

int arrayLen(char* str[]){
int length = -1;
while(str[++length] != NULL);
return length;
}

int main(int argc, char*argv[]){
char * languages[] = {"--english", "--russian", "--kazakh", NULL};
char short_languages[] = "erk";
char name[100] = "";
char * fileNames[] = {"sayhi", "sayprivet", "saysalem", NULL};
char * greetings[] = {"hi", "privet", "salem", NULL};
int lang_id = -1;
int argFound;
int err = 0;
for (int i=1; i<argc; i++){
argFound = 0;

if(strncmp(argv[i], "-", 1) == 0 && len(argv[i]) == 2){
for(int j=0; j<len(short_languages); j++){
if(argv[i][1] == short_languages[j]){
argFound++;
if(lang_id != -1){
err += 1;
printf("PROVIDE ONLY ONE ARG DET LANG\n");
break;
}
lang_id = j;
}
}
}

if(strncmp(argv[i], "--", 2) == 0 && len(argv[i]) > 2){
if(strcmp(argv[i], "--name") == 0){
if(i+1 == argc || strncmp(argv[i+1], "-", 1) == 0){
printf("THIS NAME DOESN'T ALLOWED\n");
err += 1;
break;
}
if(len(argv[i+1]) > 100){
printf("MAX NAME LEN is 100\n");
err += 1;

}
strcpy(name, argv[i+1]);
i++;
continue;
}
for(int k=0; k<arrayLen(languages); k++){
if(strcmp(argv[i], languages[k]) == 0){
argFound++;
if(lang_id != -1){
printf("PROVIDE ONLY ONE ARG DET LANG\n");
err += 1;
break;
}
lang_id = k;
}
}
}
if(argFound == 0){
printf("UNKNOWN ARG %s\n", argv[i]);
err += 1;
break;
}
}
if(lang_id == -1){
char a[10];
do{
strcpy(a, strsep(&argv[0], "/"));
}while(argv[0] != NULL);
for(int i=0; i<arrayLen(fileNames); i++){
if(strcmp(a, fileNames[i]) == 0){
lang_id = i;
}
}
}
if(err == 0){
printf("%s %s\n", greetings[lang_id], name);
}

return 0;
}
