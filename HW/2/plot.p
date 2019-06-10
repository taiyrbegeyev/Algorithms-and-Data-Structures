set terminal pdf
set output "plot1.pdf"

# x and y labels
set xlabel "Value of the k"
set ylabel "Computation time, ms"
set title "Problem 2.1 (c)"

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

plot "output1.dat" using 1:2 title "Worst Case"  with lines linestyle 1,\
     "output1.dat" using 3:4 title "Average Case" with lines linestyle 2,\
     "output1.dat" using 5:6 title "Best Case" with lines linestyle 3


set output "plot2.pdf"

set xlabel "Value of the n"
set ylabel "Computation time, ms"
set title "Problem 2.1 (b) k = 20"

plot "output2.dat" using 1:2 title "Worst Case"  with lines linestyle 1,\
     "output2.dat" using 3:4 title "Average Case" with lines linestyle 2,\
     "output2.dat" using 5:6 title "Best Case" with lines linestyle 3

set output "plot3.pdf"

set xlabel "Value of the n"
set ylabel "Computation time, ms"
set title "Problem 2.1 (b) k = 50"

plot "output3.dat" using 1:2 title "Worst Case"  with lines linestyle 1,\
     "output3.dat" using 3:4 title "Average Case" with lines linestyle 2,\
     "output3.dat" using 5:6 title "Best Case" with lines linestyle 3

