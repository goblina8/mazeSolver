#ifndef MAZE_HH
#define MAZE_HH

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "square.hh"
#include "corner.hh"
#include "frame.hh"
using namespace std;

class Maze{

  private:
   Square maze[16][16];
   vector<vector<int>> previous_position;
   bool meta = 0;
   int size = -1;
   int minSteps = -1;
   int position_x = -1;
   int position_y = -1;
   int number_of_visited_squares = 0;
   int graphics = 1;
   vector<Corner> corners;
   vector<Frame> frames;

  public:
   Maze(string name, int graphics);
   void move(int direction); //0,1,2,3 prawo,lewo,gora, dol
   bool is_it_start(int x, int y);
   bool is_it_meta(int x, int y);
   bool is_there_path(int wall_number);
   bool was_it_visited(int x, int y);
   void visit(int x, int y);
   void unvisit(int x, int y);
   void restartVisit(int x, int y);
   void stepRandom();
   void stepAlgorithm();
   void stepBack();
   qint64 solveMazeRandom();
   qint64 solveMazeAlgorithm();
   void start();
   void restart();   
   QImage image1(int x, int y);
   QImage image2(int x, int y);
   int what_size();
   Square square(int x, int y);
   Corner corner(int i);
   int corner_size();
   Frame frame(int i);
   int frame_size();
   int now_x() {return position_x;}
   int now_y() {return position_y;}
   void readMaze(string &name);
   int bestPath() {return minSteps;}
   int stepsNumber() {return previous_position.size();}
   int mazeSize() {return size;}
   void newGraphics(int graphics);
   void setCorners(int graphics);
   void setFrame(int graphics);
};

#endif