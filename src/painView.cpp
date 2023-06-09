#include "paintView.hh"

PaintView::PaintView(QWidget *parent): QWidget(parent) 
{
  _TimerMove = new QTimer(this);
  _TimerMove->setObjectName("TimerMove");
  _Robot.load(":/img/robot.png");
  _Maze = new Maze(size);

  QMetaObject::connectSlotsByName(this);
}

void PaintView::paintEvent( QPaintEvent * )
{
  QPainter  Drafter(this);
  Drafter.setBackground(Qt::white);
  double mazeHeight = size*_Maze->square(0,0).image1().height();
  double mazeWidth = size*_Maze->square(0,0).image1().width();
  double backgroundRatio = mazeHeight / mazeWidth;
  double windowRatio = height()/width();
  double ratio = windowRatio;
  
  if (backgroundRatio > windowRatio) 
  {
    ratio = height()/static_cast<double>(mazeHeight);
  } 
  else 
  {
    ratio = width()/static_cast<double>(mazeWidth);
  }
  _y_start = (height() - mazeHeight*ratio)/2;
  _x_start = (width() - mazeWidth*ratio)/2;
  Drafter.scale(ratio,ratio);
  int y = _Maze->square(0,0).image1().height()-5;
  int x = _Maze->square(0,0).image1().width()-5;
  for (int i = 0; i < _Maze->what_size(); i++)
  {
    for (int j = 0; j < _Maze->what_size(); j++)
    {
      Drafter.drawImage(_x+_x_start, _y+_y_start, _Maze->square(j,i).image1());
      Drafter.drawImage(_x+_x_start+10, _y+_y_start+11, _Maze->square(j,i).image2());
      _y += y;
      if(_y%(_Maze->what_size()*y) == 0)
      {
        _y = 0;
      }
    }
    _x += x;
    if(_x%(_Maze->what_size()*x) == 0)
     {
      _x = 0;
     }
  }
}

void PaintView::on_TimerMove_timeout()
{
  update();
}
