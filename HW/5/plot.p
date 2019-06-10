set terminal pdf
set output "plot1.pdf"

# x and y labels
set xlabel "Value of the i"
set ylabel "Computation time, microseconds"
set title "Problem 5.1"

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

set grid

plot "output.dat" using 1:2 title "Lomuro Quick Sort"  with lines linestyle 1,\
     "output.dat" using 1:3 title "Hoare Quick Sort" with lines linestyle 2,\
     "output.dat" using 1:4 title "Median of Three Quick Sort" with lines linestyle 3

set output "plot2.pdf"

set xlabel "Value of the i"
set ylabel "Computation time, microseconds"
set title "Problem 5.1"

plot "output.dat" every ::0::1000 using 1:2 title "Lomuro Quick Sort"  with lines linestyle 1,\
     "output.dat" every ::0::1000 using 1:3 title "Hoare Quick Sort" with lines linestyle 2,\
     "output.dat" every ::0::1000 using 1:4 title "Median of Three Quick Sort" with lines linestyle 3

set output "plot3.pdf"

set xlabel "Value of the i"
set ylabel "Computation time, microseconds"
set title "Problem 5.1"

plot "output.dat" every ::0::100 using 1:2 title "Lomuro Quick Sort"  with lines linestyle 1,\
     "output.dat" every ::0::100 using 1:3 title "Hoare Quick Sort" with lines linestyle 2,\
     "output.dat" every ::0::100 using 1:4 title "Median of Three Quick Sort" with lines linestyle 3

