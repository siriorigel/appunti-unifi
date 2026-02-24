import numpy as np
import matplotlib.pyplot as plt

# Funzione d'onda per l'orbitale 1s dell'idrogeno
def hydrogen_wavefunction_1s(r):
    a0 = 1  # Raggio di Bohr
    psi = (1 / np.sqrt(np.pi * a0**3)) * np.exp(-r / a0)
    return psi

# Genera valori per r
r_values = np.linspace(0, 10, 1000)

# Calcola gli orbitali atomici per ogni atomo di elio (He2)
orbital_1s_he1 = hydrogen_wavefunction_1s(r_values)
orbital_1s_he2 = hydrogen_wavefunction_1s(r_values)

# Combinazione degli orbitali atomici per formare orbitali molecolari semplificati
orbital_sigma_g = orbital_1s_he1 + orbital_1s_he2  # Orbitale legante sigma_g
orbital_sigma_u = orbital_1s_he1 - orbital_1s_he2  # Orbitale anti-legante sigma_u

# Plot degli orbitali
plt.plot(r_values, orbital_sigma_g, label='Orbitale $\sigma_g$')
plt.plot(r_values, orbital_sigma_u, label='Orbitale $\sigma_u$')
plt.title('Orbitali molecolari semplificati di $He_2$')
plt.xlabel('Raggio (a0)')
plt.ylabel('Densità di probabilità')
plt.legend()
plt.grid(True)
plt.show()
