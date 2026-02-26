set title ""
set border 3
set key right box
set tics nomirror
set ylabel ""
set xlabel ""
set xrange[:]
set output plot.pdf
plot "plot.dat" using 1:2:3 with errorbars lc 7 title "", "plot.dat" using 1:2 with points pointtype 7 pointsize 1 lc 7 notitle
unset output
