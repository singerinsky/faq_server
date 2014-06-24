find . -name "*.h" -o -name "*.cpp" -o -name "*.cc" > cscope.files

cscope -bkq -i cscope.files

ctags -R

