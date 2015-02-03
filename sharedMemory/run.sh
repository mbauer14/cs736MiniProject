#!/bin/bash
NUM_ITERATIONS=10

SIZE=4
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=16
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=64
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=256
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=1024
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=4096
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=16384
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=655536
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=262144
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done

SIZE=524288
rm -f latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> latency_$SIZE.txt
done
