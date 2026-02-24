set xlabel 'x'
set ylabel 'Qualche legge fisica'
set xrange[0:6]
set yrange [5:11]
plot 'misure.dat' u 1:2:3 with yerrorbars
pause mouse
set terminal pdf
set output "immagine.pdf"
replot
exit