CWD="$(pwd)"
COSMOS_ROOT="$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."
COSMOS_CODE_ROOT="$COSMOS_ROOT/code"
UNCRUSTIFY_ROOT="$COSMOS_ROOT/third_party/uncrustify"
UNCRUSTIFY="$UNCRUSTIFY_ROOT/build/uncrustify"
UNCRUSTIFY_CONFIG="$UNCRUSTIFY_ROOT/../uncrustify.cfg"

total=0
error_times=0

assert()
{
    error=$?
    if [[ $# -eq 1 ]]; then
        if [ $error -ne $1 ]; then
            echo "exit ($error)"
            error_code=1
            exit 1
        fi
    else
        if [ $error -ne 0 ]; then
            echo "exit ($error)"
            error_code=1
            exit 1
        fi
    fi
}

echo """
###########################
# Building uncrustify ... #
###########################
"""
cd "$UNCRUSTIFY_ROOT"
tmp=`mktemp tmp.XXXXXXXXXX`
rm -rf build
mkdir build
cd build
cmake .. > $tmp
assert
cmake --build . > $tmp
assert
rm -f $tmp
assert

echo """
########################
# Formatting files ... #
########################
"""
cd "$COSMOS_CODE_ROOT"
for cpp_file in `find -name '*.cpp'`
do
    # remove the output file if existed to prevent `uncrustify` is not override it
    rm -f "$cpp_file.uncrustify"
    if [ $? != 0 ]; then
        echo "# Failed to remove file: \`$COSMOS_CODE_ROOT/$cpp_file\`."
    fi;

    "$UNCRUSTIFY" -q -c "$UNCRUSTIFY_CONFIG" "$COSMOS_CODE_ROOT/$cpp_file"
    if [ $? != 0 ]; then
        echo "# Failed to create uncrustify file: \`$COSMOS_CODE_ROOT/$cpp_file\`."
    fi;

    total=$(($total+1))
done

echo """
#######################
# Comparing files ... #
#######################
"""
cd "$COSMOS_CODE_ROOT"
for cpp_file in `find -name '*.cpp'`
do
    d=$(diff "$cpp_file" "$cpp_file.uncrustify")

    if [ $? != 0 ]; then
        echo "# Failed: \`$COSMOS_CODE_ROOT/$cpp_file\`"
        error_times=$(($error_times+1))
    fi;
done

cd "$CWD"

echo
if [ $error_times != 0 ]; then
    echo "Failed. $error_times/$total error(s) generated."
    exit 1
else
    echo "Passed. \`checking coding style in c++ script\` exited with 0."
fi;
