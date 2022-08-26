#!/bin/bash

echo remove cache files\n

rm -rf . @
rm -rf ./.
rm 1 2 3
rm -rf ././.

echo git add
    git add .
echo git commit
    git commit -m $1 -m $2
echo git push
    git push
