cwd=$(pwd)
cosmos_root_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."

cd "$cosmos_root_path"
echo "###############################\n\
    \r# generating dependencies ... #\n\
    \r###############################"
make -f generate_dependencies.make
echo "########################\n\
    \r# compiling sources ... #\n\
    \r########################"
make -f testing.make

cd "$cosmos_root_path/scripts"
echo "#############################\n\
    \r# checking coding style ... #\n\
    \r#############################"
./cpp_coding_style_checker.sh || exit 1

cd $cwd
