#!/bin/bash
NUM_ITERATIONS=10

SIZE=4
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=16
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=64
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=256
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=1024
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=4096
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=16384
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=655536
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=262144
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done

SIZE=524288
rm -f sharedmemory_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./sharedMemory $SIZE >> sharedmemory_latency_$SIZE.txt
done
