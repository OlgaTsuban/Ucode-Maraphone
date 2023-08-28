#!/bin/sh
for user in "$@"
do
  if [ -f "$user"]; then
      rm $user
  fi
  if [ -d "$user"]; then
      rmdir $user
  fi
done
