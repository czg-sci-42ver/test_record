# https://ro-che.info/articles/2020-01-11-gdb-break-on-nan
set record full stop-at-limit off
set record full memory-query on
set record full insn-number-max 2000000000
br float-half.c:9
next
d br 1
tbr 49
c
tbr 9
rc
tbr 13
c

# tbr 13
# c
source ./print_1.gdb