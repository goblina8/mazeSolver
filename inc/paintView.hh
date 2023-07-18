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

class PaintView: public QWidget{ 
  Q_OBJECT

  QTimer    *_TimerMove = nullptr;
  QImage     _Robot;
  Maze      *_Maze;
  QWidget   *_parent;
  
  double mazeHeight = 0;
  double mazeWidth = 0;
  int _x = 0;
  int _y = 0;
  double _y_start = 0;
  double _x_start = 0;
  int Hmin = 228;
  int Hmax = 973;
  int Wmin = 306;
  int Wmax = 1638;

 public:
  PaintView(QWidget *parent = nullptr, string name = "a");
  void paintEvent( QPaintEvent * event );
  void startMove() { _TimerMove->start(100); }
  void stopMove() { _TimerMove->stop(); }
  Maze *maze() {return _Maze;}
  void newMaze(string name);
  double heightMaze() {return mazeHeight;}
  double widthMaze() {return mazeWidth;}

 public slots:
  void on_TimerMove_timeout();
}; 

#endif
