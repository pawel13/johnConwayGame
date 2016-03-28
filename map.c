#include <stdio.h>
#include "map.h"

int howManyAliveNeighbours(int x, int y){
  int aliveNeighbours = 0;
  int i,j;

 for(i = x-1; i <= x+1; i++){
    for(j = y-1; j <= y+1; j++){
      if(i!=x || j!=y)
        aliveNeighbours += point[i][j].prevState;
    }
  }

  return aliveNeighbours;

}

void changeGeneration(){
  int row,col;
  
  for(row = 1; row < PIXELS - 1; row++)
    for(col = 1; col < PIXELS - 1 ; col++)
      point[row][col].nextState = FSM[point[row][col].prevState].nextState[howManyAliveNeighbours(row,col)]; 
  
  // saving to prevState
  for(row = 1; row < PIXELS - 1; row++)
    for(col = 1; col < PIXELS - 1 ; col++)
      point[row][col].prevState = point[row][col].nextState;

}

void doManyGenerations(int n){

  while(n--){
    changeGeneration();  
    //SAVE_TO_FILE
  }
}


