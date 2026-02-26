set title "Distribuzione dei fotoni riflessi"
set xlabel "Numero di fotoni riflessi"
set ylabel "Frequenza"
bin_width = 1
bin(x, width) = width * floor(x / width)
plot "exp.dat" using (bin($1, bin_width)):(1) smooth frequency with boxes title "Riflessioni"
pause mouse