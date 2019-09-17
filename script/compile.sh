#/bin/bash
find|grep .cpp

for file in `find|grep .cpp`
do
    echo compiling $file
    if ! g++ -std=c++14 -c $file -o /dev/null ; then
        echo compile error on $file
        exit 1
    fi
    echo ok
done
