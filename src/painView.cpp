#include "paintView.hh"

PaintView::PaintView(QWidget *parent, string name): QWidget(parent) 
{
  _Robot.load(":/img/robot1.png");
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
  int y = _Maze->square(0,0).image1().height();
  int x = _Maze->square(0,0).image1().width();
  int H = _Maze->frame(0).image().height();
  int W = _Maze->frame(0).image().width();
  mazeHeight = size * y + 2*H;
  mazeWidth = size * x + 2*W;
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
  _y_start = ((controlPanelHeight - ((mazeHeight - ((size-1)*0)) * ratio)) / 2) / ratio - 10/ratio;;
  _x_start = ((width() - ((mazeWidth - ((size-1)*0)) * ratio)) / 2) / ratio;
  double y_offset;
  double x_offset; 
  double iks;
  double igrek;
  double _x_end = 0;
  double _y_end = 0;
  int p_x;
  int p_y;
  Drafter.scale(ratio,ratio);
  //FRAME
  _y_start = ((controlPanelHeight - ((mazeHeight - ((size-1)*0)) * ratio)) / 2) / ratio - 10/ratio + H/ratio;
  _x_start = ((width() - ((mazeWidth - ((size-1)*0)) * ratio)) / 2) / ratio + W/ratio;
  for (int i = 0; i < _Maze->frame_size(); i++)
  {
    p_y = _Maze->frame(i).position_x();
    p_x = _Maze->frame(i).position_y();
    iks = (p_x-1) * x;
    igrek = (p_y-1) * y;
    if(p_x == 0)
    {
      iks = 0;
    }
    if(p_y == 0)
    {
        igrek = 0;
    }
    if(p_x == 1)
    {
      iks = W;
    }
    if(p_y == 1)
    {
        igrek = H;
    }
    Drafter.drawImage(iks + _x_start + _x_end, igrek + _y_start + _y_end, _Maze->frame(i).image());
  }
  /*
  _y_start += H;
  _x_start +- W;
  //SQUARES
  for (int i = 0; i < _Maze->what_size(); i++)
  {
    for (int j = 0; j < _Maze->what_size(); j++)
    {
      y_offset = (y - _Maze->square(j,i).image2().height())/2;
      x_offset = (x - _Maze->square(j,i).image2().width())/2;
      Drafter.drawImage(_x+_x_start, _y+_y_start, _Maze->square(j,i).image1());
      Drafter.drawImage(_x+_x_start+x_offset, _y+_y_start+y_offset, _Maze->square(j,i).image2());
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
  //CORNERS
  for (int i = 0; i < _Maze->corner_size(); i++)
  {
    _x_end = (x - _Maze->corner(i).image().width()) * _Maze->corner(i).cornerX();
    _y_end = (y - _Maze->corner(i).image().height()) * _Maze->corner(i).cornerY();
    iks = _Maze->corner(i).position_x() * x;
    igrek = _Maze->corner(i).position_y() * y;
    Drafter.drawImage(iks + _x_start + _x_end, igrek + _y_start + _y_end, _Maze->corner(i).image());
  }
  */
}

void PaintView:: changeGraphics()
{
  graphics++;
  if(graphics > MAX_GRAPHICS)
  {
    graphics = 1;
  }
  _Maze->newGraphics(graphics);
  _Maze->setCorners(graphics);
  update();
}