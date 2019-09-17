#/bin/bash
for file in `find|grep .cpp`
do
    if g++ -std=c++14 -c $file; then
        echo build error on $file
        exit 1
    fi
done
echo ok