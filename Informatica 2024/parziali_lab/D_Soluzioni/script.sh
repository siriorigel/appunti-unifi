#!/bin/bash

# Chiedi all'utente il nome del comando
echo "Inserisci il nome di un comando"
read comando

# Ottieni il manuale del comando
man_output=$(man $comando 2>&1)

# Conta le linee del manuale
linee=$(echo "$man_output" | wc -l)

echo "Il manuale del comando '$comando' contiene $linee linee."

# Imposta i permessi sullo script
#chmod 751 script.sh