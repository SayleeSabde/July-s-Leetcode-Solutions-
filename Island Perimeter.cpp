/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
       int land = 0;
       int edge = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    land ++;
                    if(i > 0 && grid[i-1][j] == 1){ 
                        edge ++; 
                    }
                    if(j > 0 && grid[i][j-1] == 1){ 
                        edge ++; 
                    }
                }
            }
        }
        
        return land * 4 - edge * 2;
    }
};