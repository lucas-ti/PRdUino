#!/bin/bash

g++ test.cpp -o test
./test
clpru PRUEnergiaFile.c -o3 -k --symdebug:none -z AM3359_PRU.cmd -o PRUEnergiaFile.out -m PRUEnergiaFile.map
hexpru bin.cmd PRUEnergiaFile.out
