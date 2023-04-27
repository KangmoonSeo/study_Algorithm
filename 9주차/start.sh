## compile
g++ -w -c main.cpp
g++ -w -c sorting.cpp
g++ main.o sorting.o -o main

## execute
./main
echo ""

## delete
rm main.o sorting.o main
