#!/bin/bash

ls
echo "Di quale file o directory vuoi la dimensione?"
read filedirectory
du -hs $filedirectory
touch Test.sh
exit 0
