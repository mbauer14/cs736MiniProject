#!/bin/bash
NUM_ITERATIONS=10

SIZE=4
PORT=5000
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=16
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=64
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=256
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=1024
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=4096
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=16384
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=655536
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=262144
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

SIZE=524288
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep 1
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done
