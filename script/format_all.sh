#/bin/bash
for file in `find . | grep -E "\.(c|h)pp$"`
do
    clang-format -style=file -i $file >& /dev/null
done