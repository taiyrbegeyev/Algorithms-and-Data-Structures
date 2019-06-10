How to run the mergeSort.cpp
----------------------------
$ make


How to delete object files
--------------------------
$ make clean


Where the computation times for different cases are stored 
----------------------------------------------------------
* for different k using the same array ---- output1.dat
* for k = 20 using different arrays  ---- output2.dat
* for k = 50 using different arrays ---- output3.dat


How to draw a plot
--------------------------
I used Gnuplot to draw graphs
* plot1.pdf is the test of the algorithm for different k using the same array 
* plot2.pdf is the test of the algorithm for k = 20 using different arrays
* plot3.pdf is the test of the algorithm for k = 50 using different arrays

__plot.p__ script retrieves the data from output1.dat, output2.dat, output3.dat
and writes to plot1.pdf, plot2.pdf, plot3.pdf

$ gnuplot plot.p
