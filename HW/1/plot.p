set terminal pdf
set output "plot.pdf"

# x and y labels
set xlabel "Input"
set ylabel "Computation time"
set title "Problem 1.2 (d)"

# Line styles
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 2
set style line 3 linecolor rgb '#00ff00' linetype 1 linewidth 2

# x and y ranges
set xrange [0:7000]
set yrange [0:300]

set grid

plot "output" using 5:6 title "Worst Case" with lines linestyle 1,\
"output" using 1:2 title "Average Case" with lines linestyle 2,\
"output" using 3:4 title "Best Case"with lines linestyle 3