#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "input.h"
#include "pictures.h"
#include "map.h"

int main(int argc, char **argv){

  if (getInput(argc,argv) == EXIT_FAILURE)
    return EXIT_FAILURE;
 
  printf("input file in main: %s\n",inputPngFilename);

  readInputPng();  
  
#ifdef DEBUG
  printf("Input file in binary format:\n");  
  printBinaryPicture();  
#endif

  doManyGenerations(numberOfGenerations);

#ifdef DEBUG 
  printf("\n Result: \n");
  printBinaryPicture();
#endif

  return EXIT_SUCCESS;

}

