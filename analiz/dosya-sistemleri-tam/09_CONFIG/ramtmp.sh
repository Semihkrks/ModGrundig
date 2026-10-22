mkdir /dev/shm/tmp
chmod 1777 /dev/shm/tmp
mount --bind /dev/shm/tmp /tmp


mkdir /dev/shm/run
chmod 1777 /dev/shm/run
mount --bind /dev/shm/run /var/run
