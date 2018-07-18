#!/bin/bash

directories="linux MacOS windows"
pass=0
fail=0

function prepare_venv() {
    VIRTUALENV=$(which venv)
    if [ $? -eq 1 ]; then
        
        VIRTUALENV=$(which venv-3)
    fi

    ${VIRTUALENV} python3 -m venv mybenjienv && source mybenjienv/bin/activate && python3 "$(which pip3)" install pycodestyle
}


echo "----------------------------------------------------"
echo "Running Python Linter against following directories:"
echo "$directories"
echo "----------------------------------------------------"
echo

[ "$NOVENV" == "1" ] || prepare_venv || exit 1

# checks for the whole directories
for directory in $directories
do
    files=$(find "$directory" -path "$directory/venv" -prune -o -name '*.py' -print)

    for source in $files
    do
        echo "$source"
        pycodestyle "$source"
        if [ $? -eq 0 ]
        then
            echo "    Pass"
            let "pass++"
        else
            echo "    Fail"
            let "fail++"
        fi
    done
done

$(deactivate && rm -rf mybenjienv/)

if [ $fail -eq 0 ]
then
    echo "All checks passed for $pass source files"
else
    let total=$pass+$fail
    echo "Linter fail, $fail source files out of $total source files need to be fixed"
    exit 1
fi
