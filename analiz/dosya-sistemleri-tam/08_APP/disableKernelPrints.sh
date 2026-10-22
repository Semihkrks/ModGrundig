#!/bin/sh

#GokayK | 06.02.2017: Added for disable kernel prints, You can use this script if kernel prints bother you while debuging.
echo 0 > /proc/sys/kernel/printk
