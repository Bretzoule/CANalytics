#!/bin/bash

set -x

gnuplot -p -e "plot 'outputTimeStamp.txt' with  impulses lw 2 title 'Ecarts frequence envoi - Attack Free', 0.000438 title 'Moyenne envoi'"
