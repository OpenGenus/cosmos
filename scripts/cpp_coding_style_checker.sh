CWD=$(pwd)
COSMOS_ROOT_PATH="$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."

error_times=0
tmp=`mktemp tmp.XXXXXXXXXX`

UNCRUSTIFY_ROOT_PATH="$COSMOS_ROOT_PATH/third_party/uncrustify"
UNCRUSTIFY="$UNCRUSTIFY_ROOT_PATH/build/uncrustify"
UNCRUSTIFY_CONFIG_PATH="$UNCRUSTIFY_ROOT_PATH/../uncrustify.cfg"

echo
echo "###########################"
echo "# Building uncrustify ... #"
echo "###########################"
rm -rf $UNCRUSTIFY_ROOT_PATH/build
mkdir $UNCRUSTIFY_ROOT_PATH/build
cd $UNCRUSTIFY_ROOT_PATH/build
cmake .. > $tmp
cmake --build . > $tmp

cd "$COSMOS_ROOT_PATH/code"

echo
echo "###############################"
echo "# Creating files for diff ... #"
echo "###############################"
for cpp_file in `find -name '*.cpp'`
do
    # remove the output file if existed to prevent `uncrustify` is not override it
    rm -f $cpp_file.uncrustify

    $UNCRUSTIFY -q -c $UNCRUSTIFY_CONFIG_PATH $cpp_file
done

echo
echo "##################"
echo "# Diff files ... #"
echo "##################"
for cpp_file in `find -name '*.cpp'`
do
    d=$(diff $cpp_file $cpp_file.uncrustify)

    if [ "$d" != "" ]; then
        echo "# The \`$cpp_file\` is not passed"
        # echo
        # echo "diff $cpp_file $cpp_file.uncrustify"
        # echo
        # echo "$d"
        # echo
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
