# Sudoku Solver
---
### Installation
- Download the repository either by downloading as zip or by the command

```git clone https://github.com/Ashwin-Rajesh/Sudoku_Solver.git```
- Now move to the folder using

```cd Sudoku_Solver```
- Now, run the makefile

``` make```
- Now, run the sudoku executable by passing some example

```./sudoku```

---
### Working
- The algorithm used here uses a combination of backtracking and a custom designed system that cascades logical deductions that can be made from confirmation of values in cells. This system keep tracks of lists of
  - Which numbers can be placed in a cell
  - Which cells can a number go in a row/column/3x3 section

- Confirming a number in a cell leads to the following effects:
  - The number is removed from possibilities from all other cells in the same row/column/3x3
  - The cell confirmed is removed from possible positions list of the corresponding row/column/3x3

- A number is confirmed in a cell when either of these happens
  - Only one number is possible to be placed in the position
  - A number can be placed only in one position in a row/column/3x3
  
- If a number cannot be confirmed, we make a random guess where there are minimum number of possible numbers, and then backtrack if we detect an impossible situation, which is characterized by
  - No number can be placed in a cell
  - A number cannot go anywhere in a row/column/3x3 section
