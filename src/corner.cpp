#include "corner.hh"

Corner:: Corner(int _x, int _y, int _corner, int _graphics)
{
    x = _x;
    y = _y;
    corner = _corner;
    set(_graphics);
}

QImage Corner:: image()
{
    return hole;
}

int Corner:: position_x()
{
    return x;
}

int Corner:: position_y()
{
    return y;
}

bool Corner:: cornerX()
{
    if(corner == 1 || corner == 3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool Corner:: cornerY()
{
    if(corner == 1 || corner == 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Corner:: ul_set()
{
    QString name = ":/img/up_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    hole.load(fullPath);
}

void Corner:: ur_set()
{
    QString name = ":/img/up_right";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    hole.load(fullPath);
}

void Corner:: dl_set()
{
    QString name = ":/img/down_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    hole.load(fullPath);
}

void Corner:: dr_set()
{
    QString name = ":/img/down_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    hole.load(fullPath);
}

void Corner:: set(int _graphics)
{
    graphics = _graphics;
    switch (corner)
    {
        case 1:
        {
            ul_set();
            break;
        }
        case 2:
        {
            ur_set();
            break;
        }
        case 3:
        {
            dl_set();
            break;
        }
        case 4:
        {
            dr_set();
            break;
        }
    }
}

