# What is this?
#     auto convert files' name
#
#     e.g.,
#     1)
#         dir="aaa/bbb/ccc/ddd.cpp"
#         convert:
#             ddd.cpp => DDD.cpp
#             ddd.cpp => Ddd.cpp
#
#     2)
#         dir="multi/path/sort/bubble_sort/BuBble-_-sort.cpp"
#         convert:
#             BuBble-_-sort.cpp => bubble_sort.cpp (using directory name)
#             BuBble-_-sort.cpp => Bubble_Sort.cpp
#             BuBble-_-sort.cpp => BubbleSort.cpp
#             BuBble-_-sort.cpp => Bubble-Sort.cpp
#             ,etc.
#
# How to use?
#     1. copy this script to where your directory contains files
#     2. exec

YELLOW='\033[1;33m'
NC='\033[0m'
echo "\n${YELLOW}-  Warnning: if target-file-name is exist, will be override  !!!  ${NC}-\n"

# define
use_directory_name=0
use_type_name=1

use_default_case=0
use_lower_case=1
use_upper_case=2
use_ignore_case=3

use_default_line=0
use_under_line=1
use_dash_line=2
use_ignore_line=3

re='^[0-1]+$'
echo "Please type your choice to convert files' name ( without '.' and 'extension' )"
echo "0) Use directory name"
echo "1) Use type name"
while [ 1 ]
do
	read choice
	if [[ $choice =~ $re ]]; then
		break
	fi
	echo "wrong input"
done
if [ $choice -eq $use_type_name ]; then
	read name
else
	name="${PWD##*/}"
fi

re='^[0-3]+$'
echo "Please type your choice to convert (alpha)"
echo "0) Use default"
echo "1) Convert upper case to lower case (default)"
echo "2) Convert lower case to upper case"
echo "3) Not convert"
while [ 1 ]
do
	read alpha_choice
	if [[ $alpha_choice =~ $re ]]; then
		break
	fi
	echo "Wrong input"
done
if [ $alpha_choice -eq $use_default_case ]|| [ $alpha_choice -eq $use_lower_case ]; then
	name=`echo $name | tr [:upper:] [:lower:]`
elif [ $alpha_choice -eq $use_upper_case ]; then
	name=`echo $name | tr [:lower:] [:upper:]`
fi

re='^[0-3]+$'
echo "Please type your choice to convert ('-' and '_')"
echo "0) Use default"
echo "1) Convert '-' and '_' to '_' (default)"
echo "2) Convert '-' and '_' to '-'"
echo "3) Not convert"
while [ 1 ]
do
	read line_choice
	if [[ $line_choice =~ $re ]]; then
		break
	fi
	echo "Wrong input"
done
if [ $line_choice -eq $use_default_line ]||[ $line_choice -eq $use_under_line ]; then
	name=`echo $name | tr - _`
elif [ $line_choice -eq $use_dash_line ]; then
	name=`echo $name | tr _ -`
fi


# backup
date="backup_`date`"
`mkdir "$date"`
`cp *.* "$date"`


# match
for full_file_name in *.c *.cs *.cpp *.elm *.exs *.f *.go *.hs *.java *.jl *.js *.kt *.m *.php *.py *.rb *.rs *.sh *.swift *.ts
do
	temp=(${full_file_name//\./ })
	# check 1: escape file if has multi-layer extension
    # check 2: escape if directory not has current extension file
	if [ ${#temp[@]} -ge 3 ]||[[ ${temp[0]} == '*' ]]; then
		continue
	fi

	file_name=${temp[0]}
	file_ext=${temp[1]}

	# convert file name with pattern
	converted_file_name=$file_name
	if [ $alpha_choice -eq $use_default_case ]||[ $alpha_choice -eq $use_lower_case ]; then
		converted_file_name=`echo $converted_file_name | tr [:upper:] [:lower:]`
	elif [ $alpha_choice -eq $use_upper_case ]; then
		converted_file_name=`echo $converted_file_name | tr [:lower:] [:upper:]`
	fi

	if [ $line_choice -eq $use_default_line ]||[ $line_choice -eq $use_under_line ]; then
		converted_file_name=`echo $converted_file_name | tr - _`
	elif [ $line_choice -eq $use_dash_line ]; then
		converted_file_name=`echo $converted_file_name | tr _ -`
	fi

	# convert file
	converted_file_name="$converted_file_name.$file_ext"
	converted_target_file_name="$name.$file_ext"

	# ignore line
	converted_file_name=${converted_file_name//-}
	converted_file_name=${converted_file_name//_}
	converted_target_file_name=${converted_target_file_name//-}
	converted_target_file_name=${converted_target_file_name//_}

	if [[ ^$converted_file_name$ == ^$converted_target_file_name$ ]]; then
		`git mv --force $full_file_name $name.$file_ext`
	fi
done
