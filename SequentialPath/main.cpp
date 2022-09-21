#include <iostream>
#include <vector>

/*
finds the length of the longest sequential path
in a square matrix of integers from user input
*/

int PathCalculator(int x, int y, std::vector<std::vector<int>> &path)
{
    int s = path.size();
    if (x<0 || x>s-1 || y<0 || y>s-1) return 0;
    std::cout<< "Worked 1" << std::endl; 
    int val = path[x][y];

    int path_length = 0;
    int current;
    
    if (x<s-1)
    {
        current = PathCalculator(x+1, y, path);
        if (path[x+1][y]>val && current>path_length) path_length = current;
        if (y<s-1)
        {
            current = PathCalculator(x+1, y+1, path);
            if (path[x+1][y+1]>val && current>path_length) path_length = current;
        }
        if (y>0)
        {
            current = PathCalculator(x+1, y-1, path);
            if (path[x+1][y-1]>val && current>path_length) path_length = current;
        }
    }
    if (y<s-1)
    {
        current = PathCalculator(x, y+1, path);
        if (path[x][y+1]>val && current>path_length) path_length = current;
        if (x>0)
        {
            current = PathCalculator(x-1, y+1, path);
            if (path[x-1][y+1]>val && current>path_length) path_length = current;
        }
    }
    std::cout<< "Worked 2" << std::endl; 
    if(x>0)
    {
        current = PathCalculator(x-1, y, path);
        if (path[x-1][y]>val && current>path_length) path_length = current;
        if(y>0)
        {
            current = PathCalculator(x-1, y-1, path);
            if (path[x-1][y-1]>val && current>path_length) path_length = current;
        }
    }
    std::cout<< "Worked 3" << std::endl; 
    if (y>0)
    {
        current = PathCalculator(x, y-1, path);
        if (path[x][y-1]>val && current>path_length) path_length = current;
    }
    return path_length+1;
};

// assumes a square matrix
int SeqPathLength(std::vector<std::vector<int>> &path)
{
    int len = path.size();
    int max_path = 1;
    int current;
    for (int i = 0; i<len; i++)
    {
        for (int j = 0; j<len; j++)
        {
            current = PathCalculator(i, j, path);
            if (max_path < current) max_path = current;
        }
    }
    return max_path;
};

int main()
{
    // assigning the matrix
    int N = 2;
    std::vector<std::vector<int>> mat(N,std::vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> mat[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << SeqPathLength(mat) << std::endl;
    return 0;
}