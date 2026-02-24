import matplotlib.pyplot as plt
import csv

# Liste per memorizzare i dati
days = []
positions_x = []
positions_y = []

# Lettura dei dati dal file CSV
with open('orbita.csv', 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        days.append(int(row['Giorno']))
        positions_x.append(float(row['Posizione X (m)']))
        positions_y.append(float(row['Posizione Y (m)']))

# Creazione del grafico
plt.figure(figsize=(8, 8))
plt.plot(positions_x, positions_y, label='Orbita del pianeta')
plt.scatter([0], [0], color='orange', label='Sole') # Posizione del sole
plt.xlabel('Posizione X (m)')
plt.ylabel('Posizione Y (m)')
plt.title('Simulazione dell\'orbita planetaria')
plt.legend()
plt.grid()
plt.axis('equal') # Per mantenere le proporzioni
plt.show()
