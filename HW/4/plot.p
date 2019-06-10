set terminal pdf
set output "file.pdf"

# x and y labels
set xlabel "Value of the n"
set ylabel "Computation time, micro"
set title "Heap Sort"

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

