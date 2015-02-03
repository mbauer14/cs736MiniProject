#!/bin/bash
NUM_ITERATIONS=100

SIZE=4
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=16
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=64
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=256
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=1024
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=4096
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=16384
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=65536
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=262144
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=524288
rm -f sharedMemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedMemory_latency_$SIZE.txt
done

echo "Finished $SIZE"
