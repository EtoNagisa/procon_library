#/bin/bash
for file in `find|grep .cpp`
do
    clang-format -style=file -i $file >& /dev/null
done