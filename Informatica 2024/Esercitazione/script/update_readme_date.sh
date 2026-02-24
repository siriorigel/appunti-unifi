#!/bin/bash

# Ottieni la data attuale
current_date=$(date +"%A %d %B %Y")

# Sostituisci la data nel file README.md
sed -i.bak "s/Ultimo aggiornamento:.*/Ultimo aggiornamento: $current_date/" ../README.md

# Controlla se ci sono modifiche nel README.md

if [[ $(git status --porcelain README.md) ]]; then
    # Aggiungi il README.md allo staging area
    git add ../README.md

    # Esegui il commit con un messaggio descrittivo
    git commit -m "Aggiornamento data nel README.md"

    # Push delle modifiche nel repository remoto
    git push origin master
fi
