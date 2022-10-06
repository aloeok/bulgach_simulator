./tests_data_merger.sh
MERGE_RES="${?}"

if [ $MERGE_RES -eq "0" ]
then

while read PROG
do
	
	PROG=${PROG%$'\n'}
	PROG=${PROG%$'\r'}
	gcc -c -std=c89 -Wall -Werror -pedantic -lm "${PROG}.c" 2> /dev/null && gcc -Wall -o "${PROG}" "${PROG}.o" 2> /dev/null
	COMP_RES="${?}"
	if [ $COMP_RES -eq "0" ]
	then
		
		echo ""
		echo "${PROG} : Compiled"
		echo ""
		
		cat "all_test_data.btdata" | grep "${PROG}" | grep "in" > "current_test_in_data.btdata"

		while read TEST
		do
			TEST_ID=$(echo $TEST | cut -d ':' -f 2)
			
			INPUT_DATA=$(echo $TEST | cut -d ':' -f 4)
			
			COR_ANS=$(cat "all_test_data.btdata" | grep "${PROG}" | grep "${TEST_ID}" | grep "ou" | cut -d ':' -f 4)
			
			REQ_EXIT=$(cat "all_test_data.btdata" | grep "${PROG}" | grep "${TEST_ID}" | grep "ex" | cut -d ':' -f 4)
			REQ_EXIT=${REQ_EXIT%$'\n'}
			REQ_EXIT=${REQ_EXIT%$'\r'}
			
			ARG_DATA=$(cat "all_test_data.btdata" | grep "${PROG}" | grep "${TEST_ID}" | grep "ar" | cut -d ':' -f 4)
			ARG_DATA=${ARG_DATA%$'\n'}
			ARG_DATA=${ARG_DATA%$'\r'}
			
			ANS=$(echo $INPUT_DATA | timeout 10 "./${PROG}" 2>&1)
			EXIT_CODE=$(echo $?)
			
			if [ "${EXIT_CODE}" = "${REQ_EXIT}" ]
			then
				CHECK_DATA=$(echo -e "${COR_ANS}\n${ANS}")
				echo $CHECK_DATA | timeout 3 ./ans_checker $ARG_DATA
				CHECK_RES=$(echo $?)
				
				if [ "${REQ_EXIT}" = "1" ] && [ "${ANS}" = "" ]
				then
					echo "${PROG} : ${TEST_ID} : OK"
					echo "(Tested for input: ${INPUT_DATA})"
				elif [ "${REQ_EXIT}" = "1" ]
				then
					echo "${PROG} : ${TEST_ID} : EXTRA OUTPUT / RUNTIME ERROR"
					echo "Input data: ${INPUT_DATA}"
					echo -e "Answer:\n${ANS}"
					echo "Exit code: ${EXIT_CODE}"
					echo "Correct answer: ${COR_ANS}"
					echo "Correct exit code: ${REQ_EXIT}"
				
				elif [ "${CHECK_RES}" = "124" ]
				then
					echo "${PROG} : ${TEST_ID} : INCORRECT OUTPUT FORMAT"
					echo "Input data: ${INPUT_DATA}"
					echo -e "Answer:\n${ANS}"
					echo "Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "3" ]
				then
					echo "${PROG} : ${TEST_ID} : INCORRECT TEST FILE DATA !!!"
					echo "Input data: ${INPUT_DATA}"
					echo -e "Answer:\n${ANS}"
					echo "Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "2" ]
				then
					echo "${PROG} : ${TEST_ID} : INCORRECT OUTPUT FORMAT"
					echo "Input data: ${INPUT_DATA}"
					echo -e "Answer:\n${ANS}"
					echo "Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "1" ]
				then
					echo "${PROG} : ${TEST_ID} : WRONG ANSWER"
					echo "Input data: ${INPUT_DATA}"
					echo -e "Answer:\n${ANS}"
					echo "Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "0" ]
				then
					echo "${PROG} : ${TEST_ID} : OK"
					echo "(Tested for input: ${INPUT_DATA})"
				else
					echo "${PROG} : ${TEST_ID} : TESTER ERROR ${CHECK_RES}"
					echo "Input data: ${INPUT_DATA}"
					echo -e "Answer:\n${ANS}"
					echo "Correct answer: ${COR_ANS}"
				fi
			elif [ "${EXIT_CODE}" = "124" ]
			then
				echo "${PROG} : ${TEST_ID} : PROGRAM WORKED >10 SECONDS (check for infinite loops)"
				echo "Input data: ${INPUT_DATA}"
			else
				echo "${PROG} : ${TEST_ID} : WRONG EXIT CODE / RUNTIME ERROR"
				echo "Input data: ${INPUT_DATA}"
				echo -e "Answer:\n${ANS}"
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
done < "prog_list.btdata"

rm "all_test_data.btdata" 2> /dev/null

else
echo "MERGING ERROR"

fi

$SHELL
