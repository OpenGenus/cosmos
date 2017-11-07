# Compile and link tests file that passed by parameters
# the output file will named sample.cpp -> sample.cpp.o

sh_dir=$(dirname "$0")

for file in "$@"
do
    `g++-7 $sh_dir"/test_main.cpp.o" "$file" -o "$file.o" -Wall`
done
