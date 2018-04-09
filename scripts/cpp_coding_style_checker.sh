CWD="$(pwd)"
COSMOS_ROOT="$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."
COSMOS_CODE_ROOT="$COSMOS_ROOT/code"
UNCRUSTIFY_ROOT="$COSMOS_ROOT/third_party/uncrustify"
UNCRUSTIFY="$UNCRUSTIFY_ROOT/build/uncrustify"
UNCRUSTIFY_CONFIG_PATH="$UNCRUSTIFY_ROOT/../uncrustify.cfg"

error_times=0

echo
echo "###########################"
echo "# Building uncrustify ... #"
echo "###########################"
cd "$UNCRUSTIFY_ROOT"
tmp=`mktemp tmp.XXXXXXXXXX`
rm -rf build
mkdir build
cd build
cmake .. > $tmp
cmake --build . > $tmp
rm -f $tmp

echo
echo "###############################"
echo "# Creating files for diff ... #"
echo "###############################"
cd "$COSMOS_CODE_ROOT"
for cpp_file in `find -name '*.cpp'`
do
    # remove the output file if existed to prevent `uncrustify` is not override it
    rm -f "$cpp_file.uncrustify"

    "$UNCRUSTIFY" -q -c "$UNCRUSTIFY_CONFIG_PATH" "$cpp_file"
done

echo
echo "##################"
echo "# Diff files ... #"
echo "##################"
cd "$COSMOS_CODE_ROOT"
for cpp_file in `find -name '*.cpp'`
do
    d=$(diff "$cpp_file" "$cpp_file.uncrustify")

    if [ "$d" != "" ]; then
        echo "# The \`$cpp_file\` is not passed"
        error_times=$(($error_times+1))
    fi;
done

cd "$CWD"

if [ $error_times != 0 ]; then
    echo "$error_times error(s) generated."
    exit 1
else
    echo "Done. \`checking coding style in c++ script\` exited with 0."
fi;
