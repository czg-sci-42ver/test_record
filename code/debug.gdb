# https://ro-che.info/articles/2020-01-11-gdb-break-on-nan
set record full stop-at-limit off
set record full memory-query on
set record full insn-number-max 2000000000
# set debug infrun 1
# set debug lin-lwp 1
# set debug record 1
tbr float-half.c:13
br float-half.c:9
r
record full
d br 2
c
# tbr 9
info record
tbr 49
c
tbr 9
info record 
rc
tbr 13
c
info record
source ./print_1.gdb

# reverse-continue
# until 13
# source ./print_1.gdb