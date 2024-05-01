# Third-degree-graph
A basic graphing program made with c++ <br />
The source that I got the graphics.h library from: <br />
https://www.geeksforgeeks.org/include-graphics-h-codeblocks/ <br />
Tweaks explained:<br />
x_range means the difference between each marker in the x axis and y_range means likewise.
increment is for what value the each pixel will correspond to.<br />
For example:<br />
A graph that is 1000x1000 that has 100 x and y range and 0.01 increment will have 10 markers on each axis, each marker representing an integer. Each pixel will correspond to the 1/100th of an integer.
Default settings are 800x600, 10 x and y range with 0.1 increment.
