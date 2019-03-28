ruby input.rb > test.in
./tle.out < test.in > 1.out
./wa.out < test.in > 2.out
echo "test case:"
cat test.in
diff 1.out 2.out
echo "---------"
cat 1.out
echo ""
echo ""
