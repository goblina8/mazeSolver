#ifndef SQUARE_HH
#define SQUARE_HH

#include <iostream>
#include <QWidget>
#include <QImage>
#include <string>
#include <QString>
#include <QDebug>

using namespace std;

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
   int visited = 0;
   QImage ul_corner;
   QImage ur_corner;
   QImage dl_corner;
   QImage dR_corner;

  public:
   Square(int x, int y, bool _start, bool _meta, int number, int graphics);
   Square(){};
   void visited_image(int graphics);
   void basic_image();
   void meta_image();
   void start_image();
   void robot_image(int graphics);
   void visit();
   void unvisit();
   void restartVisit();
   bool is_it_start();
   bool is_it_meta();
   bool is_path(int wall_number);
   int was_it_visited();
   int position_x();
   int position_y();
   void loadPicture(int nr);
   QImage image1();
   QImage image2();
};

#endif
