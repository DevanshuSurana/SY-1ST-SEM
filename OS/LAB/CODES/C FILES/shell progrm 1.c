echo "Enter two numbers." read a ; read b
echo "Please enter your choice" echo "1.Addition"
echo "2.Subtraction"
echo "3.Multiplication"
echo "4.Division"
read r
case "$r" in
1) echo "The sum of is: `echo $a+$b|bc`";;
2) echo "The difference is: `echo $a-$b|bc`";; 3) echo "The product is: `echo $a\*$b|bc`";;
4) echo "The quotient is: `echo $a/$b|bc`";; *) echo "Invalid option !!";;
esac