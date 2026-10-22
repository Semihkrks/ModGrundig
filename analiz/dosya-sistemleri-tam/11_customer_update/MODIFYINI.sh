#!/bin/sh
	cd /Customer/
	[ -e /dev/shm/panelparaname ] && rm /dev/shm/panelparaname
	[ -e /dev/shm/panelparanum ] && rm /dev/shm/panelparanum
	modelstyle=`cat /config/sys.ini | grep -i gModelName`
	modelstyle=${modelstyle##*=\"}
	modelstyle=${modelstyle%\"*}
	#echo $modelstyle
	panelname=`cat $modelstyle | grep -i m_pPanelName`
	panelname=${panelname##*= \"}
	panelname=${panelname##*= }
	panelname=${panelname%\"*}
	#echo $panelname
	cat $modelstyle | grep -i TunnerSelectNo > temppanelparalist	
	grep -i m_ $panelname >> temppanelparalist
	cat temppanelparalist | while read line
	do
	line=${line%%;*}
	paraname=${line%%=*}
	paraname=${paraname%% *}
	paranum=${line##* }
	echo $paraname >> /dev/shm/panelparaname
	echo $paranum >> /dev/shm/panelparanum
	done
	rm temppanelparalist