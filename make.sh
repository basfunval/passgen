#!/bin/bash
[ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"
rm passgen
gcc -o passgen passgen.c
if [ "$1" == 'install' ]
then
  cp -i passgen /bin/passgen
fi