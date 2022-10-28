===Description===
This is the HW2 of the class Data Structure (Deadline - 2022/10/28)
This program is written in C++11.
Name of file : HW1_F74106270.zip
Structure :
|-HW1_F74106270.rar (.zip) 
| |-HW1_F74016270 (Folder)
| | |-main.cpp
| | |-main.exe
| | |-maze1.txt
| | |-maze2.txt
| | |-sample_output.txt
| | |-sample_output1.txt
| | |-Readme.txt

This program finds a path for a mouse from the starting point(1,0) to the end(15,16), 
and prints out the path the mouse went finding also printing out if the mouse escape the maze. 

Functions / Struct / Input Output File in the program : 
* ifstream myfile : the input file used in the program.
* ofstream myfileout : where the output of Path is put.
* struct pos : stores the x and y position of the path and adds to a queue.
* static int matrix[17][17] : stores the 1 and 0 in this matrix that represents the maze
* static int mark[17][17] : a copy of the matrix, but the path that has been gone through would be changed to 1
* struct offsets : used to represent the eight position x and y increase/decrease value
* struct Items : x is for the x position, y is for y position and dir for the direction(offsets)
* enum directions : directions start from E clockwise to NE giving it value 0 - 7
* static void Path(const int m, const int p) : (m,p) is the destination of the maze. 
    Path prints out the path that it went through and if the mouse found escaped or not and stores it in myfileout.
    Creates a stack<Items> st that stores the position the mouse walks.
    (1,0) is the starting point and it starts by checking if the east of the current position is 0 or 1, 
    if it is 1, it goes to that position and stacks it in st, if it is 0, it skips that position and go to the next direction.
    if the mouse cannot find any positon to go foward, it goes back to the previous position.
* int main() : the main of the program, asks which file to input and opens the input file and the corresponding output file. 
    Then runs Path(). Lastly, return 0.