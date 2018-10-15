for full_path_file in `find 'input' -name '*.cpp'`
do
    # format file
    uncrustify -c ../../../../third_party/uncrustify.cfg $full_path_file

    # compare file
    input_file=$full_path_file'.uncrustify'
    output_file='output/'`basename $full_path_file`
    diff $input_file $output_file
done
