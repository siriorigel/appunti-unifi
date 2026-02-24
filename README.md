# 📚 Appunti UniFi – Fisica e Astrofisica

Repository che raccoglie gli appunti scritti in **LaTeX** durante la laurea triennale in Fisica e Astrofisica presso l’Università degli Studi di Firenze.

L’obiettivo è creare una raccolta ordinata, accessibile e migliorabile nel tempo di materiale utile per studio, ripasso e approfondimento.

---

## 📂 Struttura del Repository

Gli appunti sono organizzati per:

- 📁 **Anno di corso**
- 📁 **Insegnamento**
- 📄 File `.tex` sorgenti
- 📦 Eventuali PDF compilati
- 📊 Figure e immagini in cartelle dedicate

Ogni cartella di corso può contenere:

- Appunti completi o parziali  
- Esercizi svolti  
- Materiale integrativo  
- File di configurazione LaTeX  

---

## ⚙️ Requisiti

Per compilare i file è necessario avere installato:

- Una distribuzione LaTeX (TeX Live, MikTeX, ecc.)
- Un editor LaTeX (Overleaf, VS Code, TeXstudio, ecc.)

Compilazione standard:

```bash
pdflatex main.tex
```
In alternativa, se presente:
```bash
latexmk -pdf main.tex
```

## 📜 Regole
- Non ci sono regole
- Se trovi errori, apri una Issue o proponi una Pull Request.

## 🤝 Contribuire

I contributi sono benvenuti e aiutano a migliorare la qualità e la completezza degli appunti.

Puoi contribuire in diversi modi:

- 📝 Correggendo errori o refusi  
- 📚 Aggiungendo chiarimenti o spiegazioni  
- 📈 Migliorando impaginazione, struttura o organizzazione  
- ✍️ Inserendo nuovi appunti o esercizi svolti

### Come contribuire
1. Fai un fork del repository  
2. Crea un nuovo branch  
   ```bash
   git checkout -b nome-branch
   ```
3. Effettua le modifiche
4. Fai commit
   ```bash
   git commit -m "Descrizione modifiche"
   ```
5. Pusha il branch sul tuo fork
   ```bash
   git push origin nome-branch
   ```
6. Apri una Pull request
