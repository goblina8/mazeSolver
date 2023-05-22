#include "maze.hh"

Maze:: Maze(int size)
{
    srand((unsigned) time(NULL));
    this->size = size;
    string name;
    switch(size)
    {
        case 6:
        {
            name = "mazes/maze6x6.txt";
            /*
            maze[0][0] = Square(0,0,0,0,7);
            maze[0][1] = Square(0,1,0,0,8);
            maze[0][2] = Square(0,2,0,0,2);
            maze[0][3] = Square(0,3,0,0,8);
            maze[0][4] = Square(0,4,0,0,8);
            maze[0][5] = Square(0,5,0,0,6);

            maze[1][0] = Square(1,0,0,0,9);
            maze[1][1] = Square(1,1,0,0,7);
            maze[1][2] = Square(1,2,0,0,10);
            maze[1][3] = Square(1,3,0,0,7);
            maze[1][4] = Square(1,4,0,0,6);
            maze[1][5] = Square(1,5,0,0,9);

            maze[2][0] = Square(2,0,0,0,9);
            maze[2][1] = Square(2,1,0,0,9);
            maze[2][2] = Square(2,2,0,1,7);
            maze[2][3] = Square(2,3,0,1,3);
            maze[2][4] = Square(2,4,0,0,9);
            maze[2][5] = Square(2,5,0,0,9);

            maze[3][0] = Square(3,0,0,0,9);
            maze[3][1] = Square(3,1,0,0,9);
            maze[3][2] = Square(3,2,0,1,11);
            maze[3][3] = Square(3,3,0,1,10);
            maze[3][4] = Square(3,4,0,0,9);
            maze[3][5] = Square(3,5,0,0,9);

            maze[4][0] = Square(4,0,0,0,15);
            maze[4][1] = Square(4,1,0,0,5);
            maze[4][2] = Square(4,2,0,0,8);
            maze[4][3] = Square(4,3,0,0,14);
            maze[4][4] = Square(4,4,0,0,9);
            maze[4][5] = Square(4,5,0,0,9);

            maze[5][0] = Square(5,0,1,0,13);
            maze[5][1] = Square(5,2,0,0,10);
            maze[5][2] = Square(5,3,0,0,13);
            maze[5][3] = Square(5,4,0,0,8);
            maze[5][4] = Square(5,5,0,0,4);
            maze[5][5] = Square(5,6,0,0,10);
            */
            break;
        }
        case 16:
        {
            name = "mazes/maze16x16.txt";
            break;
        }
        default:
        {
            break;
        }
    }
    readMaze(name);
    start();
}

void Maze:: move(int direction)
{
    if(!maze[position_x][position_y].is_it_meta())
    {
        vector<int> xy;
        xy.push_back(position_x);
        xy.push_back(position_y);
        previous_position.push_back(xy);
        switch(direction)
        {
            case 1: //up
            {
                position_x -= 1;
                break;
            }
            case 2: //down
            {
                position_x += 1;
                break;
            }
            case 3: //left
            {
                position_y -= 1;
                break;
            }
            case 4: //right
            {
                position_y += 1;
                break;
            }
            default:
            {
                break;
            }
        }
        maze[position_x][position_y].visit();
        maze[position_x][position_y].robot_image();
        maze[previous_position.back()[0]][previous_position.back()[1]].visited_image();
    }
}

bool Maze:: is_it_start(int x, int y)
{
    return maze[x][y].is_it_start();
}

bool Maze:: is_it_meta(int x, int y)
{
    return maze[x][y].is_it_meta();
}

