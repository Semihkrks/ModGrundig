
#echo "Mounting OAD"
mount -t ubifs ubi:oad /OAD

#echo "Mounting certificate"
mount -t ubifs  -o ro ubi1:certificate /certificate

#echo "Mounting Customer ini"
# BEKO_G9_BRINGUP Start
# skip because it will be execited in etc/init.d/rcS
#mount -t  ubifs ubi:customer_update /Customer_Update
# BEKO_G9_BRINGUP End

#echo "Mounting BACKUP_DB"
mount -t ubifs ubi:BACKUP_DB /BACKUP_DB
