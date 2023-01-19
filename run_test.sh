app="./build/app/app"

function test(){
    echo $1 $2 $3 $4 $5
    $1 $2 $3 $4 $5
    echo ""
}

# run test
test $app

test $app 50

test $app 10 10

test $app 20 10 10 20

test $app 20 10 10
