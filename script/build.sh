for file in `find|grep .cpp`
do
    if g++ -c $file >& /dev/null; then
        echo build error on $file
        exit 1
    fi
done
echo ok