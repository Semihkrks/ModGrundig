#!/bin/sh

MNT_POINT=/dev/$1
MNT_PATH=/usb/$1
NTY_PATH=/tmp/mount.notifier

#echo "start automount.sh" > /root/auto.log

if [ "$1" == "" ]; then
    echo "automount.sh parameter is none"
    exit 1
fi

#echo "start $1" >> /root/auto.log
CHECK_TAG=`echo ${#MNT_POINT}`
#echo "$1 check tag = $CHECK_TAG" >> /root/auto.log
# sdx case
if [ "$CHECK_TAG" -lt "9" ]; then
    MNT_TAG=`mount | grep $MNT_PATH`
    #echo "MNT_TAG=$MNT_TAG" >> /root/auto.log
    if [ "$MNT_TAG" = "" ]; then
        #mount sdx
        mkdir -p $MNT_PATH
        mount $MNT_POINT $MNT_PATH
        #check usb fstype and remount again
        MNT_TAG=`mount | grep $MNT_PATH | cut -d' ' -f5`
        umount $MNT_PATH
        if [ "$MNT_TAG" = "vfat" ]; then
            mount -t $MNT_TAG -o iocharset=utf8,shortname=winnt $MNT_POINT $MNT_PATH
        elif [ "$MNT_TAG" = "ntfs" ]; then
            mount -t $MNT_TAG -o nls=utf8 $MNT_POINT $MNT_PATH
        fi
        #echo "mount $MNT_PATH" >> /root/auto.log
        # if sdx mount ok, don't mount sdx1
        MNT_TAG=`mount | grep $MNT_PATH`
        #echo "check sdx mount : MNT_TAG=$MNT_TAG" >> /root/auto.log
        if [ "$MNT_TAG" = "" ]; then
            #mount sdx1
            MNT_POINT="$MNT_POINT"1
            
            #check if sdx1 mount already
            MNT_TAG=`mount | grep $MNT_POINT`
            if [ "$MNT_TAG" = "" ]; then
                #MNT_PATH="$MNT_PATH"1
                mkdir -p $MNT_PATH
                mount $MNT_POINT $MNT_PATH
                #check usb fstype and remount again
                MNT_TAG=`mount | grep $MNT_PATH | cut -d' ' -f5`
                umount $MNT_PATH
                if [ "$MNT_TAG" = "vfat" ]; then
                    mount -t $MNT_TAG -o iocharset=utf8,shortname=winnt $MNT_POINT $MNT_PATH
                elif [ "$MNT_TAG" = "ntfs" ]; then
                    mount -t $MNT_TAG -o nls=utf8 $MNT_POINT $MNT_PATH
                fi
                #echo "mount $MNT_PATH" >> /root/auto.log
            fi
        fi

        #FIXME blkid is too slow
        BLKID_STR=""        #`blkid -l | grep $1`
        VOL_NAME="WaHa"     #`echo $BLKID_STR | cut -d'"' -f2`
        VOL_UUID="WaHa-001" #`echo $BLKID_STR | cut -d'"' -f4`
        MNT_INFO=`mount | grep $MNT_PATH`
        NODE_PATH=`echo $MNT_INFO | cut -d' ' -f1`
        FS_TYPE=`echo $MNT_INFO | cut -d' ' -f5`
        #echo "m \"$VOL_NAME\" $VOL_UUID $NODE_PATH $MNT_PATH $FS_TYPE"   >> /root/auto.log
    
        for NTY in `ls $NTY_PATH`
        do
            echo "m \"$VOL_NAME\" $VOL_UUID $NODE_PATH $MNT_PATH $FS_TYPE" > $NTY_PATH/$NTY
        done
    else 
        #umount sdx and sdxx
        #echo "u $MNT_PATH" >> /root/auto.log
        umount -l $MNT_PATH
        rm -rf $MNT_PATH
    
        #MNT_POINT="$MNT_POINT"1
        #MNT_PATH="$MNT_PATH"1
        #umount -l $MNT_PATH
        #rm -rf $MNT_PATH
        
        for NTY in `ls $NTY_PATH`
        do
            echo "u $MNT_PATH" > $NTY_PATH/$NTY
        done
    
        #echo "unmount $MNT_PATH" >> /root/auto.log
    fi
# sdxx case
else
    MNT_TAG=`mount | grep $MNT_PATH`
    if [ "$MNT_TAG" = "" ]; then
        #mount sdxx
        mkdir -p $MNT_PATH
        mount $MNT_POINT $MNT_PATH
        #check usb fstype and remount again
        MNT_TAG=`mount | grep $MNT_PATH | cut -d' ' -f5`
        umount $MNT_PATH
        if [ "$MNT_TAG" = "vfat" ]; then
            mount -t $MNT_TAG -o iocharset=utf8,shortname=winnt $MNT_POINT $MNT_PATH
        elif [ "$MNT_TAG" = "ntfs" ]; then
            mount -t $MNT_TAG -o nls=utf8 $MNT_POINT $MNT_PATH
        fi
        #echo "mount $MNT_PATH" >> /root/auto.log
        #FIXME blkid is too slow
        BLKID_STR=""        #`blkid -l | grep $1`
        VOL_NAME="WaHa"     #`echo $BLKID_STR | cut -d'"' -f2`
        VOL_UUID="WaHa-001" #`echo $BLKID_STR | cut -d'"' -f4`
        MNT_INFO=`mount | grep $MNT_PATH`
        NODE_PATH=`echo $MNT_INFO | cut -d' ' -f1`
        FS_TYPE=`echo $MNT_INFO | cut -d' ' -f5`
        #echo "m \"$VOL_NAME\" $VOL_UUID $NODE_PATH $MNT_PATH $FS_TYPE"   >> /root/auto.log
    
        for NTY in `ls $NTY_PATH`
        do
            echo "m \"$VOL_NAME\" $VOL_UUID $NODE_PATH $MNT_PATH $FS_TYPE" > $NTY_PATH/$NTY
        done
    else 
        #umount sdxx
        #echo "u $MNT_PATH" >> /root/auto.log
        umount -l $MNT_PATH
        rm -rf $MNT_PATH
                
        for NTY in `ls $NTY_PATH`
        do
            echo "u $MNT_PATH" > $NTY_PATH/$NTY
        done
        
        #echo "unmount $MNT_PATH" >> /root/auto.log
    fi
fi
#echo "end automount.sh" >> /root/auto.log
exit 0

