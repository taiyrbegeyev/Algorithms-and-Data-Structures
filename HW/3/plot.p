set terminal pdf
set output "naiveRecursive.pdf"

# x and y labels
set xlabel "Value of the n"
set ylabel "Computation time, nanoseconds"
set title "Naive Recursive"

# Line styles
set style line 1 \
    linecolor rgb "#0060ad" \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.5

set style line 2 \
    linecolor rgb "#ff0000" \
    linetype 2 linewidth 2 \
    pointtype 7 pointsize 1.5

set style line 3 \
    linecolor rgb "#008000" \
    linetype 3 linewidth 2 \
    pointtype 7 pointsize 1.5

set style line 4 \
    linecolor rgb "#FFD700" \
    linetype 3 linewidth 2 \
    pointtype 7 pointsize 1.5


set grid

plot "fibonacciNaive.dat" using 1:2 title "Graph" with lines linestyle 1

set output "bottomUp.pdf"

set xlabel "Value of the n"
set ylabel "Computation time, nanoseconds"
set title "Bottom Up Approach"

plot "fibonacciBottomUp.dat" using 1:2 title "Graph" with lines linestyle 2

set output "closedForm.pdf"

set xlabel "Value of the n"
set ylabel "Computation time, nanoseconds"
set title "Closed Form"

plot "fibonacciClosedForm.dat" using 1:2 title "Graph" with lines linestyle 3

set output "matrix.pdf"

set xlabel "Value of the n"
set ylabel "Computation time, nanoseconds"
set title "Matrix Representation"

plot "fibonacciMatrix.dat" using 1:2 title "Graph" with lines linestyle 1


set output "ALL.pdf"

set xlabel "Value of the n"
set ylabel "Computation time, nanoseconds"
set title "All"

set yrange [0:10000]
set xrange [0:100]

plot "fibonacciNaive.dat" using 1:2 title "Naive" with lines linestyle 1,\
     "fibonacciBottomUp.dat" using 1:2 title "bottomUp" with lines linestyle 2,\
     "fibonacciClosedForm.dat" using 1:2 title "Closed Form" with lines linestyle 3, \
     "fibonacciMatrix.dat" using 1:2 title "Matrix" with lines linestyle 4
