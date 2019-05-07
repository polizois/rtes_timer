#!/bin/sh

file1="withoutCompensation"
file2="withCompensation"

dur="7200" # Define Sampling Duration (in seconds)
step="0.1" # Define Sampling Step (in seconds)

func()
{
  echo "STARTING Timer ${1%Compensation} compensation"
	mkdir -p results
  ./$1 $dur $step > results/$1'_'$dur'_'$step'_'$(date +"%d-%m-%y_%H.%M.%S").txt
  echo "Timer ${1%Compensation} compensation just FINISHED"
}

func $file1 &
func $file2
