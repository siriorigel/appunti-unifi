#!/bin/bash

echo Inserisci il nome del programma che vuoi eseguire
ls
read variable
gcc $variable
./a.out
exit 0
