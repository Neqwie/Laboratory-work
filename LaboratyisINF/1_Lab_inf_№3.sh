#!/bin/bash

function func { # реализую функцию для генерации паролей из симоволов 0-9
    s=""
    for (( i = 0; i < $1; i++ ))
        do 
            s+=$(( $RANDOM % 10 )) #использую $RANDOM для для генерации пароля посимвольно
    done
    echo $s
}

echo "Enter count your passwords:"
read n

for (( i = 0; i < $n; i++ ))
    do
        echo "Enter len your password"
        read ai_len
        result=$(func $ai_len)
        echo "Your random password is done"
        echo $result
done
