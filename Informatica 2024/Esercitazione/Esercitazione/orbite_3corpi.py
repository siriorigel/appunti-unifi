import matplotlib.pyplot as plt
import matplotlib.animation as animation
import pandas as pd

# Leggi i dati dal file CSV
data = pd.read_csv('orbita.csv')

# Crea una figura e un asse
fig, ax = plt.subplots()
ax.set_xlim(-5e11, 5e11)
ax.set_ylim(-5e11, 5e11)

# Crea i grafici vuoti per i corpi celesti
sun_plot, = ax.plot([], [], 'yo', markersize=12)  # Sole
earth_plot, = ax.plot([], [], 'bo', markersize=6)  # Terra
moon_plot, = ax.plot([], [], 'go', markersize=4)  # Luna

# Inizializza i dati dei grafici
def init():
    sun_plot.set_data([], [])
    earth_plot.set_data([], [])
    moon_plot.set_data([], [])
    return sun_plot, earth_plot, moon_plot

# Aggiorna i dati per ogni frame dell'animazione
def update(frame):
    sun_plot.set_data(data['Posizione X Sole'][frame], data['Posizione Y Sole'][frame])
    earth_plot.set_data(data['Posizione X Terra'][frame], data['Posizione Y Terra'][frame])
    moon_plot.set_data(data['Posizione X Luna'][frame], data['Posizione Y Luna'][frame])
    return sun_plot, earth_plot, moon_plot

# Crea l'animazione
ani = animation.FuncAnimation(fig, update, frames=range(len(data)), init_func=init, blit=True, interval=50)

# Mostra l'animazione
plt.show()
