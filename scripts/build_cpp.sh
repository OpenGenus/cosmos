cwd=$(pwd)
cosmos_root_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."

cd "$cosmos_root_path"
echo ""
echo "###############################"
echo "# generating dependencies ... #"
echo "###############################"
make -f generate_dependencies.make || exit 1

echo ""
echo "#########################"
echo "# compiling sources ... #"
echo "#########################"
make -f testing.make || exit 1

cd "$cosmos_root_path/scripts"
echo ""
echo "#############################"
echo "# checking coding style ... #"
echo "#############################"
./cpp_coding_style_checker.sh || exit 1

cd $cwd
