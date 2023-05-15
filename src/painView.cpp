#include "paintView.hh"

PaintView::PaintView(QWidget *parent): QWidget(parent) 
{
  _TimerMove = new QTimer(this);
  _TimerMove->setObjectName("TimerMove");
  _Background.load(":/img/background.png");
  _Robot.load(":/img/robot.png");
  _Maze = new Maze(6);

  QMetaObject::connectSlotsByName(this);
}

void PaintView::paintEvent( QPaintEvent * )
{
  QPainter  Drafter(this);
  Drafter.setBackground(Qt::white);

  double backgroundRatio = _Background.height()/_Background.width();
  double windowRatio = height()/width();
  double ratio;

  if (backgroundRatio > windowRatio) {
     ratio = height()/static_cast<double>(_Background.height());
  } else {
     ratio = width()/static_cast<double>(_Background.width());
  }
  Drafter.scale(ratio,ratio);
  Drafter.drawImage(0,0,_Background);
  int y = _Maze->square(0,0).image1().height()-5;
  int x = _Maze->square(0,0).image1().width()-5;
  for (int i = 0; i < _Maze->what_size(); i++)
  {
    for (int j = 0; j < _Maze->what_size(); j++)
    {
      Drafter.drawImage(_x, _y, _Maze->square(j,i).image1());
      Drafter.drawImage(_x+10, _y+11, _Maze->square(j,i).image2());
      _y += y;
      if(_y%(50+6*y) == 0)
      {
        _y = 50;
      }
    }
    _x += x;
    if(_x%(50+6*x) == 0)
     {
      _x = 50;
     }
  }
}

void PaintView::on_TimerMove_timeout()
{
  update();
}
