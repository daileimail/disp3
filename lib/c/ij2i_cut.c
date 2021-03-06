/*
# Descriptions   : 
# Usage          : 
# Parameters	 : none
# Sample Input   : 
# Sample Output  : 
# Depedency      : none
# Temp File      : none
# Comments       : none
# See Also       : none
# Data           : 
# Template       : Last modified date 11/16/10
# Author         : setupX
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#include "../net_mn.h"

int main(int argc, char *argv[]){
	FILE *fp1;
	FILE *fp2;
	char line[MAX_LINE_SIZE];
	char file1[MAX_FILE_NAME_SIZE];
	char file2[MAX_FILE_NAME_SIZE];
	int ln,i;
	char *token;
	MN2I mn2i1,mn2i2;
	int not_end1,not_end2;
	int c1,c2,ci,cut;


	strcpy(file1,argv[1]);
	strcpy(file2,argv[2]);
	cut=atoi(argv[3]);
	
	c1=0;
	c2=0;
	ci=0;
	if ((fp1 = fopen(file1, "r")) == NULL){
		fprintf(stderr, "Coudn't open file %s\n",file1);
		return -1;
	}
	if ((fp2 = fopen(file2, "r")) == NULL){
		fprintf(stderr, "Coudn't open file %s\n",file2);
		return -1;
	}
	
//	mn2i2 is super set

	not_end1=read_mn2i_fp(fp1,&mn2i1);
	not_end2=read_mn2i_fp(fp2,&mn2i2);
	while (not_end1 && not_end2){

		if (atoi(mn2i1.m) < atoi(mn2i2.m)){
			if(mn2i1.i>=cut) c1++;
			not_end1 = read_mn2i_fp(fp1,&mn2i1);
			continue;
		}
		if (atoi(mn2i1.m) > atoi(mn2i2.m)){
			if(mn2i2.i>=cut) c2++;
			not_end2 = read_mn2i_fp(fp2,&mn2i2);
			continue;
		}

		if (atoi(mn2i1.n) < atoi(mn2i2.n)){
			if(mn2i1.i>=cut) c1++;
			not_end1 = read_mn2i_fp(fp1,&mn2i1);
			continue;
		}
		if (atoi(mn2i1.n) > atoi(mn2i2.n)){
			if(mn2i2.i>=cut) c2++;
			not_end2 = read_mn2i_fp(fp2,&mn2i2);
			continue;
		}
		if(mn2i1.i>=cut && mn2i2.i>=cut) {ci++;}
		if(mn2i1.i>=cut) {c1++;}
		if(mn2i2.i>=cut) {c2++;}
		not_end1 = read_mn2i_fp(fp1,&mn2i1);
		not_end2 = read_mn2i_fp(fp2,&mn2i2);
	}
	while (not_end1){
		if(mn2i1.i>=cut) c1++;
		not_end1 = read_mn2i_fp(fp1,&mn2i1);
	}
	while (not_end2){
		if(mn2i2.i>=cut) c2++;
		not_end2 = read_mn2i_fp(fp2,&mn2i2);
	}

	fclose(fp1);
	fclose(fp2);
	printf("%d\t%d\t%d\t%f\t%f\n",
		c1,c2,ci,(double)ci/(double)c1,(double)ci/(double)c2);
	return 1;
}
