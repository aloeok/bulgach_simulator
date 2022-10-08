echo "Searching for test data..."
echo ""
echo "all test data" > "all_test_data.btdata"

while read PROG
do
	PROG=${PROG%$'\n'}
	PROG=${PROG%$'\r'}
	cat "test_data/${PROG}_test_data.txt" 2>/dev/null >> "all_test_data.btdata"
	RES="${?}"
	
	if [ "${RES}" = "0" ]
	then
		echo "${PROG} : test data FOUND"
	elif [ "${PROG}" != "" ]
	then
		echo "${PROG} : test data NOT FOUND"
	fi
	
done < "prog_list.btdata"

echo ""
echo "_________________________________"
