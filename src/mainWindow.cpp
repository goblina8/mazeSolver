#include "mainWindow.hh"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
  _ControlPanel = new ControlPanel(this);
  setStatusBar(new QStatusBar());
  resize(300,230);
  setCentralWidget(_ControlPanel);
  setMinimumWidth(670);
  setMinimumHeight(420);
  setMaximumWidth(850);
  setMaximumHeight(650);
  connect(_ControlPanel,SIGNAL(reportSign(const QString &)),this,SLOT(receiveStatus(const QString &)));
  connect(_ControlPanel,SIGNAL(reportClosing()),this,SLOT(whenClosed()));
}

void MainWindow::receiveStatus(const QString &Napis)
{
  statusBar()->showMessage(Napis);
}
 
bool MainWindow::canBeClosed()
{
  return QMessageBox::question(this,tr("Warning"), tr("Do you really want to close the application?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No) == QMessageBox::Yes;
}
 
void MainWindow::closeEvent( QCloseEvent * event )
{
  if (canBeClosed()) event->accept();
                    else event->ignore();
}

void MainWindow::whenClosed()
{
  if (canBeClosed()) 
  {
    qApp->quit();
  }
}

void MainWindow:: keyPressEvent(QKeyEvent * event)
{
  if(event->key() == Qt::Key_W)
  {
    _ControlPanel->maze()->is_there_path(1);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_S)
  {
    _ControlPanel->maze()->is_there_path(2);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_A)
  {
    _ControlPanel->maze()->is_there_path(3);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_D)
  {
    _ControlPanel->maze()->is_there_path(4);
    _ControlPanel->paintView()->update();
  }
  if(event->key() == Qt::Key_B)
  {
    _ControlPanel->maze()->stepBack();
    _ControlPanel->paintView()->update();
  }
  _ControlPanel->stepsNumber();
}
