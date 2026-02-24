import matplotlib.pyplot as plt
import pandas as pd

# Leggi il file CSV
data = pd.read_csv('Simulation.csv')

# Crea il grafico
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot(data['x1'], data['y1'], data['z1'], label='Corpo 1')
ax.plot(data['x2'], data['y2'], data['z2'], label='Corpo 2')
ax.plot(data['x3'], data['y3'], data['z3'], label='Corpo 3')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()

plt.show()
