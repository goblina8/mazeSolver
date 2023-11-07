#include "dijkstra.hh"

Dijkstra:: Dijkstra(int _size, Square (&_maze)[16][16])
{
    size = _size;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            vertex_value[i][j] = 10000;
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            vertex[i][j] = &_maze[i][j];
            if(vertex[i][j]->is_it_start() == 1)
            {
                vertex_value[i][j] = 0;
                source_x = i; //row
                source_y = j; //column
            }
        }
    }
}

bool Dijkstra:: isThereWayOut()
{
    return way_out;
}

int Dijkstra:: ReturnMovement()
{
    return move[step_count];
}

vector<int> Dijkstra::ReturnPath()
{
    return path[step_count];
}

void Dijkstra:: step()
{
    step_count++;
}

void Dijkstra:: stepBack()
{
    step_count--;
}

void Dijkstra:: solve() //1up, 2down, 3left, 4right
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int solved_x = -1;
    int solved_y = -1;
    int direction = 0;
    priority_queue<pair<int, pair<int, int>>> prio_que;
    prio_que.push({vertex_value[source_x][source_y], {source_x, source_y}});
    while(!prio_que.empty())
    {
        pair<int, pair<int, int>> current = prio_que.top();
        prio_que.pop();
        int x = current.second.first;
        int y = current.second.second;
        int dist = -current.first;
    
        if (vertex[x][y]->is_it_meta() == 1)
        {
            solved_x = x;
            solved_y = y;
            break;
        } 

        for (int i = 0; i < 4; i++) // up / down / left / right
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (vertex[x][y]->is_path(i+1) == 1) 
            {
                int new_dist = dist + 1; 
                if(new_dist < vertex_value[new_x][new_y])
                {
                    vertex_value[new_x][new_y] = new_dist;
                    prio_que.push({-new_dist, {new_x, new_y}}); 
                }
            }

        }
        
    }
    path.clear();
    move.clear();
    while((solved_x != source_x) || (solved_y != source_y)) 
    {
        path.push_back({solved_x, solved_y});
        if (direction != 0)
        {
            move.push_back(direction);
        }
        int min_distance = vertex_value[solved_x][solved_y];
        int prev_solved_x = solved_x;
        int prev_solved_y = solved_y;
        for (int i = 0; i < 4; i++) // up / down / left / right
        {
            int new_x = solved_x + dx[i];
            int new_y = solved_y + dy[i];
            
            if (vertex[solved_x][solved_y]->is_path(i+1) == 1) 
            {
                if(vertex_value[new_x][new_y] == min_distance-1)
                {
                    solved_x = new_x;
                    solved_y = new_y;
                    if(i+1 == 1){direction = 2;}
                    else if(i+1 == 2){direction = 1;}
                    else if(i+1 == 3){direction = 4;}
                    else if(i+1 == 4){direction = 3;}
                    break;
                }
            }
            else
            {
                direction = 0;
            }
        }

        if (solved_x == prev_solved_x && solved_y == prev_solved_y) {
            direction = 0;  // Cannot find the next square to move, reset the direction
        }
    }
    move.push_back(direction);
    reverse(path.begin(), path.end());
    reverse(move.begin(), move.end());
    way_out = !path.empty();

    if(way_out)
    {
        step_count = 0;
    }
}


