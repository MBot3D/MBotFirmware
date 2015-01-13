#!/bin/bash

#cd $( dirname $( readlink -f "${BASH_SOURCE[0]}" ))

while true; do

FAIL8U2="8U2 Bootloader PASS"
FAIL2560="2560 Bootloader PASS"
FAILUSB="USB Program PASS"


   echo "Press Enter upload 2560 firmware"
    read

    # Upload bootloader and motor test via isp
    avrdude -p m2560 -D -P com4 -c stk500v2 -b 115200 -U flash:w:mbot_grid2plus_wpy.hex:i

    if [ $? -ne 0 ]
     then
      FAIL2560="2560 Bootloader FAIL"
    # else
    #  sleep 10
    fi
 
   # Upload firmware via usb
   #avrdude -p m2560 -P usb -c avrispmkii
   #avrdude -F -V -p m2560 -P usb -c avrispmkii -b 57600 -U flash:w:Mighty-mb40-v5.5.hex

   if [ $? -ne 0 ]
    then
       FAILUSB="USB Program FAIL"
    fi

	echo $FAIL8U2
	echo $FAIL2560
	echo $FAILUSB
done

#!/bin/bash



