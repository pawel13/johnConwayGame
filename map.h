#ifndef _MAP_H_
#define _MAP_H_

#define PIXELS 22

struct e{
  int x;
  int y;
  int prevState;
  int nextState;
};

struct e point[PIXELS][PIXELS];

struct f{
  int currState;
  int nextState[9];

};

static struct f FSM[2]={
  {0,{0,0,0,1,0,0,0,0,0}}, // if dead- next states depending on the number of alive neighbours: 0,1,2,...,8
  {1,{0,0,1,1,0,0,0,0,0}}  // if alive- next states ...
};

int howManyAliveNeighbours(int x, int y);
void changeGeneration();
void doManyGenerations(int n);

#endif

