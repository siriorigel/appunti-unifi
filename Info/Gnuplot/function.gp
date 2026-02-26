set terminal svg size 1280,960
set title "Temperature" tc rgb 0xffffff
set border 3 lc rgb 0xffffff
set key right box tc rgb 0xffffff
set tics nomirror
set ylabel "Intensità luminosa" tc rgb 0xffffff
set xlabel "Lunghezza d'onda" tc rgb 0xffffff
set xrange[0.00000000001:0.0000000010]
set output "function.svg"
plot (6.62607015*10**(-34) * 2 * 300000**2 * exp(-(6.62607015*10**(-34) * 300000) / (1.38*10**(-23) * x * 12000 ))) / (x**5) lc 6 title "12000K", (6.62607015*10**(-34) * 2 * 300000**2 * exp(-(6.62607015*10**(-34) * 300000) / (1.38*10**(-23) * x * 9000))) / (x**5) lc 4 title "9000", (6.62607015*10**(-34) * 2 * 300000**2 * exp(-(6.62607015*10**(-34) * 300000) / (1.38*10**(-23) * x * 6000 ))) / (x**5) lc 7 title "6000"

