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
  QVBoxLayout *vertical1 = new QVBoxLayout(); 
  QVBoxLayout *vertical2 = new QVBoxLayout(frame); 
  // SIZE
  setMinimumWidth(630);
  setMinimumHeight(360);
  setMaximumWidth(1000);
  setMaximumHeight(650);
  // BUTTONS
  _CloseButton = new QPushButton(tr("Zamknij"),this);
  _RestartButton = new QPushButton(tr("Restart"),this);
  _SolveButton = new QPushButton(tr("Solve the maze"),this);
  _StepButton = new QPushButton(tr("Do one step"),this);
  _StepBackButton = new QPushButton(tr("Do step back"),this);
  _LoadButton = new QPushButton(tr("Load maze"),this);
  //BUTTONS SIZE
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
  _LoadButton->setMinimumWidth(90);
  _LoadButton->setMaximumWidth(110);
  _LoadButton->setMinimumHeight(20);
  _LoadButton->setMaximumHeight(30);
  // COMBOBOX
  QDir directory("mazes");
  _fileNames = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);
  _comboBox = new QComboBox;
  _comboBox->addItems(_fileNames);
  _comboBox->setObjectName("fileName");
  // PAINTVIEW
  _PaintView = new PaintView(this, _fileNames[0].toStdString());
  QString best = QString::number(maze()->bestPath());
  _bestPath = new QLabel(best);
  // TEXTBOXES
  _bestPathLabel = new QLabel("Step number of best path");
  _bestPathLabel->setFrameShadow(QFrame::Raised);
  _bestPathLabel->setFrameShape(QFrame::Box);
  _bestPathLabel->setLineWidth(2);
  _bestPathLabel->setMaximumWidth(200);
  _bestPathLabel->setAlignment(Qt::AlignCenter);
  _bestPath->setFrameShadow(QFrame::Sunken);
  _bestPath->setFrameShape(QFrame::Panel);
  _bestPath->setLineWidth(2);
  _bestPath->setMaximumWidth(50);
  _bestPath->setMinimumWidth(30);
  _bestPath->setAlignment(Qt::AlignCenter);
  _stepsNumberLabel = new QLabel(" Current number of steps ");
  _stepsNumberLabel->setFrameShadow(QFrame::Raised);
  _stepsNumberLabel->setFrameShape(QFrame::Box);
  _stepsNumberLabel->setLineWidth(2);
  _stepsNumberLabel->setMaximumWidth(200);
  _stepsNumberLabel->setAlignment(Qt::AlignCenter);
  _stepsNumber = new QLabel("0");
  _stepsNumber->setFrameShadow(QFrame::Sunken);
  _stepsNumber->setFrameShape(QFrame::Panel);
  _stepsNumber->setLineWidth(2);
  _stepsNumber->setMaximumWidth(50);
  _stepsNumber->setMinimumWidth(30);
  _stepsNumber->setAlignment(Qt::AlignCenter);
  // ADDING LAYOUTS
  //vertical0->addItem(new QSpacerItem(15,10,QSizePolicy::Maximum,QSizePolicy::Maximum));
  vertical1->addWidget(_PaintView);
  horizontal1->addItem(new QSpacerItem(0,10,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal2->addWidget(_comboBox); 
  horizontal2->addWidget(_LoadButton);
  horizontal3->addItem(new QSpacerItem(0,200,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal4->addWidget(_bestPath); 
  horizontal4->addItem(new QSpacerItem(20,0,QSizePolicy::Minimum,QSizePolicy::Minimum));
  horizontal4->addWidget(_bestPathLabel); 
  horizontal5->addWidget(_stepsNumber); 
  horizontal5->addItem(new QSpacerItem(20,0,QSizePolicy::Minimum,QSizePolicy::Minimum));
  horizontal5->addWidget(_stepsNumberLabel); 
  horizontal6->addItem(new QSpacerItem(0,30,QSizePolicy::Minimum,QSizePolicy::MinimumExpanding));
  horizontal7->addWidget(_StepButton); 
  horizontal7->addWidget(_StepBackButton); 
  horizontal8->addWidget(_SolveButton);  
  horizontal9->addItem(new QSpacerItem(0,30,QSizePolicy::Minimum,QSizePolicy::Maximum));
  horizontal10->addWidget(_RestartButton);  
  horizontal11->addItem(new QSpacerItem(0,30,QSizePolicy::Minimum,QSizePolicy::Maximum)); 
  horizontal12->addWidget(_CloseButton);
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
  horizontal->addLayout(vertical1);
  //horizontal->addLayout(vertical2);
  horizontal->addWidget(frame);

  //CONNECTING
  connect(_CloseButton,SIGNAL(clicked()),this,SIGNAL(ReportClosing()));
  connect(_RestartButton,SIGNAL(clicked()),this,SLOT(restartMaze()));
  connect(_StepButton,SIGNAL(clicked()),this,SLOT(stepInMaze()));
  connect(_StepBackButton,SIGNAL(clicked()),this,SLOT(stepBack()));
  connect(_SolveButton,SIGNAL(clicked()),this,SLOT(solveMaze()));
  connect(_LoadButton,SIGNAL(clicked()),this,SLOT(loadMaze()));
  QMetaObject::connectSlotsByName(this);
}

void ControlPanel:: restartMaze()
{
  _PaintView->maze()->restart();
  _PaintView->update();
  stepsNumber();
}

void ControlPanel:: stepInMaze()
{
  _PaintView->maze()->step();
  _PaintView->update();
  stepsNumber();
}

void ControlPanel:: stepBack()
{
  _PaintView->maze()->stepBack();
  _PaintView->update();
  stepsNumber();
}

void ControlPanel:: solveMaze()
{
  _PaintView->maze()->solveMaze();
  _PaintView->update();
  stepsNumber();
}

void ControlPanel:: on_fileName_currentIndexChanged(int index)
{
  _index = index;
}

void ControlPanel:: loadMaze()
{
  _PaintView->newMaze(_fileNames[_index].toStdString());
  stepsNumber();
  bestPathNumber();
  _PaintView->update();
}