/*
 * strings.cpp
 *
 *  Created on: 20.11.2014 г.
 *      Author: trifon
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;

void palindrome() {
	char s[MAX];
	cin.getline(s, MAX);

	int n = strlen(s);
	int i = 0;
	while (i < n / 2 && s[i] == s[n - i - 1])
		i++;

	// a[i] != a[j], j е "огледалното" на i
	// j = n - i - 1
	// прегледали сме всички k огледални двойки
	// k == n / 2
	// i == k == n / 2 --> прегледали сме всички двойки

	if (i == n / 2)
		cout << "Палиндром е!\n";
	else
		cout << "Не е палиндром!\n";

}

int testStrings() {

	int a[] = { 1, 2, 3 };
	char w1[] = "He\nllo";
	char w2[MAX] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << w1 << endl;
	cout << w2 << endl;
	cout << a << endl;
	//cin >> w1;
	//cout << w1 << endl;
	// !!! cin >> a;
	cin.getline(w2, MAX);
	//cin.getline(w2, 10, '!');
	cout << w2 << endl;

	cout << strlen(w2) << endl;
	cout << strcpy(w2, "Goodbye!") << endl;
	cout << w2 << endl;
	// !!! strcpy("Goodbye!", w2);
	cout << strcmp(w1, w2) << endl;

	// !!! if (strcmp(w2, "Goodbye!"))
	if (strcmp(w2, "Goodbye!") == 0)
		cout << "Да!" << endl;

	cout << strcat(w2, " See you soon!") << endl;
	cout << w2 << endl;

	cout << strchr(w2, 'b') << endl;
	// !!! cout << strchr(w2, 'X') << endl;

	if (strchr(w2, 'X'))
		cout << "Има X!\n";
	else
		cout << "Няма X!\n";

	cout << strstr(w2, "you") << endl;
	if (strstr(w2, "Hello"))
		cout << "Има Hello!\n";
	else
		cout << "Няма Hello!\n";

	return 0;
}

bool isSeparator(char c) {
	return c == ' ' || c == ',' || c == '.' || c == '\0';
}

void countWords() {
	char s[MAX];
	cin.getline(s, MAX);


	int counter = 0, i = 0;
	bool onWord = false;
	/*
	while (s[i] != '\0') {
		bool onWordNext = !isSeparator(s[i]);
		if (onWord && !onWordNext)
			counter++;
		onWord = onWordNext;
		i++;
	}
	if (onWord)
		counter++;
		*/
	do {
		bool onWordNext = !isSeparator(s[i]);
		if (onWord && !onWordNext)
			counter++;
		onWord = onWordNext;
		i++;
	} while(s[i-1] != '\0');

	cout << "Намерени са " << counter << " думи" << endl;
}

int main() {
	// testStrings();
	// palindrome();
	countWords();
	return 0;
}

