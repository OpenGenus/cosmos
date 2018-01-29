cwd=$(pwd)

make -f generate_dependencies.make
make -f testing.make

cd scripts
./cpp_coding_style_checker.sh || exit 1
cd $cwd
