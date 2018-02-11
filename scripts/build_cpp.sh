cwd=$(pwd)
cosmos_root_path="$(cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )/.."

cd "$cosmos_root_path"
make -f generate_dependencies.make
make -f testing.make

cd "$cosmos_root_path/scripts"
./cpp_coding_style_checker.sh || exit 1

cd $cwd
