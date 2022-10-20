./tests_data_merger.sh
MERGE_RES="${?}"

gcc -std=c89 -Wall -Werror -pedantic -o "ans_checker" "ans_checker.c"

if [ $MERGE_RES -eq "0" ]
then

while read PROG
do
	
	PROG=${PROG%$'\n'}
	PROG=${PROG%$'\r'}
	#gcc -c -std=c89 -Wall -Werror -pedantic -lm "${PROG}.c" 2> /dev/null && gcc -Wall -o "${PROG}" "${PROG}.o" 2> /dev/null
	gcc -std=c89 -Wall -Werror -pedantic -o "${PROG}" "${PROG}.c" -lm
	COMP_RES="${?}"
	if [ $COMP_RES -eq "0" ]
	then
		
		echo ""
		echo "${PROG} : Compiled"
		echo ""
		
		cat "all_test_data.btdata" | grep "${PROG}:" | grep "in" > "current_test_in_data.btdata"

		while read TEST
		do
			TEST_ID=$(echo $TEST | cut -d ':' -f 2)
			
			INPUT_DATA=$(echo $TEST | cut -d ':' -f 4)
			
			COR_ANS=$(cat "all_test_data.btdata" | grep "${PROG}:" | grep "${TEST_ID}" | grep "ou" | cut -d ':' -f 4)
			
			REQ_EXIT=$(cat "all_test_data.btdata" | grep "${PROG}:" | grep "${TEST_ID}" | grep "ex" | cut -d ':' -f 4)
			REQ_EXIT=${REQ_EXIT%$'\n'}
			REQ_EXIT=${REQ_EXIT%$'\r'}
			
			ARG_DATA=$(cat "all_test_data.btdata" | grep "${PROG}:" | grep "${TEST_ID}" | grep "ar" | cut -d ':' -f 4)
			ARG_DATA=${ARG_DATA%$'\n'}
			ARG_DATA=${ARG_DATA%$'\r'}
			
			ANS=$(echo $INPUT_DATA | timeout 5 "./${PROG}" 2>&1)
			
			EXIT_CODE=$(echo $?)
			
			if [ "${EXIT_CODE}" = "${REQ_EXIT}" ]
			then
				CHECK_DATA=$(printf "a${COR_ANS}\n${ANS}")
				
				printf "${CHECK_DATA}\n" | timeout 3 ./ans_checker $ARG_DATA
				CHECK_RES=$(echo $?)
				
				if [ "${REQ_EXIT}" = "1" ] && [ "${ANS}" = "" ]
				then
					echo "${PROG} : ${TEST_ID} : OK (correct input check)"
					#echo "Tested for input: ${INPUT_DATA}"
				elif [ "${REQ_EXIT}" = "1" ]
				then
					echo "${PROG} : ${TEST_ID} : FAIL (extra output / runtime error)"
					echo "Input data: ${INPUT_DATA}"
					echo "Answer:"
					echo "[${ANS}]"
					echo "Exit code: ${EXIT_CODE}"
					echo "Correct answer: $[{COR_ANS}]"
					echo "Correct exit code: ${REQ_EXIT}"
				
				elif [ "${CHECK_RES}" = "124" ]
				then
					echo "${PROG} : ${TEST_ID} : TESTER TL (incorrect output format / incorrect test data)"
					echo "Input data: ${INPUT_DATA}"
					echo "Answer:"
					echo "[${ANS}]"
					echo "Correct answer: [${COR_ANS}]"
				elif [ "${CHECK_RES}" = "3" ]
				then
					echo "${PROG} : ${TEST_ID} : TESTER ERROR (incorrect test data)"
					echo "Input data: ${INPUT_DATA}"
					echo "Answer:"
					echo "${ANS}"
					echo "Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "2" ]
				then
					echo "${PROG} : ${TEST_ID} : FAIL (incorrect output format)"
					echo "Input data: ${INPUT_DATA}"
					echo "Answer:"
					echo "[${ANS}]"
					echo "Correct answer: [${COR_ANS}]"
				elif [ "${CHECK_RES}" = "1" ]
				then
					echo "${PROG} : ${TEST_ID} : FAIL (wrong answer)"
					echo "Input data: ${INPUT_DATA}"
					echo "Answer:"
					echo "${ANS}"
					echo "Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "0" ]
				then
					echo "${PROG} : ${TEST_ID} : OK (correct answer)"
					#echo "Tested for input: ${INPUT_DATA}"
				else
					echo "${PROG} : ${TEST_ID} : TESTER ERROR ${CHECK_RES} (some real bullshit happened)"
					echo "Input data: ${INPUT_DATA}"
					echo "Answer:"
					echo "[${ANS}]"
					echo "Exit code: [${EXIT_CODE}]"
					echo "Correct answer: [${COR_ANS}]"
					echo "Correct exit code: [${REQ_EXIT}]"
					
				fi
			elif [ "${EXIT_CODE}" = "124" ]
			then
				echo "${PROG} : ${TEST_ID} : FAIL (program worked > 5 seconds (infinite loop / extra scanf / ineffective algorithm))"
				echo "Input data: ${INPUT_DATA}"
			else
				echo "${PROG} : ${TEST_ID} : WRONG EXIT CODE (or incorrect test data)"
				echo "Input data: ${INPUT_DATA}"
				echo "Answer:"
				echo "${ANS}"
				echo "Exit code: ${EXIT_CODE}"
				echo "Correct answer: ${COR_ANS}"
				echo "Correct exit code: ${REQ_EXIT}"
			fi
		
		echo ""
			
		done < "current_test_in_data.btdata"
		
		echo "No more tests for ${PROG}"
		echo "_________________________________"

	else
		
		echo ""
		echo "${PROG}.c : Source file not found or compilation error"
		echo ""
		echo "Check for correct spelling,"
		echo "program source or test script location"
		echo "or compilation flags"
		echo "(gcc -c -std=c89 -Wall -Werror -pedantic -lm <source_file>)"
		echo "_________________________________"

	fi
	rm "current_test_in_data.btdata" 2> /dev/null
	rm "${PROG}"
done < "prog_list.btdata"

rm "all_test_data.btdata" 2> /dev/null
rm "ans_checker" 2> /dev/null

else
echo "TEST DATA MERGING ERROR"

fi

$SHELL
