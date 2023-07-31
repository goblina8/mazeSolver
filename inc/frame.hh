#ifndef FRAME_HH
#define FRAME_HH

#include <iostream>
#include <QImage>
#include <string>
#include <QString>

using namespace std;

class Frame{
  private:
   QImage frame;
   int x;
   int y;
   int size;
   int graphics;

  public:
   Frame(int x, int y, int graphics, int size);
   int position_x();
   int position_y();
   void set(int graphics);
   QImage image();
   void ul_set();
   void ur_set();
   void dl_set();
   void dr_set();
   void left_set();
   void right_set();
   void up_set();
   void down_set();
};

#endif
