set terminal svg size 1280,960
set title "Compatibilità rho"
set border 3
set key right box
set tics nomirror
set ylabel "rho"
set xlabel "N"
set xrange[0:4]
set output "plot3.svg"
plot "plot3.dat" using 1:2:3 with errorbars lc 7 title "rho_x", "plot3.dat" using 1:2 with points pointtype 7 pointsize 1 lc 7 notitle
unset output