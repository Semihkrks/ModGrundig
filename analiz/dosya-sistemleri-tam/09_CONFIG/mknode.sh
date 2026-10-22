#echo "$0 start"
mkdir -p /dev/shm/dev
cd /dev/shm/dev
mknod binder c `cat /sys/devices/virtual/misc/binder/dev | sed 's/:/ /g'`
mknod ashmem c `cat /sys/devices/virtual/misc/ashmem/dev | sed 's/:/ /g'`
#echo "$0 end"
