awk '{ for (i = 1; i <= NF; i++) column[i] = (NR == 1 ? $i : column[i] " " $i); count = NF } END { for (i = 1; i <= count; i++) print column[i] }' file.txt
