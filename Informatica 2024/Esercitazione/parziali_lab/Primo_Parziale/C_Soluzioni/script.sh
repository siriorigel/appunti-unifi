#!/bin/bash

# Estrarre le righe dal manuale del comando ncal in cui compare la parola "Display"
man ncal | grep -i "Display"

#chmod 764 script.sh

#Il numero 764 rappresenta i permessi:
#7 per l'utente: lettura, scrittura, esecuzione.
#6 per il gruppo: lettura, scrittura.
#4 per il mondo: esecuzione.