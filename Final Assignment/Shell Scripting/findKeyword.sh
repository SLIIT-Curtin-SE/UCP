#we only allow one argument to be passed since it wasn't mentioned that we can pass two.
if [ $# -eq 1 ]; then
    grep -rhw $1 data > output.txt #r for recursive, w for only whole words, h for only the string, > to direct the return values into a file
else
    echo "Provide 1 argument"
fi