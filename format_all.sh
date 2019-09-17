for file in `find|grep .cpp`
do
    clang-format -i $file >& /dev/null
done