/* There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.) */

class Solution {
  
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        vector<int> cell_tmp(8);
        vector<vector<int>> result;
        while(N--){
          for(int j = 1;j < 7;j++){
                cell_tmp[j] = cells[j-1] == cells[j+1];
          }
           
          if(result.size() && result.front() == cell_tmp)
              return result[N%result.size()]; 					//Pattern is repeated after 14th iteration 
          else
              result.push_back(cell_tmp);
          cells = cell_tmp;
           
        }
            
        
    return cells; 
    }
       
        
    
};