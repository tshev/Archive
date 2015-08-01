cat access_log | cut -d ' ' -f1 | uniq -c | sort -g | tail -n 10

