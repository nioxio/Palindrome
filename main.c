#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	printf(" \033[36m------------------\n");
	printf(" Palindrome checker\n");
	printf(" \033[36m------------------\n");
	do {
		char input[999];
		printf(" \033[33mPlease enter a sentence or a word : \033[36m");
		scanf("%999[^\n]", &input);
		// if input is too big, clear input and ask for new input
		if (strlen(input) > 999) {
			fseek(stdin, 0, SEEK_END);
			main();
			return 0;
		}
		// Call funktion to check if input is a palindrome, respond depending on return value
		int answer = isPalindrome(input);
		if (answer == 0) {
			printf(" \033[32m\"\033[36m%s\033[32m\" is a palindrome, press Q to exit.\n", input);
		}
		else if (answer == 1) {
			printf(" \033[31m\"\033[36m%s\033[31m\" is not a palindrome, press Q to exit.\n", input);
		}
		// Clear input in case something went wrong
		fseek(stdin, 0, SEEK_END);
		// End loop if player wishes to
	} while (tolower(getch()) != 'q');
	printf("\033[30m");
	return 0;
}

int isPalindrome(char inputString[]) {
	int length = strlen(inputString);
	int j = length - 1;
	// See if first char matches last char, then go inwards from there.
	for (int i = 0; i < length; i++ & j--) {
		// If the current char is a space, skip until the char is not a space
		for (i; inputString[i] == ' '; i++);
		for (j; inputString[j] == ' '; j--);
		if (tolower(inputString[i]) != tolower(inputString[j])) {
			return 1;
		}
	}
	return 0;
}