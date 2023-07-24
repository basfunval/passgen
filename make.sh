#!/bin/bash
[ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"
rm passgen
gcc -o passgen passgen.c
cp -f passgen /bin/passgen
