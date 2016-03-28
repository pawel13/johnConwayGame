#include "input.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


int getInput(int argc, char** argv){
/*  extern int opt;
  extern int numberOfGenerations; 
  extern char* inputPngFilename; 
  extern char* outputPngFilename;
  extern char* programName;
  extern int userSetNumberOfGenerations;
  extern char *usage;
*/  numberOfGenerations = 50;
  inputPngFilename = NULL;
  outputPngFilename = NULL;
  programName = argv[0];
  userSetNumberOfGenerations = 0;
  usage  =
 "Usage:\n%s -i|-I input_file -o|-O output_file [-n|-N number_of_generations] [-h|-H] \n"
 "h-                      get help (see this menu)\n"
 "input_file-             file of an input picture with .png extension \n"
 "output_file-            name of a file to save the resulting picture to with .png extension \n"
 "number_of_generations-  optional parameter, specifies the number of generation iterations, by default: 50 \n";

  while ((opt = getopt(argc, argv, "n:N:i:I:o:O:"))!=-1){
    switch(opt){
      case 'n': case 'N': 
        numberOfGenerations = atoi(optarg); 
        printf("Number of generations = %d\n",numberOfGenerations); 
        userSetNumberOfGenerations = 1;
        break;
      case 'i': case 'I':
        inputPngFilename = optarg;
        printf("Reading from a '%s' file\n", inputPngFilename);
        break;
      case 'o': case 'O':
        outputPngFilename = optarg;
        printf("Output file directory: %s\n", outputPngFilename);
        break;
      default: 
        printf(usage, programName);
        exit (EXIT_FAILURE);
      }
  }

  if( optind < argc || inputPngFilename == NULL || outputPngFilename == NULL || argc < 2 || numberOfGenerations <= 0) {
    tellWhatsWrong(optind, numberOfGenerations, inputPngFilename, outputPngFilename, argc, argv);
    showHowToUse(usage, programName);
    exit (EXIT_FAILURE);
  }
  if (!userSetNumberOfGenerations)
   fprintf(stderr,"Assuming number of generations is a default value (50)\n");
  return EXIT_SUCCESS;
}
    
void tellWhatsWrong(int optind, int numberOfGenerations, char* inputPngFilename, char* outputPngFilename, int argc, char** argv){
    fprintf( stderr, "Bad parameters:\n" );
    
  if( optind < argc)
    for( ; optind < argc; optind++ )
      fprintf( stderr, "\t\"%s\"\n", argv[optind] );
      if( argc < 2) {
    fprintf(stderr,"\tToo few arguments!\n");
  }  
  if(inputPngFilename == NULL) {
    fprintf(stderr,"\tInput file not specified!\n");
  }

  if( outputPngFilename == NULL ) {
    fprintf(stderr,"\tOutput file not specified!\n");
  }
  if( numberOfGenerations <= 0 ){
    fprintf(stderr, "\tNumber of generations must be a positive value!\n");
  }

}
 
void showHowToUse(char* usage, char* programName){
    fprintf( stderr, usage, programName );
}


