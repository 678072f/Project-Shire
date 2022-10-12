#! /bin/bash

# Universal Variables
REMOTE_ADDRESS="duhonrpi2.ddns.net"
USERNAME="pi"
SCP=$(which scp)
SSH=$(which ssh)

# Input variables
PROJECT=$1
FILES=()
shift 1
for i in $@; do
    FILES+=( $i );
done

# Check PROJECT Input
if [[ $PROJECT == "Shire" || $PROJECT == "shire" ]];
then
    PATH="~/Project-Shire/experimental/source/"
elif [[ $PROJECT == "Auto-Garden" || $PROJECT == "auto-garden" ]];
then
    PATH="/var/www/domains/duhonrpi2.tld/"
else
    echo "Error! Usage: upload [PROJECT] [INPUT FILE] | [PROJECT = shire || auto-garden]"
    exit 1
fi


for j in ${FILES[@]}; do
    $SCP $j $USERNAME@$REMOTE_ADDRESS:$PATH
done

echo "cd $PATH && ls" | $SSH $USERNAME@$REMOTE_ADDRESS
# echo "/home/pi/Project-Shire/experimental/bin/shire_d && -1" | $SSH $USERNAME@$REMOTE_ADDRESS
