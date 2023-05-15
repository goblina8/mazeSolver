#ifndef PAINTVIEW_HH
#define PAINTVIEW_HH

#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QBrush>
#include <QPalette>
#include <iostream>

#include "maze.hh"
using namespace std;

class PaintView: public QWidget { 
  Q_OBJECT

  QTimer    *_TimerMove = nullptr;
  QImage     _Background;
  QImage     _Robot;
  Maze      *_Maze;

  int _x = 50;
  int _y = 50;

 public:
  PaintView(QWidget *parent = nullptr);
  void paintEvent( QPaintEvent * event );
  void startMove() { _TimerMove->start(100); }
  void stopMove() { _TimerMove->stop(); }
  Maze *maze() {return _Maze;}

 public slots:
  void on_TimerMove_timeout();
}; 

#endif
