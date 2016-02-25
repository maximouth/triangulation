set terminal png
set output "salle.png"

set title "signal dans la salle"
set xlabel "distance m"
set ylabel "puissance db"
plot "mesures/salle" with linespoints 