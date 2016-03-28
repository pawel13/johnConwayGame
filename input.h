#ifndef _INPUT_H_
#define _INPUT_H_

#include <stdlib.h>
int opt;
int numberOfGenerations; 
char* inputPngFilename; 
char* outputPngFilename;
char* programName; 
int userSetNumberOfGenerations; 
char* usage; 

int getInput(int, char**);
void tellWhatsWrong(int optind, int numberOfGenerations, char* inputPngFilename, char* outputPngFilename, int argc, char** argv);
void showHowToUse(char* usage, char* programName);

#endif
