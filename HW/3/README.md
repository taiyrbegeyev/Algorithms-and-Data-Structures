How to run the program
----------------------------
$ make


How to delete object files
--------------------------
$ make clean


Where the computation times for different cases are stored 
----------------------------------------------------------
* for Naive Recursive ---- fibonacciNaive.dat
* for Bottom Up  ---- fibonacciBottomUp.dat
* for Closed Form ---- fibonacciClosesForm.dat
* for Matrix ---- fibonacciMatrix.dat


How to draw a plot
--------------------------
I used Gnuplot to draw graphs
* plot1.pdf is the test of the algorithm for different k using the same array 
* plot2.pdf is the test of the algorithm for k = 20 using different arrays
* plot3.pdf is the test of the algorithm for k = 50 using different arrays

* **plot.p** script retrieves the data from fibonacciNaive.dat, fibonacciBottomUp.dat, fibonacciClosesForm.dat, fibonacciMatrix.dat and writes to naiveRecursive.pdf, bottomUp.pdf, closedForm.pdf, matrix.pdf respectively
* All.pdf ---- all four methods are drawn

$ gnuplot plot.p