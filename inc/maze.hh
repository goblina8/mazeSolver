#ifndef MAZE_HH
#define MAZE_HH

#include <iostream>
#include <QImage>

#include "square.hh"
using namespace std;

class Maze{
  private:
   Square maze[16][16];
   bool meta = 0;
   int size;
   int position_now_x = -1;
   int position_now_y = -1;
   int position_previous_x;
   int position_previous_y;
   int number_of_visited_squares = 0;

  public:
   Maze(int size);
   void move(int direction); //0,1,2,3 prawo,lewo,gora, dol
   bool is_it_start(int x, int y);
   bool is_it_meta(int x, int y);
   bool is_there_path(int wall_number);
   int choose_direction();
   bool was_it_visited(int x, int y);
   void visit(int x, int y);
   void new_position(int x, int y);
   void start();
   void restart();
   QImage image1(int x, int y);
   QImage image2(int x, int y);
   int what_size();
   Square square(int x, int y);
   int now_x() {return position_now_x;}
   int now_y() {return position_now_y;}
};

#endif