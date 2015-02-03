#!/bin/bash
NUM_ITERATIONS=100

SIZE=4
PORT=5001
SLEEP_TIME=.25
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=16
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=64
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=256
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=1024
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=4096
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=16384
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=65536
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=262144
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"

SIZE=524288
rm -f tcp_latency_$SIZE.txt
for((c=1; c<=$NUM_ITERATIONS; c++))
do
  ./server/server $SIZE $PORT &
  sleep $SLEEP_TIME
  ./client/client $SIZE $PORT >> tcp_latency_$SIZE.txt
done

echo "Finished $SIZE"
