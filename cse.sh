#!/bin/bash

printf "Press 0 to search for Station:\n%s";
printf "Press 1 to search for Air Quality:\n%s";
printf "Press 2 to search for O3 Value:\n%s";
printf "Press 3 to search for NO2 Value:\n%s";
printf "Press 4 to search for PM10 Value:\n%s";

read choice;
echo "$choice";


if [ $choice -eq 0 ]
then
printf "please enter Station (e.g: Sants) name to search:\n%s"; read pattern; awk -v patt="$pattern" -F',' '$1 ~ patt' air_quality_Nov2017.csv
fi


if [ "$choice" -eq 1 ];
then
printf "please enter Air Quality (e.g: Good) to search: "; read pattern; awk -v patt="$pattern" -F',' '$2 ~ patt' air_quality_Nov2017.csv
fi


if [ $choice -eq 2 ]
then
printf "please enter O3 Value(e.g:1) to search:\n%s"; read pattern; awk -v patt="$pattern" -F',' '$7 == patt' air_quality_Nov2017.csv
fi


if [ $choice -eq 3]
then
printf "please enter NO2 Value(e.g:3) to search:\n%s"; read pattern; awk -v patt="$pattern" -F',' '$10 == patt' air_quality_Nov2017.csv
fi


if [ $choice -eq 4]
then
printf "please enter PM10 Value(e.g:30) to search:\n%s"; read pattern; awk -v patt="$pattern" -F',' '$13 == patt' air_quality_Nov2017.csv
fi