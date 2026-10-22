rm -rf /dev/shm/dev
mkdir -p /dev/shm/dev

tmp=`cat /sys/class/ubi/ubi2/dev | sed 's/:/ /'`
mknod /dev/shm/dev/ubi2 c ${tmp}

tmp=`cat /sys/class/ubi/ubi2_0/dev | sed 's/:/ /'`
mknod /dev/shm/dev/ubi2_0 c ${tmp}

# BEKO_G9_BRINGUP Start
mknod /dev/shm/boot c 283 0

PART_MAX=10
VOL_MAX=10
PART_IDX=0
VOL_IDX=0

while test -e /sys/class/ubi/ubi${PART_IDX}_${VOL_IDX}/dev
do
    if test -e /sys/class/ubi/ubi${PART_IDX}/dev
    then
        #echo ubi${PART_IDX}
        tmp=`cat /sys/class/ubi/ubi${PART_IDX}/dev | sed 's/:/ /'`
        mknod /dev/shm/ubi${PART_IDX} c ${tmp}
    fi
    while test -e /sys/class/ubi/ubi${PART_IDX}_${VOL_IDX}/dev
    do
        #echo ubi${PART_IDX}_${VOL_IDX}
        tmp=`cat /sys/class/ubi/ubi${PART_IDX}_${VOL_IDX}/dev | sed 's/:/ /'`
        mknod /dev/shm/ubi${PART_IDX}_${VOL_IDX} c ${tmp}
        VOL_IDX=$(($VOL_IDX+1))
    done
    PART_IDX=$(($PART_IDX+1))
    VOL_IDX=0
done
# BEKO_G9_BRINGUP End

