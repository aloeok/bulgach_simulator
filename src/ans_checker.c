#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_ANS_SER_CNT 10
#define MAX_SER_DATA_CNT 10

int ans_series_count;
int ans_series_params[MAX_ANS_SER_CNT][2];		/*	asp[ser_ind][0] - type (0 - int, 1 - double, 2 - string); asp[ser_ind][1] - count		*/

int int_ans_cor [MAX_SER_DATA_CNT];
int int_ans [MAX_SER_DATA_CNT];

double double_ans_cor [MAX_SER_DATA_CNT];
double double_ans [MAX_SER_DATA_CNT];

char string_ans_cor [MAX_SER_DATA_CNT][100];
char string_ans [MAX_SER_DATA_CNT][100];

int set_series_params (int argc, char** argv);
int get_correct_ans ();
int get_ans ();
int check_ans ();

int main (int argc, char** argv) {
	int exit_code;
	
	exit_code = set_series_params(argc, argv);
	if (exit_code == 1)
		return 3;
	
	exit_code = get_correct_ans();
	if (exit_code == 1)
		return 3;
	
	exit_code = get_ans();
	if (exit_code == 1)
		return 2;
	
	exit_code = check_ans();
	
	return exit_code;
}

int set_series_params (int argc, char** argv) {
	int i;
	ans_series_count = 0;
	
	for (i = 1; i < argc; i += 2) {
		if (strcmp(argv[i], "-d") == 0) {
			ans_series_params[ans_series_count][0] = 0;
			ans_series_params[ans_series_count][1] = atoi(argv[i + 1]);
			++ ans_series_count;
		} else if (strcmp(argv[i], "-lf") == 0) {
			ans_series_params[ans_series_count][0] = 1;
			ans_series_params[ans_series_count][1] = atoi(argv[i + 1]);
			++ ans_series_count;
		} else if (strcmp(argv[i], "-s") == 0) {
			ans_series_params[ans_series_count][0] = 2;
			ans_series_params[ans_series_count][1] = atoi(argv[i + 1]);
			++ ans_series_count;
		} else {
			return 1;
		}
	}
	
	if (ans_series_count == 0) {
		return 1;
	}
	
	return 0;
}

int get_correct_ans () {
	int series, i, scheck;
	for (series = 0; series < ans_series_count; ++ series) {
		for (i = 0; i < ans_series_params[series][1]; ++ i) {
			switch (ans_series_params[series][0]) {
				case 0:
					scheck = scanf("%d", &int_ans_cor[i]);
					break;
				case 1:
					scheck = scanf("%lf", &double_ans_cor[i]);
					break;
				case 2:
					scheck = scanf("%s", string_ans_cor[i]);
					break;
				default:
					return 1;
			}
			if (scheck != 1) {
				return 1;
			}
		}
	}
	return 0;
}

int get_ans () {
	int series, i, scheck;
	char delim;
	for (series = 0; series < ans_series_count; ++ series) {
		for (i = 0; i < ans_series_params[series][1]; ++ i) {
			switch (ans_series_params[series][0]) {
				case 0:
					scheck = scanf("%d", &int_ans[i]);
					break;
				case 1:
					scheck = scanf("%lf", &double_ans[i]);
					break;
				case 2:
					scheck = scanf("%s", string_ans[i]);
					break;
				default:
					return 1;
			}
			if (scheck != 1)
				return 1;
			delim = getc(stdin);
			if (delim >= 32)
				return 1;
		}
	}
	return 0;
}

int check_ans () {
	int series, i;
	for (series = 0; series < ans_series_count; ++ series) {
		for (i = 0; i < ans_series_params[series][1]; ++ i) {
			switch (ans_series_params[series][0]) {
				case 0:
					if (int_ans_cor[i] != int_ans[i])
						return 1;
					break;
				case 1:
					if (double_ans_cor[i] != double_ans[i])
						return 1;
					break;
				case 2:
					if (strcmp(string_ans_cor[i], string_ans[i]) != 0)
						return 1;
					break;
			}
		}
	}
	return 0;
}
