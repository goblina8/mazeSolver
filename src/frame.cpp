#include "frame.hh"

Frame:: Frame (int _x, int _y, int _graphics, int _size)
{
    x = _x;
    y = _y;
    size = _size;
    set(_graphics);
}

QImage Frame:: image()
{
    return frame;
}

int Frame:: position_x()
{
    return x;
}

int Frame:: position_y()
{
    return y;
}

void Frame:: ul_set()
{
    QString name = ":/img/up_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: ur_set()
{
    QString name = ":/img/up_right";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: dl_set()
{
    QString name = ":/img/down_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: dr_set()
{
    QString name = ":/img/down_right";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: left_set()
{
    QString name = ":/img/left_side";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: right_set()
{
    QString name = ":/img/right_side";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: up_set()
{
    QString name = ":/img/up_side";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: down_set()
{
    QString name = ":/img/down_side";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    frame.load(fullPath);
}

void Frame:: set(int _graphics)
{
    graphics = _graphics;
    if(x == 0)
    {
        if(y == 0)
        {
            ul_set();
            cout << x << " " << y << " ul" << endl;
        }
        else if(y == size - 1)
        {
            ur_set();
            cout << x << " " << y << " ur" << endl;
        }
        else 
        {
            up_set();
             cout << x << " " << y << " up" << endl;
        }
    }
    else if (x == size-1)
    {
        if(y == 0)
        {
            dl_set();
             cout << x << " " << y << " dl" << endl;
        }
        else if(y == size - 1)
        {
            dr_set();
             cout << x << " " << y << " dr" << endl;
        }
        else 
        {
            down_set();
             cout << x << " " << y << " down" << endl;
        }
    }
    else
    {
        if(y == 0)
        {
            left_set();
             cout << x << " " << y << " left" << endl;
        }
        else
        {
            right_set();
             cout << x << " " << y << " right" << endl;
        }
    }
}