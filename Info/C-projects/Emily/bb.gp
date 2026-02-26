set ylabel 'P (kW m^{−2} nm^{ −1})'
set xlabel 'wavelength (nm)'
plot 'dati.txt' u 1:2 w lines
pause mouse