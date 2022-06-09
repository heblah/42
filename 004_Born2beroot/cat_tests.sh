#!/bin/bash
LOGIN="halvarez"

cat << EOF > $LOGIN"42_autoconf"
 Defaults     passwd_tries=3
 Defaults     badpass_message="Wrong password. Try again!"
 Defaults     logfile="/var/log/sudo/sudo.log"
 Defaults     log_input
 Defaults     log_output
 Defaults     requiretty
EOF
