#include "paintView.hh"

PaintView::PaintView(QWidget *parent, string name): QWidget(parent) 
{
  _TimerMove = new QTimer(this);
  _TimerMove->setObjectName("TimerMove");
  _Robot.load(":/img/robot.png");
  _Maze = new Maze(name, graphics);
  _parent = parent;
  setMinimumWidth(360);
  setMinimumHeight(360);
  setMaximumWidth(630);
  setMaximumHeight(630);
  QMetaObject::connectSlotsByName(this);
}

void PaintView:: newMaze(string name)
{
  delete _Maze;
  _Maze = new Maze(name, graphics);
}

void PaintView::paintEvent( QPaintEvent * )
{
  QPainter  Drafter(this);
  Drafter.setBackground(Qt::white);
  int size = _Maze->mazeSize();
  mazeHeight = size*_Maze->square(0,0).image1().height();
  mazeWidth = size*_Maze->square(0,0).image1().width();
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
  double controlPanelHeight = _parent->height();
  _y_start = ((controlPanelHeight - ((mazeHeight - ((size-1)*4)) * ratio)) / 2) / ratio;
  _x_start = ((width() - ((mazeWidth - ((size-1)*4)) * ratio)) / 2) / ratio;
  Drafter.scale(ratio,ratio);
  int y = _Maze->square(0,0).image1().height()-4;
  int x = _Maze->square(0,0).image1().width()-4;
  for (int i = 0; i < _Maze->what_size(); i++)
  {
    for (int j = 0; j < _Maze->what_size(); j++)
    {
      Drafter.drawImage(_x+_x_start, _y+_y_start, _Maze->square(j,i).image1());
      Drafter.drawImage(_x+_x_start+10, _y+_y_start+10, _Maze->square(j,i).image2());
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

void PaintView:: changeGraphics()
{
  graphics++;
  if(graphics > MAX_GRAPHICS)
  {
    graphics = 1;
  }
  _Maze->newGraphics(graphics);
  update();
}