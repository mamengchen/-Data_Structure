#!/bin/bash
a=$1
b=$2
echo "$a-$b=$(($a-$b))"

#!/bin/sh
str="I am oldboy linux welcome to our training"
for n in $str
do
if [ `expr length $n` -lt 6 ]
then
echo $n
fi
done

#!/bin/sh

expr $1 + "mmc" > /dev/null 2>&1

[ $? == 0  ] && echo int || echo chars


#!/bin/sh
if expr "$1" : ".*\.txt" >/dev/null
then
echo "this is txt"
else
echo "this is not txt"
fi

#!/bin/sh
if [ `expr "$1" : "[0-9]*$"` == 0 ]
then
echo "is not num"
else
echo "is num"
fi
