#echo $0 start
echo 524288  > /proc/sys/net/core/rmem_default
echo 524288  > /proc/sys/net/core/rmem_max
#echo $0 end