bool Maze:: is_there_path(int wall_number)
{
    switch(wall_number)
    {
        case 1:
        {
            if(maze[position_x][position_y].is_path(1) == 1)
            {
                move(1);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case 2:
        {
            if(maze[position_x][position_y].is_path(2) == 1)
            {
                move(2);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case 3:
        {
            if(maze[position_x][position_y].is_path(3) == 1)
            {
                move(3);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case 4:
        {
            if(maze[position_x][position_y].is_path(4) == 1)
            {
                move(4);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}

bool Maze:: was_it_visited(int x, int y)
{
    return maze[x][y].was_it_visited();
}

void Maze:: visit(int x, int y)
{
    maze[x][y].visit();
}

void Maze:: unvisit(int x, int y)
{
    maze[x][y].unvisit();
}

void Maze:: start()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(maze[i][j].is_it_start())
            {
                position_x = i;
                position_y = j;
            }
        }
    }
}

void Maze:: restart()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j].basic_image();
            maze[i][j].unvisit();
            if(maze[i][j].is_it_start())
            {
                position_x = i;
                position_y = j;
                maze[i][j].robot_image();
                maze[i][j].visit();
            }
            if(maze[i][j].is_it_meta())
            {
                position_x = i;
                position_y = j;
                maze[i][j].meta_image();
            }
        }
    }
}  

QImage Maze:: image1(int x, int y)
{
    return maze[x][y].image1(); 
}

QImage Maze:: image2(int x, int y)
{
    return maze[x][y].image2(); 
}

int Maze:: what_size()
{
    return size;
}

Square Maze:: square(int x, int y)
{
    return maze[x][y];
}

void Maze:: stepBack()
{
    unvisit(position_x, position_y);
    if(maze[position_x][position_y].was_it_visited() == 0)
    {
        maze[position_x][position_y].basic_image();
    }
    else
    {
        maze[position_x][position_y].visited_image();
    }
    position_x = previous_position.back()[0];
    position_y = previous_position.back()[1];
    maze[position_x][position_y].robot_image();
    previous_position.pop_back();
}


void Maze::step()
{
    vector<int> visited;
    vector<int> not_visited;
    if(maze[position_x][position_y].is_path(1) == 1)
    {
        if(maze[position_x - 1][position_y].was_it_visited() == 1)
        {
            visited.push_back(1);
        }
        else
        {
            not_visited.push_back(1);
        }   
    }
    if(maze[position_x][position_y].is_path(2) == 1)
    {
        if(maze[position_x + 1][position_y].was_it_visited() == 1)
        {
            visited.push_back(2);
        }
        else
        {
            not_visited.push_back(2);
        }   
    }
    if(maze[position_x][position_y].is_path(3) == 1)
    {
        if(maze[position_x][position_y - 1].was_it_visited() == 1)
        {
            visited.push_back(3);
        }
        else
        {
            not_visited.push_back(3);
        }   
    }
    if(maze[position_x][position_y].is_path(4) == 1)
    {
        if(maze[position_x][position_y + 1].was_it_visited() == 1)
        {
            visited.push_back(4);
        }
        else
        {
            not_visited.push_back(4);
        }   
    }
    if((visited.size() == 0) && (not_visited.size() == 0)) //no way out
    {
        cout << "No way out" << endl;
    }
    if((not_visited.size() > 0)) //if there is any not checked way
    {
        int index = (rand()%(not_visited.size()));
        move(not_visited[index]);
    }
    else //if there is only checked way
    {
        int index = (rand()%(visited.size()));
        move(visited[index]);
    }
}
void Maze:: solveMaze()
{
    while(!(maze[position_x][position_y].is_it_meta()))
    {
        step();
    }
}

void Maze:: readMaze(string& name)
{
    ifstream txt;
    int size = 0;
    txt.open(name);
    string line;
    if(txt.is_open())
    {
        getline(txt,line);
        if(line[0] == '#')
        {
            if(line[2] != '#')
            {
                size = (line[1]-48)*10+line[2]-48;
            }
            else
            {
                size = line[1] - 48;
            }
        }
        int x = 0;
        int number = 1;
        bool start = 0;
        bool meta = 0;
        while(x < size)
        {
            getline(txt,line);
            int k = 0;
            int y = 0;
            while(y != size)
            {
                if(line[k] == ' ')
                {
                    maze[x][y] = Square(x,y,start,meta,number);
                    y++;
                    start = 0;
                    meta = 0;
                }
                else
                {
                    int numb = isdigit(line[k]);
                    if(numb == 0)
                    {
                        if(line[k] == 's')
                        {
                            start = 1;
                        }
                        else if (line[k] == 'm')
                        {
                            meta = 1;
                        }
                    }
                    else
                    {
                        if(isdigit(line[k+1]) == 0)
                        {
                            number = line[k]-48;
                        }
                        else
                        {
                            number = (line[k]-48)*10+line[k+1]-48;
                            k++;
                        }
                    }
                }
                k++;
            }
            x++;
        }
    }
    else
    {
        cout << "NO SUCH FILE" << endl;
    }
}
