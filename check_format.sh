#/bin/bash
TEMPORARY_FILE_NAME="a"
while ls $TEMPORARY_FILE_NAME >& /dev/null
do
    TEMPORARY_FILE_NAME=$TEMPORARY_FILE_NAME"a"
done

for file in `find|grep .cpp`
do
    clang-format $file > $TEMPORARY_FILE_NAME >& /dev/null
    if ! diff $file $TEMPORARY_FILE_NAME >& /dev/null; then
        exit 1
    fi
done

rm $TEMPORARY_FILE_NAME