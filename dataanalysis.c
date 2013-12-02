// Dylan G.
// Reading input files, writing multiple output for data analysis
/******************************************************************************
 			Example Application:
*******************************************************************************
5 wireless sensors are deployed in a pond, from the surface to the bottom of 
the pond, to measure water temperature during the day. The sensors send their
measured temperature information (in Fahrenheit) to a base station at the 
beginning of each hour. The base station collects all these data into a single 
text file (see the input section for format of this file).

/******************************************************************************
*******************************************************************************
---------Important Note:----------- 
I suggest opening this file using VIM for better viewing 
(color coded,et)
*******************************************************************************
*******************************************************************************/

#include <stdio.h>
#define BLOCK 5

int main(int argc, char *argv[]) {
	FILE *f1,*f2,*f3;
	int sensor[1800], time[1800], i=0, clock, t1, count,b=0,c=0,d=0,e=0,f=0, p=0,g=0, v=0;
  	float temperature[1800], temp1[1800], temp2[1800], temp3[1800], temp4[1800], temp5[1800],sum[1800], hourhigh[1800], hourlow[1800], mean[1800], meansum1=0, meansum2=0, meansum3=0, meansum4=0, meansum5=0, meantotal1, low1, low2, low3, low4, low5, high1, high2, high3, high4, high5;

// verify that user has specified 4 arguments.

  if (argc != 4)
  { printf("\n\n****************************************\nYou have not entered 4 arguments\n****************************************\nPlease enter the program name followed by:\n1. Name of desired input file\n2. Name of desired output file for report 1\n3. Name of desired output file for report 2\n\n\n");
    exit(0);
  }

//Open input file(f1) to read and open first output(f2) file to write
  f1 = fopen(argv[1], "r");
  f2 = fopen(argv[2], "w");

// safety check

  if (f1 == NULL)
  { printf("File %s cannot open!\n", argv[1]);
    exit(0);
  }
	printf("\n\n****************************************************************\n\t         Files opened successfully.\n(Below is a table of sensor temperature data followed by a plot)\n****************************************************************\n\n\n");

//scan the input file

	fprintf(f2, "       sensor1  sensor2  sensor3  sensor4  sensor5   mean\n");

printf("       sensor1  sensor2  sensor3  sensor4  sensor5   mean\n");

clock = 0;

	while (!feof(f1) && clock<24) {
		count=0;
		while (count<BLOCK) {
			fscanf(f1,"%d", &sensor[i]);
			if (sensor[i] == 1) {
				fscanf(f1,"%*c%2d", &time[i]);
				fscanf(f1,"%*s%f", &temperature[i]);
				temp1[i]=(temperature[i]-32.0)*(5.0/9.0);

	//compute overall high/low temperatures for sensor 1
	
			high1 = low1 = temp1[0];
			b=0;
			while (b<i)
			{	if (temp1[b] > high1)
					high1 = temp1[b];
				if (temp1[b] < low1)
					low1 = temp1[b];
				b++;
			}
	//compute mean for all temperature data of sensor 1
	
			 meansum1 = meansum1 + temp1[b]/24;
			}
			if (sensor[i] == 2) {
	     	  		fscanf(f1,"%*c%2d", &time[i]);
				fscanf(f1,"%*s%f", &temperature[i]);
				temp2[i]=(temperature[i]-32.0)*(5.0/9.0);

	//compute overall high/low temperatures for sensor 2
	
			high2 = low2 = temp2[0];
			c=0;
			while (c<i)
			{ 	if (temp2[c] > high2)
					high2 = temp2[c];
				if (temp2[c] < low2)
					low2 = temp2[c];
				c++;
			}

	//compute mean for all temperature data of sensor 2
	
			 meansum2 = meansum2 + temp2[c]/24;
			}
			if (sensor[i] == 3) {
	     	  		fscanf(f1,"%*c%2d", &time[i]);
				fscanf(f1,"%*s%f", &temperature[i]);
				temp3[i]=(temperature[i]-32.0)*(5.0/9.0);

	//compute overall high/low temperatures for sensor 3
	
			high3 = low3 = temp3[0];
			d=0;
			while (d<i)
			{	if (temp3[d] > high3)
					high3 = temp3[d];
				if (temp3[d] < low3)
					low3 = temp3[d];
				d++;
			}
	//compute mean for all temperature data of sensor 3
	
			 meansum3 = meansum3 + temp3[d]/24;
			}
			if (sensor[i] == 4) {
	    	   		fscanf(f1,"%*c%2d", &time[i]);
				fscanf(f1,"%*s%f", &temperature[i]);
				temp4[i]=(temperature[i]-32.0)*(5.0/9.0);

	//compute overall high/low temperatures for sensor 4
	
			high4 = low4 = temp4[0];
			e=0;
			while (e<i)
			{	if (temp4[e] > high4)
					high4 = temp4[e];
				if (temp4[e] < low4)
					low4 = temp4[e];
				e++;
			}

	//compute mean for all temperature data of sensor 4
	
			 meansum4 = meansum4 + temp4[e]/24;
			}
			if (sensor[i] == 5) {
				fscanf(f1,"%*c%2d", &time[i]);
				fscanf(f1,"%*s%f", &temperature[i]);
				temp5[i]=(temperature[i]-32.0)*(5.0/9.0); 

	//compute overall high/low temperatures for sensor 5
	
			high5 = low5 = temp5[0];
			f=0;
			while (f<i)
			{	if (temp5[f] > high5)
					high5 = temp5[f];
				if (temp5[f] < low5)
					low5 = temp5[f];
				f++;
			}

	//compute mean for all temperature data of sensor 5
	
			 meansum5 = meansum5 + temp5[f]/24;
			}
			
//Calculate high temperature for each hour (used later for Report 2 plot)

	if (temp1[i]>temp2[i] && temp1[i]>temp3[i] && temp1[i]>temp4[i] && temp1[i]>temp5[i]){
		hourhigh[g]=temp1[i];}
	if (temp2[i]>temp1[i] && temp2[i]>temp3[i] && temp2[i]>temp4[i] && temp2[i]>temp5[i]){
		hourhigh[g]=temp2[i];}
	if (temp3[i]>temp1[i] && temp3[i]>temp2[i] && temp3[i]>temp4[i] && temp3[i]>temp5[i]){
		hourhigh[g]=temp3[i];}
	if (temp4[i]>temp1[i] && temp4[i]>temp2[i] && temp4[i]>temp3[i] && temp4[i]>temp5[i]){
		hourhigh[g]=temp4[i];}
	if (temp5[i]>temp1[i] && temp5[i]>temp2[i] && temp5[i]>temp3[i] && temp5[i]>temp4[i]){
		hourhigh[g]=temp5[i];}

// Calculate low temperature for each hour (used later for Report 2 plot)

	if (temp1[i]<temp2[i] && temp1[i]<temp3[i] && temp1[i]<temp4[i] && temp1[i]<temp5[i]){
		hourlow[g]=temp1[i];}
	if (temp2[i]<temp1[i] && temp2[i]<temp3[i] && temp2[i]<temp4[i] && temp2[i]<temp5[i]){
		hourlow[g]=temp2[i];}
	if (temp3[i]<temp1[i] && temp3[i]<temp2[i] && temp3[i]<temp4[i] && temp3[i]<temp5[i]){
		hourlow[g]=temp3[i];}
	if (temp4[i]<temp1[i] && temp4[i]<temp2[i] && temp4[i]<temp3[i] && temp4[i]<temp5[i]){
		hourlow[g]=temp4[i];}
	if (temp5[i]<temp1[i] && temp5[i]<temp2[i] && temp5[i]<temp3[i] && temp5[i]<temp4[i]){
		hourlow[g]=temp5[i];}

	count=count+1;
		}

//Calculate mean of each hour's sensor temperature data

	sum[i]=temp1[i]+temp2[i]+temp3[i]+temp4[i]+temp5[i];
	mean[i] = sum[i]/5;

//Print sensor temperature information to output file(f2) previously specified 
//by user

	fprintf(f2, "%02d:00%9.3f%9.3f%9.3f%9.3f%9.3f%9.3f\n", clock, temp1[i], temp2[i], temp3[i], temp4[i], temp5[i], mean[i]);

printf("%02d:00%9.3f%9.3f%9.3f%9.3f%9.3f%9.3f\n", clock, temp1[i], temp2[i], temp3[i], temp4[i], temp5[i], mean[i]);

	i++;
	g++;
	clock = clock + 1;
	count = 0;
	}

//print overall high/low/mean data for each sensor to output file

	fprintf(f2,"high %9.3f%9.3f%9.3f%9.3f%9.3f\n", high1, high2, high3, high4, high5);
	fprintf(f2,"low  %9.3f%9.3f%9.3f%9.3f%9.3f\n", low1, low2, low3, low4, low5);
	fprintf(f2,"mean %9.3f%9.3f%9.3f%9.3f%9.3f\n", meansum1, meansum2, meansum3, meansum4, meansum5);


	printf("high %9.3f%9.3f%9.3f%9.3f%9.3f\n", high1, high2, high3, high4, high5);
	printf("low  %9.3f%9.3f%9.3f%9.3f%9.3f\n", low1, low2, low3, low4, low5);
	printf("mean %9.3f%9.3f%9.3f%9.3f%9.3f\n", meansum1, meansum2, meansum3, meansum4, meansum5);


//close first output file(f2) and open second output file(f3) for report 2 

	fclose (f2);
	f3 = fopen(argv[3], "w");

//Print Plot for Report 2 (Graph) to screen and second output file:

printf("\n     - - - -           1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 6 6 6\n");
	fprintf(f3,"     - - - -           1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 6 6 6\n");
printf("     8 6 4 2 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4\n");
	fprintf(f3,"     8 6 4 2 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4 6 8 0 2 4\n");
printf("   + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	fprintf(f3,"   + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

//Here is the while loop used to generate location of low/mean/high symbols

p = 0;
g = 0;
i = 0;
clock = 0;
while (p<24) {
	printf("%2d | ", clock);
		fprintf(f3, "%2d | ", clock);
	v = -8;
	while (v < hourlow[g]){
		printf(" ");
			fprintf(f3, " ");
		v++;
	}
	printf("*");
		fprintf(f3, "*");
	v=v+1;
	while (v < mean[i]){
		printf(" ");
			fprintf(f3, " ");
		v++;
	}
	printf("#");
		fprintf(f3, "#");
	v=v+2;
	while (v < hourhigh[g]){
		printf(" ");
			fprintf(f3, " ");
		v++;
	}
	printf("+\n");
		fprintf(f3, "+\n");
	clock = clock +1;
	p++;
	g++;
	i++;
}

//close input file and second output file

fclose (f1);
fclose (f3);

//close program

printf("\n\n");
  return 0;
}
