#!/bin/bash

infile=infile
outfile=outfile

# echo "grep "physical id" /proc/cpuinfo | sort | uniq | wc -l"
# grep "physical id" /proc/cpuinfo | sort | uniq | wc -l
# echo 
# ./pipex $infile "grep \"physical id\" \"/proc/cpuinfo\"" "sort" "uniq" "wc -l" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "grep "^processor" /proc/cpuinfo | wc -l"
# grep "^processor" /proc/cpuinfo | wc -l
# echo 
# ./pipex $infile "grep \"^processor\" \"/proc/cpuinfo\"" "wc -l" outfile
# cat $outfile
# echo
# echo "====================================================================="

./pipex $infile "ls -l" "wc -l" outfile
cat $outfile

# echo "free -m | awk '\$1 == \"Mem:\" {print \$2}'"
# free -m | awk '$1 == "Mem:" {print $2}'
# echo 
# ./pipex $infile "free -m" "awk '\$1 == \"Mem:\" {print \$2}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "free -m | awk '\$1 == \"Mem:\" {print \$3}'"
# free -m | awk '$1 == "Mem:" {print $3}'
# echo 
# ./pipex $infile "free -m" "awk '\$1 == \"Mem:\" {print \$3}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "free | awk '\$1 == \"Mem:\" {printf("%.2f"), \$3/\$2*100}'" 
# free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}'
# echo 
# ./pipex $infile "free" "awk '\$1 == \"Mem:\" {printf(\"%.2f\"), \$3/\$2*100}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += \$2} END {print ft}'"
# df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}'
# echo 
# ./pipex $infile "df -Bg" "grep '^/dev/'" "grep -v '/boot$'" "awk '{ft += \$2} END {print ft}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += \$3} END {print ut}'"
# df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}'
# echo 
# ./pipex $infile "df -Bm" "grep '^/dev/'" "grep -v '/boot$'" "awk '{ut += \$3} END {print ut}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += \$3} {ft+= \$2} END {printf("%d"), ut/ft*100}'"
# df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}'
# echo 
# ./pipex $infile "df -Bm" "grep '^/dev/'" "grep -v '/boot$'" "awk '{ut += \$3} {ft+= \$2} END {printf(\"%d\"), ut/ft*100}" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), \$1 + \$3}'"
# top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}'
# echo 
# ./pipex $infile "top -bn1" "grep '^%Cpu'" "cut -c 9-" "xargs" "awk '{printf(\"%.1f%%\"), \$1 + \$3}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "who -b | awk '\$1 == "system" {print \$3 " " \$4}'"
# who -b | awk '$1 == "system" {print $3 " " $4}'
# echo 
# ./pipex $infile "who -b" "awk '\$1 == \"system\" {print \$3 \" \" \$4}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "lsblk | grep "lvm" | wc -l"
# lsblk | grep "lvm" | wc -l
# echo 
# ./pipex $infile "lsblk" "grep \"lvm\"" "wc -l" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "cat /proc/net/sockstat{,6} | awk '\$1 == "TCP:" {print \$3}'"
# cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}'
# echo 
# ./pipex $infile "cat /proc/net/sockstat" "awk '\$1 == \"TCP:\" {print \$3}'" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "users | ls -l"
# users | ls -l
# echo 
# ./pipex $infile "users" "ls -l" outfile
# cat outfile
# echo
# echo "====================================================================="

# echo "ip link show | awk '\$1 == "link/ether" {print \$2}'"
# ip link show | awk '$1 == "link/ether" {print $2}'
# echo 
# ./pipex $infile "ip link show" "awk '\$1 == \"link/ether\" {print \$2}'" outfile
# cat outfile
# echo
# echo "====================================================================="
