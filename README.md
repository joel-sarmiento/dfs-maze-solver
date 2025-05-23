# Maze Solver Using Depth-First Search (DFS)

This project uses DFS to solve a maze input by the user. The program reads in a maze represented as a list of coordinates. The program begins at the start location and explores neighbors with the priority order: RIGHT, DOWN, LEFT, UP.

## Files Included
maze_solver: contains implementation of program  
test_mazes: contains mazes in appropriate format used for testing

## Program Input Format
Number of coordinates  
x y  
x y  
.  
.  
.  
x y (start location)  
x y (end location)  

## Program Output
If a solution is found, the path of coordinates from the start location to end location is printed.
Otherwise, "no solution" is output.

## Test Results
**Note**:  
x: Valid maze path  
S: Start location  
E: End location  
Numbers: Solution path


### Maze 1  
Input:  
![Screenshot 2025-05-22 at 10 16 07 PM](https://github.com/user-attachments/assets/b050a4c9-5fb8-4f3c-8e79-56473a9b896d)

Maze Visual:  
<pre>
  0  1  2  3  4  5
0 x  x 
1    x  x  x
2    x  E  x
3       x  S
4    x  x
</pre>

Output:  
![Screenshot 2025-05-22 at 10 22 49 PM](https://github.com/user-attachments/assets/dd246be0-db34-4502-a65b-affe91cb1937)

Solution Path:  
<pre>
  0  1  2  3  4  5
0 x  x 
1    x  x  x
2    x  3  x
3       2  1
4    x  x
</pre>


### Maze 7  
Input:  
![Screenshot 2025-05-22 at 10 09 30 PM](https://github.com/user-attachments/assets/fb538fea-be47-4df9-bdef-0b790d203c84)

Maze Visual:  
<pre>
  0  1  2  3  4  5
0          x     E  
1    x  x  x  x  x  
2       S        x 
</pre>

Output:  
![Screenshot 2025-05-22 at 10 11 07 PM](https://github.com/user-attachments/assets/60055e34-d577-4b58-8285-b658b8f3fec7)

Solution Path:  
<pre>
  0  1  2  3  4  5
0          x     6  
1    x  2  3  4  5  
2       1        x 
</pre>


### Maze 9  
Input:  
![Screenshot 2025-05-22 at 10 25 45 PM](https://github.com/user-attachments/assets/0469d328-7b59-4f20-a3bb-f7291a30b08c)

Maze Visual:  
<pre>
  0  1  2  3  4  5  6
0                   E
1    x  x        x
2       x  S  x  x
3       x     x
</pre>

Output:  
![Screenshot 2025-05-22 at 10 30 34 PM](https://github.com/user-attachments/assets/a88df39d-3881-4215-a1d5-45d6cb2649ca)


