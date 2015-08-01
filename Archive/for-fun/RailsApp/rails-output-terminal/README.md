vmstat-rails
============

 Vmstat  reports  information  about  processes, memory, paging, block IO, traps, disks and cpu activity.
 <br/>
<code>$ vim com2</code>
<pre>
id=$(($1+0))
if [ $id -eq 2 ]
then
	echo "Enter the delay time"
	vmstat -f $id
fi
if [ $id -eq 0 ]
then
	vmstat
fi
if [ $id -eq 1 ]
then
	vmstat -f
fi
if [ $id -eq 3 ]
then 
	vmstat -s
fi;
if [ $id -eq 4 ]
then
	echo "Enter The phrase in REGEX"
	vmstat -s | grep $rg
fi;
if [ $id -eq 5 ]
then
	vmstat -s | grep "total memory"
fi;
if [ $id -eq 6 ] 
then
	vmstat -s | grep "used memory"
fi
if [ $id -eq 7 ]
then 
	vmstat -s | grep "active memory"
fi;
if [ $id -eq 8 ] 
then
	vmstat -s | grep "inactive memory"
fi;
if [ $id -eq 9 ]
then
	vmstat -s | grep "free memory"
fi
if [ $id -eq 10 ] 
then
	vmstat -s | grep "buffer memory"
fi
if [ $id -eq 11 ]
then
	vmstat -s | grep "swap cache"
fi
if [ $id -eq 12 ]
then
	vmstat -s | grep "buffer memory"
fi;
if [ $id -eq 13 ]
then
	vmstat -s | grep "used swap"
fi</pre>
<code>
<pre>
$ sudo ln -s /FULL/PATH/TO/COM2 /usr/bin/
$ cd /PATH/TO/vmstat-rails 
$ rails server
</pre></code>
