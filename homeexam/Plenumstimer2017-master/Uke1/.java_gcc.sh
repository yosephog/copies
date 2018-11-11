javac () {
    outfile=$(echo $1 | sed -e 's/.java/.class/g')
    gcc -x c -o $outfile $@
}

function java {
    execfile=$1".class"
    ./$execfile
}
