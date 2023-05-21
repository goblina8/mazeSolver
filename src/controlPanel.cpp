#include "controlPanel.hh"

ControlPanel::ControlPanel(QWidget *parent):  QWidget(parent)
{
  QHBoxLayout *horizontal = new QHBoxLayout(this);
  QHBoxLayout *horizontal1 = new QHBoxLayout();
  QHBoxLayout *horizontal2 = new QHBoxLayout();
  QHBoxLayout *horizontal3 = new QHBoxLayout();
  QHBoxLayout *horizontal4 = new QHBoxLayout();
  QHBoxLayout *horizontal5 = new QHBoxLayout();
  QHBoxLayout *horizontal6 = new QHBoxLayout();
  QHBoxLayout *horizontal7 = new QHBoxLayout();
  QVBoxLayout *vertical1 = new QVBoxLayout(); 
  QVBoxLayout *vertical2 = new QVBoxLayout(); 

  _PaintView = new PaintView(this);
  _CloseButton = new QPushButton(tr("Zamknij"),this);
  _RestartButton = new QPushButton(tr("Restart"),this);
  _SolveButton = new QPushButton(tr("Solve the maze"),this);
  _StepButton = new QPushButton(tr("Do one step"),this);
  _StepBackButton = new QPushButton(tr("Do step back"),this);

  _CloseButton->setMinimumWidth(100);
  _CloseButton->setMaximumWidth(250);
  _CloseButton->setMinimumHeight(50);
  _CloseButton->setMaximumHeight(90);
  _RestartButton->setMinimumWidth(100);
  _RestartButton->setMaximumWidth(250);
  _RestartButton->setMinimumHeight(50);
  _RestartButton->setMaximumHeight(90);
  _SolveButton->setMinimumWidth(200);
  _SolveButton->setMaximumWidth(500);
  _SolveButton->setMinimumHeight(50);
  _SolveButton->setMaximumHeight(90);
  _StepButton->setMinimumWidth(100);
  _StepButton->setMaximumWidth(250);
  _StepButton->setMinimumHeight(50);
  _StepButton->setMaximumHeight(90);
  _StepBackButton->setMinimumWidth(100);
  _StepBackButton->setMaximumWidth(250);
  _StepBackButton->setMinimumHeight(50);
  _StepBackButton->setMaximumHeight(90);

  vertical1->addWidget(_PaintView);
  horizontal1->addItem(new QSpacerItem(10,10,QSizePolicy::Minimum,QSizePolicy::MinimumExpanding));
  horizontal2->addWidget(_StepButton); 
  horizontal2->addWidget(_StepBackButton); 
  horizontal3->addWidget(_SolveButton);  
  horizontal4->addItem(new QSpacerItem(10,70,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal5->addWidget(_RestartButton);  
  horizontal6->addItem(new QSpacerItem(10,70,QSizePolicy::Minimum,QSizePolicy::Maximum)); 
  horizontal7->addWidget(_CloseButton);
  
  vertical2->addLayout(horizontal1);
  vertical2->addLayout(horizontal2);
  vertical2->addLayout(horizontal3);
  vertical2->addLayout(horizontal4);
  vertical2->addLayout(horizontal5);
  vertical2->addLayout(horizontal6);
  vertical2->addLayout(horizontal7);

  horizontal->addLayout(vertical1);
  horizontal->addLayout(vertical2);

  connect(_CloseButton,SIGNAL(clicked()),this,SIGNAL(ReportClosing()));
  connect(_RestartButton,SIGNAL(clicked()),this,SLOT(restartMaze()));
  connect(_StepButton,SIGNAL(clicked()),this,SLOT(stepInMaze()));
  connect(_StepBackButton,SIGNAL(clicked()),this,SLOT(stepBack()));
  connect(_SolveButton,SIGNAL(clicked()),this,SLOT(solveMaze()));
  QMetaObject::connectSlotsByName(this);
}

void ControlPanel:: restartMaze()
{
  _PaintView->maze()->restart();
  _PaintView->update();
}

void ControlPanel:: stepInMaze()
{
  _PaintView->maze()->step();
  _PaintView->update();
}

void ControlPanel:: stepBack()
{
  _PaintView->maze()->stepBack();
  _PaintView->update();
}

void ControlPanel:: solveMaze()
{
  _PaintView->maze()->solveMaze();
  _PaintView->update();
}

/*
void ControlPanel::on_RestartButton_toggled(bool Checked)
{
  if (Checked) _PaintView->startMove();
          else _PaintView->stopMove();
}
*/