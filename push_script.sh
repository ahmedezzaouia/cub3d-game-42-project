#!/bin/bash

echo remove cache files
echo -n .
sleep 1
echo -n .
sleep 1
echo -n .
sleep 1
echo -n .
sleep 1
echo -n .
sleep 1

clear

rm -rf .
rm -rf ./.
rm 1 2 3
rm -rf ././.
rm ./cub3d/cub3d
rm -rf ./cub3d/cub3d.dSYM

clear

echo git add
sleep 1
    git add .
clear

echo git commit
sleep 1
    git commit -m $1 -m $2
clear

echo git push
sleep 1
    git push
clear
