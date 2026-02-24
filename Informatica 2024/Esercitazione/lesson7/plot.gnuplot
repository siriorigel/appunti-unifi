# plot.gnuplot

# Dati di input
datafile = 'misure.dat'
outputfile = 'istogramma_gaussiana.png'
gaussfile = 'gauss.dat'

# Parametri dell'istogramma
binwidth = 0.05
set boxwidth binwidth
bin(x, width) = width * floor(x / width) + binwidth / 2.0

# Settaggi di Gnuplot
set terminal png
set output outputfile
set title "Istogramma delle misure con sovrapposizione gaussiana"
set xlabel "Valore"
set ylabel "Frequenza"
set style fill solid 0.5

# Normalizzazione dell'istogramma
set yrange [0:*]
stats datafile u 1 nooutput
n = STATS_records
norm_factor = n * binwidth

# Trama dell'istogramma normalizzato e della gaussiana
plot datafile u (bin($1, binwidth)):(1.0/norm_factor) smooth freq with boxes title "Misure", \
     gaussfile u 1:2 w lines title 'Gaussiana'
