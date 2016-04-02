#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <png.h>

#include "pictures.h"
#include "map.h"

void readPngFile(){
  
  
}

void savePngFile(){
  
  
}



void makeBinaryPicture(){
  int i,j;
  
  
  //TEMPORARY SOLUTIONS FOR INITIALIZING AN ARRAY
  // srand(time(NULL));
  srand(0);
  for(i=1;i<PIXELS-1;i++){
    for(j=1;j<PIXELS-1;j++){
      point[i][j].x = i;
      point[i][j].y = j;
      point[i][j].prevState=rand()%2;
    }
  }

  for(i = 0; i <= PIXELS - 1; i++){
      point[i][0].x = i; 
      point[i][0].y = 0; 
      point[i][0].prevState = 0; 

      point[i][PIXELS-1].x = i;
      point[i][PIXELS-1].y = PIXELS-1;
      point[i][PIXELS-1].prevState = 0;

      point[0][i].x = 0; 
      point[0][i].y = i; 
      point[0][i].prevState = 0; 
  
      point[PIXELS-1][i].x = PIXELS-1; 
      point[PIXELS-1][i].y = i; 
      point[PIXELS-1][i].prevState = 0; 
  }
  
}

void printBinaryPicture(){
  int i,j;
  for(i = 0; i < PIXELS; i++){
    for(j = 0; j < PIXELS; j++){
      printf("%d",point[i][j].prevState);
    }
    printf("\n");
  }

}


