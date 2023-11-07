#include "controlPanel.hh"

ControlPanel::ControlPanel(QWidget *parent):  QWidget(parent)
{
  _parent = parent;
  // FRAMES
  QFrame *frame = new QFrame(this);
  frame->setFrameShadow(QFrame::Sunken);
  frame->setFrameShape(QFrame::Panel);
  frame->setLineWidth(2);
  frame->setMaximumWidth(300);
  // LAYOUTS
  QHBoxLayout *horizontal = new QHBoxLayout(this);
  QHBoxLayout *horizontal1 = new QHBoxLayout();
  QHBoxLayout *horizontal2 = new QHBoxLayout();
  QHBoxLayout *horizontal3 = new QHBoxLayout();
  QHBoxLayout *horizontal4 = new QHBoxLayout();
  QHBoxLayout *horizontal5 = new QHBoxLayout();
  QHBoxLayout *horizontal6 = new QHBoxLayout();
  QHBoxLayout *horizontal7 = new QHBoxLayout();
  QHBoxLayout *horizontal8 = new QHBoxLayout();
  QHBoxLayout *horizontal9 = new QHBoxLayout();
  QHBoxLayout *horizontal10 = new QHBoxLayout();
  QHBoxLayout *horizontal11 = new QHBoxLayout();
  QHBoxLayout *horizontal12 = new QHBoxLayout();
  QHBoxLayout *horizontal13 = new QHBoxLayout();
  QHBoxLayout *horizontal14 = new QHBoxLayout();
  QHBoxLayout *horizontal15 = new QHBoxLayout();
  QHBoxLayout *horizontal16 = new QHBoxLayout();
  QVBoxLayout *vertical1 = new QVBoxLayout(); 
  QVBoxLayout *vertical2 = new QVBoxLayout(frame); 
  // SIZE
  setMinimumWidth(630);
  setMinimumHeight(360);
  setMaximumWidth(1000);
  setMaximumHeight(650);
  // BUTTONS
  _CloseButton = new QPushButton(tr("Close"),this);
  _RestartButton = new QPushButton(tr("Restart"),this);
  _SolveButton = new QPushButton(tr("Solve the maze"),this);
  _StepButton = new QPushButton(tr("Do one step"),this);
  _StepBackButton = new QPushButton(tr("Do step back"),this);
  _LoadButton = new QPushButton(tr("Graphics"),this);
  //BUTTONS SIZE
  _CloseButton->setMinimumWidth(100);
  _CloseButton->setMaximumWidth(500);
  _CloseButton->setMinimumHeight(40);
  _CloseButton->setMaximumHeight(80);
  _RestartButton->setMinimumWidth(100);
  _RestartButton->setMaximumWidth(500);
  _RestartButton->setMinimumHeight(40);
  _RestartButton->setMaximumHeight(80);
  _SolveButton->setMinimumWidth(200);
  _SolveButton->setMaximumWidth(500);
  _SolveButton->setMinimumHeight(40);
  _SolveButton->setMaximumHeight(80);
  _StepButton->setMinimumWidth(100);
  _StepButton->setMaximumWidth(250);
  _StepButton->setMinimumHeight(40);
  _StepButton->setMaximumHeight(80);
  _StepBackButton->setMinimumWidth(100);
  _StepBackButton->setMaximumWidth(250);
  _StepBackButton->setMinimumHeight(40);
  _StepBackButton->setMaximumHeight(80);
  _LoadButton->setMinimumWidth(110);
  _LoadButton->setMaximumWidth(110);
  _LoadButton->setMinimumHeight(25);
  _LoadButton->setMaximumHeight(30);
  // COMBOBOXEX
  QDir directory("mazes");
  _fileNames = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);
  _comboBoxMaze = new QComboBox;
  _comboBoxMaze->addItems(_fileNames);
  _comboBoxMaze->setObjectName("fileName");
  _comboBoxMaze->setMinimumWidth(110);
  _comboBoxMaze->setMaximumWidth(180);
  _comboBoxMaze->setMinimumHeight(25);
  _comboBoxMaze->setMaximumHeight(30);
  _comboBoxAlgorithm = new QComboBox;
  _comboBoxAlgorithm->addItem("Random");
  _comboBoxAlgorithm->addItem("Algorithm");
  _comboBoxAlgorithm->setObjectName("algorithm");
  _comboBoxAlgorithm->setMinimumWidth(110);
  _comboBoxAlgorithm->setMaximumWidth(180);
  _comboBoxAlgorithm->setMinimumHeight(25);
  _comboBoxAlgorithm->setMaximumHeight(30);
  // PAINTVIEW
  _PaintView = new PaintView(this, _fileNames[0].toStdString());
  QString best = QString::number(maze()->bestPath());
  _bestPath = new QLabel(best);
  // TEXTBOXES
  _bestPathLabel = new QLabel("Step number of best path");
  _bestPathLabel->setFrameShadow(QFrame::Raised);
  _bestPathLabel->setFrameShape(QFrame::Box);
  _bestPathLabel->setLineWidth(2);
  _bestPathLabel->setMinimumWidth(185);
  _bestPathLabel->setMaximumWidth(200);
  _bestPathLabel->setAlignment(Qt::AlignCenter);
  _bestPathLabel->setMinimumHeight(30);
  _bestPathLabel->setMaximumHeight(40);
  _bestPath->setFrameShadow(QFrame::Sunken);
  _bestPath->setFrameShape(QFrame::Panel);
  _bestPath->setLineWidth(2);
  _bestPath->setMaximumWidth(60);
  _bestPath->setMinimumWidth(40);
  _bestPath->setMinimumHeight(30);
  _bestPath->setMaximumHeight(40);
  _bestPath->setAlignment(Qt::AlignCenter);
  _stepsNumberLabel = new QLabel(" Current number of steps ");
  _stepsNumberLabel->setFrameShadow(QFrame::Raised);
  _stepsNumberLabel->setFrameShape(QFrame::Box);
  _stepsNumberLabel->setLineWidth(2);
  _stepsNumberLabel->setMinimumWidth(185);
  _stepsNumberLabel->setMaximumWidth(200);
  _stepsNumberLabel->setAlignment(Qt::AlignCenter);
  _stepsNumberLabel->setMinimumHeight(30);
  _stepsNumberLabel->setMaximumHeight(40);
  _stepsNumber = new QLabel("0");
  _stepsNumber->setFrameShadow(QFrame::Sunken);
  _stepsNumber->setFrameShape(QFrame::Panel);
  _stepsNumber->setLineWidth(2);
  _stepsNumber->setMaximumWidth(60);
  _stepsNumber->setMinimumWidth(40);
  _stepsNumber->setAlignment(Qt::AlignCenter);
  _stepsNumber->setMinimumHeight(30);
  _stepsNumber->setMaximumHeight(40);
  _TimeLabel = new QLabel(" Time in microseconds ");
  _TimeLabel->setFrameShadow(QFrame::Raised);
  _TimeLabel->setFrameShape(QFrame::Box);
  _TimeLabel->setLineWidth(2);
  _TimeLabel->setMinimumWidth(185);
  _TimeLabel->setMaximumWidth(200);
  _TimeLabel->setAlignment(Qt::AlignCenter);
  _TimeLabel->setMinimumHeight(30);
  _TimeLabel->setMaximumHeight(30);
  _Time = new QLabel("0");
  _Time->setFrameShadow(QFrame::Sunken);
  _Time->setFrameShape(QFrame::Panel);
  _Time->setLineWidth(2);
  _Time->setMaximumWidth(60);
  _Time->setMinimumWidth(40);
  _Time->setMinimumHeight(30);
  _Time->setMinimumHeight(30);
  _Time->setAlignment(Qt::AlignCenter);
  _algorithmLabel = new QLabel(" Algorithm ");
  _algorithmLabel->setFrameShadow(QFrame::Raised);
  _algorithmLabel->setFrameShape(QFrame::Box);
  _algorithmLabel->setLineWidth(2);
  _algorithmLabel->setMinimumWidth(110);
  _algorithmLabel->setMaximumWidth(110);
  _algorithmLabel->setMinimumHeight(25);
  _algorithmLabel->setMaximumHeight(30);
  _algorithmLabel->setAlignment(Qt::AlignCenter);
  // ADDING LAYOUTS
  vertical1->addWidget(_PaintView);
  horizontal1->addItem(new QSpacerItem(0,10,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal2->addWidget(_comboBoxMaze); 
  horizontal2->addWidget(_LoadButton);
  horizontal3->addWidget(_comboBoxAlgorithm);
  horizontal3->addWidget(_algorithmLabel);
  horizontal4->addItem(new QSpacerItem(0,10,QSizePolicy::Minimum,QSizePolicy::Minimum));
  horizontal5->addWidget(_bestPath); 
  horizontal5->addItem(new QSpacerItem(20,30,QSizePolicy::Minimum,QSizePolicy::Minimum));
  horizontal5->addWidget(_bestPathLabel); 
  horizontal6->addWidget(_stepsNumber); 
  horizontal6->addItem(new QSpacerItem(20,0,QSizePolicy::Minimum,QSizePolicy::Minimum));
  horizontal6->addWidget(_stepsNumberLabel); 
  horizontal7->addWidget(_Time); 
  horizontal7->addItem(new QSpacerItem(20,0,QSizePolicy::Minimum,QSizePolicy::Minimum));
  horizontal7->addWidget(_TimeLabel); 
  horizontal8->addItem(new QSpacerItem(0,10,QSizePolicy::Minimum,QSizePolicy::MinimumExpanding));
  horizontal9->addWidget(_StepButton); 
  horizontal9->addWidget(_StepBackButton); 
  horizontal10->addItem(new QSpacerItem(0,7,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal11->addWidget(_SolveButton);  
  horizontal12->addItem(new QSpacerItem(0,7,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal13->addWidget(_RestartButton);  
  horizontal14->addItem(new QSpacerItem(0,7,QSizePolicy::Minimum,QSizePolicy::Maximum)); 
  horizontal15->addWidget(_CloseButton);
  horizontal16->addItem(new QSpacerItem(0,5,QSizePolicy::Minimum,QSizePolicy::Minimum));
  // LAYOUTS INTO LAYOUTS
  vertical2->addLayout(horizontal1);
  vertical2->addLayout(horizontal2);
  vertical2->addLayout(horizontal3);
  vertical2->addLayout(horizontal4);
  vertical2->addLayout(horizontal5);
  vertical2->addLayout(horizontal6);
  vertical2->addLayout(horizontal7);
  vertical2->addLayout(horizontal8);
  vertical2->addLayout(horizontal9);
  vertical2->addLayout(horizontal10);
  vertical2->addLayout(horizontal11);
  vertical2->addLayout(horizontal12);
  vertical2->addLayout(horizontal13);
  vertical2->addLayout(horizontal14);
  vertical2->addLayout(horizontal15);
  vertical2->addLayout(horizontal16);
  horizontal->addLayout(vertical1);
  horizontal->addWidget(frame);
  //CONNECTING
  connect(_CloseButton,SIGNAL(clicked()),this,SIGNAL(reportClosing()));
  connect(_RestartButton,SIGNAL(clicked()),this,SLOT(restartMaze()));
  connect(_StepButton,SIGNAL(clicked()),this,SLOT(stepInMaze()));
  connect(_StepBackButton,SIGNAL(clicked()),this,SLOT(stepBack()));
  connect(_SolveButton,SIGNAL(clicked()),this,SLOT(solveMaze()));
  connect(_LoadButton,SIGNAL(clicked()),this,SLOT(loadGraphics()));
  QMetaObject::connectSlotsByName(this);
}

void ControlPanel:: restartMaze()
{
  _PaintView->maze()->restart();
  _PaintView->update();
  stepsNumber();
  _Time->setText("0");
  _PaintView->maze()->dijkstra();
}

void ControlPanel:: stepInMaze()
{
  switch(_algorithm)
  {
    case 0:
      {
        _PaintView->maze()->stepRandom();
        _PaintView->update();
        stepsNumber();
        break;
      }
      case 1:
      {
        _PaintView->maze()->stepAlgorithm();
        _PaintView->update();
        stepsNumber();
        break;
      }
  }
}

void ControlPanel:: stepBack()
{
  _PaintView->maze()->stepBack();
  _PaintView->update();
  stepsNumber();
  if(_algorithm == 1)
    {
        maze()->returnD()->stepBack();
    }
}

void ControlPanel:: solveMaze()
{
  switch (_algorithm)
  {
    case 0:
    {
      _PaintView->maze()->solveMazeRandom();
      _Time->setText(QString::number(_PaintView->maze()->WhatTime()));
      _PaintView->update();
      stepsNumber();
      break;
    }
    case 1:
    {
      _PaintView->maze()->solveMazeAlgorithm();
      _Time->setText(QString::number(_PaintView->maze()->WhatTime()));
      _PaintView->update();
      stepsNumber();
    }
  }
}

void ControlPanel:: on_fileName_currentIndexChanged(int index)
{
  _index = index;
  _PaintView->newMaze(_fileNames[_index].toStdString());
  stepsNumber();
  bestPathNumber();
  _PaintView->update();
  if(_algorithm == 1)
  {
    _PaintView->maze()->dijkstra();
  }
}

void ControlPanel:: on_algorithm_currentIndexChanged(int index)
{
  _algorithm = index;
  if(_algorithm == 1)
  {
    _PaintView->maze()->dijkstra();
  }
}

void ControlPanel:: loadGraphics()
{
  _PaintView->changeGraphics();
}