cwd=$(pwd)
cosmos_root_path="$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."

error_times=0
tmp=`mktemp tmp.XXXXXXXXXX`

uncrustify_root_path="$cosmos_root_path/third_party/uncrustify"
uncrustify="$uncrustify_root_path/build/uncrustify"
uncrustify_config_path="$uncrustify_root_path/../uncrustify.cfg"

echo
echo "###########################"
echo "# Building uncrustify ... #"
echo "###########################"
rm -rf $uncrustify_root_path/build
mkdir $uncrustify_root_path/build
cd $uncrustify_root_path/build
cmake .. > $tmp
cmake --build . > $tmp

cd "$cosmos_root_path/code"

echo
echo "###############################"
echo "# Creating files for diff ... #"
echo "###############################"
for cpp_file in `find -name '*.cpp'`
do
    # remove the output file if existed to prevent `uncrustify` is not override it
    rm -f $cpp_file.uncrustify

    $uncrustify -q -c $uncrustify_config_path $cpp_file
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

cd "$cwd"

if [ $error_times != 0 ]; then
    echo "$error_times error(s) generated."
    exit 1
else
    echo "Done. \`checking coding style in c++ script\` exited with 0."
fi;
