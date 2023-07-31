#ifndef CORNER_HH
#define CORNER_HH

#include <iostream>
#include <QImage>
#include <string>
#include <QString>
#include <QDebug>

using namespace std;

class Corner{
  private:
   QImage hole;
   int x;
   int y;
   int corner; //1 - ul, 2 - ur, 3 - dl, 4 - dr
   int graphics;

  public:
   Corner(int _x, int _y, int _corner, int _graphics);
   int position_x();
   int position_y();
   QImage image();
   void set(int graphics);
   bool cornerX();
   bool cornerY();
   void ul_set();
   void ur_set();
   void dl_set();
   void dr_set();
};

#endif
