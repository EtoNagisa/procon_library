#/bin/bash
ls -la
find|grep .cpp

for file in `find|grep .cpp`
do
    g++ -std=c++14 -c $file -o /dev/null
    if [  $? != 0 ] ; then
        echo build error on $file
        exit 1
    fi
done
echo ok