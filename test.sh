#!/bin/bash
echo -e "\033[32;1m"libftTester"\033[m"
read $a
git clone https://github.com/Tripouille/libftTester.git
cd libftTester/
make a
cd ..
rm -rf Libftest/ libft-war-machine/ libft-unit-test/ libftTester/
echo -e "\033[32;1m"make fclean"\033[m"
read $a
make
make fclean
ls
echo -e "\033[32;1m"make clean"\033[m"
read $a
make
make fclean
# bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"
# ~/francinette/tester.sh
# rm -rf ~/francinette
