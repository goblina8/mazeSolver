#ifndef SQUARE_HH
#define SQUARE_HH

#include <iostream>
#include <QWidget>
#include <QImage>


class Square{
  private:
   QImage square;
   QImage item;
   int position[2];
   bool left_wall;
   bool right_wall;
   bool up_wall;
   bool down_wall;
   bool meta;
   bool start;
   int square_option;
   bool visited = 0;

  public:
   Square(int x, int y, bool _start, bool _meta, int number);
   Square(){};
   void visited_image();
   void basic_image();
   void meta_image();
   void robot_image();
   void visit();
   void unvisit();
   bool is_it_start();
   bool is_it_meta();
   bool is_path(int wall_number);
   bool was_it_visited();
   int position_x();
   int position_y();
   QImage image1();
   QImage image2();
};

#endif
