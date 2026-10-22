#!/bin/sh

BACKUP_RESTORE_FILE(){
	ORIGINAL_FILE=$1
	BACKUP_FILE=$2
	FILE_SIZE=$(stat -c%s "$ORIGINAL_FILE")
	TMP_FILE=/config/tmp_file.ini
	#echo "<#> $ORIGINAL_FILE <#> $BACKUP_FILE <#> $FILE_SIZE <#> $TMP_FILE"

	if [ ! -f "$ORIGINAL_FILE" ] || [ "$FILE_SIZE" -lt 500 ]
	then
		echo "<#> Restore $ORIGINAL_FILE"
		mount -o remount,rw /config/
		cp -rf $BACKUP_FILE $TMP_FILE && mv $TMP_FILE $ORIGINAL_FILE
		mount -o remount,ro /config/
	else
		MD5_ORIGINAL=`md5sum $ORIGINAL_FILE | cut -d" " -f1`
		MD5_BACKUP=`md5sum $BACKUP_FILE | cut -d" " -f1`
		#echo "md5 <#> $MD5_ORIGINAL $MD5_BACKUP"
		if [ -f $BACKUP_FILE ] && [ $MD5_ORIGINAL == $MD5_BACKUP ]
		then
			echo "<#> No need to backup $ORIGINAL_FILE"
		else
			echo "<#> Backup $ORIGINAL_FILE"
			mount -o remount,rw /config/
			cp -rf $ORIGINAL_FILE $TMP_FILE && mv $TMP_FILE $BACKUP_FILE
			mount -o remount,ro /config/
		fi
	fi
}

BACKUP_RESTORE_FILE /config/dfbrc.ini /config/dfbrc.ini.bk
BACKUP_RESTORE_FILE /config/model/Customer_1.ini /config/model/Customer_1.ini.bk
