#include "paintView.hh"

PaintView::PaintView(QWidget *parent, string name): QWidget(parent) 
{
  _TimerMove = new QTimer(this);
  _TimerMove->setObjectName("TimerMove");
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
  double H = _Maze->square(0,0).image1().height();
  double W = _Maze->square(0,0).image1().width();
  mazeHeight = size * H;
  mazeWidth = size * W;
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
  _y_start = ((controlPanelHeight - ((mazeHeight - ((size-1)*0)) * ratio)) / 2) / ratio - 10/ratio;
  _x_start = ((width() - ((mazeWidth - ((size-1)*0)) * ratio)) / 2) / ratio;
  Drafter.scale(ratio,ratio);
  double y = _Maze->square(0,0).image1().height();
  double x = _Maze->square(0,0).image1().width();
  //JAK USTAWIC POZYCJE NA SRODKU - WiELKOSC OBRAZKA KTORY DOPIERO SIE POJAWI
  double y_offset;
  double x_offset; 
  double x_end_UR;
  double y_end_DL;
  double x_end_DR;
  double y_end_DR;

  for (int i = 0; i < _Maze->what_size(); i++)
  {
    for (int j = 0; j < _Maze->what_size(); j++)
    {
      y_offset = (H - _Maze->square(j,i).image2().height())/2;
      x_offset = (W - _Maze->square(j,i).image2().width())/2;
      Drafter.drawImage(_x+_x_start, _y+_y_start, _Maze->square(j,i).image1());
      Drafter.drawImage(_x+_x_start+x_offset, _y+_y_start+y_offset, _Maze->square(j,i).image2());

      x_end_UR = W - _Maze->square(j,i).imageUR().width();
      y_end_DL = H - _Maze->square(j,i).imageDL().height();
      x_end_DR = W - _Maze->square(j,i).imageDR().width();
      y_end_DR = H - _Maze->square(j,i).imageDR().height();
      Drafter.drawImage(_x+_x_start, _y+_y_start, _Maze->square(j,i).imageUL());
      Drafter.drawImage(_x+_x_start, _y+_y_start+y_end_DL, _Maze->square(j,i).imageDL());
      Drafter.drawImage(_x+_x_start+x_end_UR, _y+_y_start, _Maze->square(j,i).imageUR());
      Drafter.drawImage(_x+_x_start+x_end_DR, _y+_y_start+y_end_DR, _Maze->square(j,i).imageDR());
      
      _y += y;
      if(_y%(_Maze->what_size()*int(y)) == 0)
      {
        _y = 0;
      }
    }
    _x += x;
    if(_x%(_Maze->what_size()*int(x)) == 0)
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
  _Maze->setCorners(graphics);
  update();
}