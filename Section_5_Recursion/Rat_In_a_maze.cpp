#include <iostream>
#include <vector>
using namespace std;

void Maze(vector<vector <int>> maze , vector<string> &paths , string temp, int i , int j)
{

    if(i == maze[0].size()-1 && j == maze[0].size()-1)
    {
        paths.push_back(temp);
        return;
    }

    if(i < maze[0].size()-1) // Down
    {

        if(maze[i+1][j] != 0)
        {
            Maze(maze , paths, temp +"D", i+1 , j);
        }

    }

    if(j < maze[0].size()-1) // Right
    {
        if(maze[i][j+1] != 0)
        {
            Maze(maze , paths, temp +"R", i , j+1);
        }
    }

}

int main()
{   
    vector<string> paths = {};
    vector<vector<int>> arr = 
    {
    {1 , 0 , 0 , 0},
    {1 , 1 , 0 , 1},
    {1 , 1 , 0 , 0},
    {0 , 1 , 1 , 1}
    };
    string t;
    Maze(arr , paths, t , 0 , 0);
    cout << "Total Paths calculated : " << paths.size() << endl;
    if(paths.size() == 0)
    {
        cout << "No Paths available" << endl;
        return 0;
    }
    cout << "Paths: " << endl;
    for(auto i : paths)
    {
        cout << i << endl;
    }
    return 0;
    
}