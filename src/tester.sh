while read PROG
do
	
	PROG=${PROG%$'\n'}
	PROG=${PROG%$'\r'}
	gcc -Wall -c -std=c89 -Wall -Werror -pedantic -lm "${PROG}.c" 2> /dev/null && gcc -Wall -o "${PROG}" "${PROG}.o" 2> /dev/null
	COMP_RES="${?}"
	if [ $COMP_RES -eq "0" ]
	then
		
		echo ""
		echo "_________________________________"
		echo "${PROG} : Compiled"
		echo ""
		
		cat "test_list.txt" | grep "${PROG}" | grep "in" > "test_input.txt"

		while read TEST
		do
			TEST_ID=$(echo $TEST | cut -d ':' -f 2)
			
			INPUT_DATA=$(echo $TEST | cut -d ':' -f 4)
			
			COR_ANS=$(cat "test_list.txt" | grep "${PROG}" | grep "${TEST_ID}" | grep "ou" | cut -d ':' -f 4)
			
			REQ_EXIT=$(cat "test_list.txt" | grep "${PROG}" | grep "${TEST_ID}" | grep "ex" | cut -d ':' -f 4)
			REQ_EXIT=${REQ_EXIT%$'\n'}
			REQ_EXIT=${REQ_EXIT%$'\r'}
			
			ARG_DATA=$(cat "test_list.txt" | grep "${PROG}" | grep "${TEST_ID}" | grep "ar" | cut -d ':' -f 4)
			ARG_DATA=${ARG_DATA%$'\n'}
			ARG_DATA=${ARG_DATA%$'\r'}
			
			ANS=$(echo $INPUT_DATA | timeout 10 "./${PROG}" 2>&1)
			EXIT_CODE=$(echo $?)
			
			if [ "${EXIT_CODE}" = "${REQ_EXIT}" ]
			then
				CHECK_DATA=$(echo -e "${COR_ANS}\n${ANS}")
				echo $CHECK_DATA | timeout 2 ./ans_checker $ARG_DATA
				CHECK_RES=$(echo $?)
				
				if [ "${REQ_EXIT}" = "1" ] && [ "${ANS}" = "" ]
				then
					echo "${PROG} : ${TEST_ID} : OK"
				elif [ "${REQ_EXIT}" = "1" ]
				then
					echo "${PROG} : ${TEST_ID} : EXTRA OUTPUT / RUNTIME ERROR"
					echo "           Input data: ${INPUT_DATA}"
					echo -e "               Answer:\n${ANS}"
					echo "            Exit code: ${EXIT_CODE}"
					echo "       Correct answer: ${COR_ANS}"
					echo "    Correct exit code: ${REQ_EXIT}"
				
				elif [ "${CHECK_RES}" = "124" ]
				then
					echo "${PROG} : ${TEST_ID} : INCORRECT OUTPUT FORMAT"
					echo "           Input data: ${INPUT_DATA}"
					echo -e "               Answer:\n${ANS}"
					echo "       Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "3" ]
				then
					echo "${PROG} : ${TEST_ID} : INCORRECT TEST FILE DATA !!!"
					echo "           Input data: ${INPUT_DATA}"
					echo -e "               Answer:\n${ANS}"
					echo "       Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "2" ]
				then
					echo "${PROG} : ${TEST_ID} : INCORRECT OUTPUT FORMAT"
					echo "           Input data: ${INPUT_DATA}"
					echo -e "               Answer:\n${ANS}"
					echo "       Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "1" ]
				then
					echo "${PROG} : ${TEST_ID} : WRONG ANSWER"
					echo "           Input data: ${INPUT_DATA}"
					echo -e "               Answer:\n${ANS}"
					echo "       Correct answer: ${COR_ANS}"
				elif [ "${CHECK_RES}" = "0" ]
				then
					echo "${PROG} : ${TEST_ID} : OK"
				else
					echo "${PROG} : ${TEST_ID} : TESTER ERROR ${CHECK_RES}"
					echo "           Input data: ${INPUT_DATA}"
					echo -e "               Answer:\n${ANS}"
					echo "       Correct answer: ${COR_ANS}"
				fi
			elif [ "${EXIT_CODE}" = "124" ]
			then
				echo "${PROG} : ${TEST_ID} : PROGRAM WORKED >10 SECONDS (check for infinite loops)"
				echo "           Input data: ${INPUT_DATA}"
			else
				echo "${PROG} : ${TEST_ID} : WRONG EXIT CODE / RUNTIME ERROR"
				echo "           Input data: ${INPUT_DATA}"
				echo -e "               Answer:\n${ANS}"
				echo "            Exit code: ${EXIT_CODE}"
				echo "       Correct answer: ${COR_ANS}"
				echo "    Correct exit code: ${REQ_EXIT}"
			fi
			
			echo ""
			
		done < "test_input.txt"
		
		echo ""
		echo "_________________________________"
		echo ""
		echo ""

	else
		
		echo ""
		echo "_________________________________"
		echo "${PROG}.c : Not found or compilation error"
		echo ""
		echo "_________________________________"
		echo ""
		echo ""

	fi

done < "progs_list.txt"
rm "test_input.txt" 2> /dev/null
$SHELL
