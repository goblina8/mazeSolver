#ifndef PAINTVIEW_HH
#define PAINTVIEW_HH

#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QBrush>
#include <QPalette>
#include <iostream>
#include <QSizePolicy>
#include "maze.hh"

using namespace std;

#define MAX_GRAPHICS 2

class PaintView: public QWidget{ 
  Q_OBJECT

  QImage     _Robot;
  Maze      *_Maze;
  QWidget   *_parent;
  double     mazeHeight = 0;
  double     mazeWidth = 0;
  double     itemHeight = 0;
  double     itemWidth = 0;
  double     _y_start = 0;
  double     _x_start = 0;
  int        _x = 0;
  int        _y = 0;
  int        Hmin = 228;
  int        Hmax = 973;
  int        Wmin = 306;
  int        Wmax = 1638;
  int        graphics = 1;

 public:
  PaintView(QWidget *parent = nullptr, string name = "a");
  Maze *maze() {return _Maze;}
  double heightMaze() {return mazeHeight;}
  double widthMaze() {return mazeWidth;}
  void paintEvent( QPaintEvent * event );
  void newMaze(string name);
  void changeGraphics();
}; 

#endif
