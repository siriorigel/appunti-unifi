#!/bin/bash

# Percorso del README.md
readme_path="../README.md"

# Ottieni la versione corrente dal README.md utilizzando awk
current_version=$(awk '/^Versione:/ {print $2}' "$readme_path")

# Verifica se la versione è stata ottenuta correttamente
if [ -z "$current_version" ]; then
    echo "Errore: non è stato possibile ottenere la versione corrente dal README.md."
    exit 1
fi

# Estrai i componenti della versione corrente
IFS='.' read -r major minor patch <<< "$current_version"

# Incrementa la versione del patch di 1
new_version="$major.$minor.$((patch + 1))"

# Sostituisci la versione nel file README.md
sed -i.bak "s/^Versione: $current_version/Versione: $new_version/" "$readme_path"

# Aggiungi il README.md allo staging area
git add "$readme_path"

# Esegui il commit con un messaggio descrittivo
git commit -m "Aggiornamento automatico della versione e della data nel README.md"

# Push delle modifiche nel repository remoto
git push origin master

# Notifica all'utente che la versione è stata aggiornata
echo "La versione nel README.md è stata aggiornata a $new_version."
