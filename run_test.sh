app="./build/out/bin/app"

function test(){
    echo $1 $2 $3 $4 $5
    $1 $2 $3 $4 $5
    echo ""
}

# run test
test $app 100 1