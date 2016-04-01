set terminal png
set output "couloir.png"

set title "signal dans le couloir"
set xlabel "distance m"
set ylabel "puissance db"
plot "mesures/couloir" with linespoints 