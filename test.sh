#!/bin/bash

cd src

git checkout master
make
echo "Running single process version..."
echo "./AirportSim 3 4 .1 .1 1440 0 20"
./AirportSim 3 4 .1 .1 1440 0 20

echo
echo

git checkout multi-master
make
echo "Running multiple process version..."
echo "./AirportSim 3 4 .1 .1 1440 0 20 2"
./AirportSim 3 4 .1 .1 1440 0 20 2

echo "./AirportSim 3 4 .1 .1 1440 0 20 2"
./AirportSim 3 4 .1 .1 1440 0 20 2
echo "./AirportSim 3 4 .1 .1 1440 0 20 3"
./AirportSim 3 4 .1 .1 1440 0 20 3
