#include <stdio.h>
#include <string.h>

int main()
{	
	char* words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 
					 "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty",
					 "sixty", "seventy", "eighty", "ninety", "hundred"};

	size_t letter_count = 0;
	int i;
	for (i = 1; i < 20; ++i) //First 19 numbers
		letter_count += strlen(words[i]);

	int p = 19;
	for (i = 20; i < 100; i += 10) {//First 99 numbers
		++p;
		letter_count += strlen(words[p]);
		for (int k = 1; k <= 9; ++k)
			letter_count += strlen(words[k]) + strlen(words[p]);
	}

	size_t dest = letter_count;
	int k;

	for (k = 1; k <= 9; ++k)
		letter_count += (strlen(words[k]) + strlen(words[28]) + 3)*99 + dest;

	for (int y = 1; y <= 9; ++y) //Adding one hundred, two hundred, ...
		letter_count += strlen(words[y]) + strlen(words[28]);

	printf("Total letters: %zu\n", letter_count + 11); //strlen("one thousand") = 8 

	return 0;
}

