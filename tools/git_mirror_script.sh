#!/bin/sh

MINUTE="< Minutes between two updates >"
PULL="< Repository pull from >"
PUSH="< Repository push to >"

while :
do
    git pull $PULL --force
    git push $PUSH --force
    TIME_OLD=`date +%M`
    TIME_NEW=`date +%M`
    TIME=$(($TIME_NEW - $TIME_OLD ))
    
    while [[ "$TIME" -ne "$MINUTE" ]]
    do
        TIME_NEW=`date +%M`
        TIME=$(($TIME_NEW - $TIME_OLD ))

    done
done
