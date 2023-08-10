#ifndef SQUARE_HH
#define SQUARE_HH

#include <QImage>
#include <string>
#include <QString>
#include <QDebug>

using namespace std;

class Square{
  private:
   QImage     square;
   QImage     item;
   bool       left_wall;
   bool       right_wall;
   bool       up_wall;
   bool       down_wall;
   bool       meta;
   bool       start;
   int        position[2];
   int        square_option;
   int        visited = 0;

  public:
   Square(int x, int y, bool _start, bool _meta, int number, int graphics);
   Square(){};
   int was_it_visited();
   int position_x();
   int position_y();
   bool is_it_start();
   bool is_it_meta();
   bool is_path(int wall_number);
   bool cornerUL();
   bool cornerUR();
   bool cornerDL();
   bool cornerDR();
   void basic_image();
   void meta_image();
   void start_image();
   void visit();
   void unvisit();
   void restartVisit();
   void loadPicture(int graphics);
   void visited_image(int graphics);
   void robot_image(int graphics);
   QImage image1();
   QImage image2();
   QImage imageUL();
   QImage imageDL();
   QImage imageUR();
   QImage imageDR();
};

#endif
