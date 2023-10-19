#!/bin/bash

# constants
last_name="Melacarne"

# command line args
exercise_nunber=$1
exercise_name=$2

# create directory
mkdir -p "$exercise_name"

# create file
touch "$exercise_name"/es_"$exercise_nunber"_"$last_name"_"$exercise_name".cpp