// Description: This program asks the user to enter a word that starts with a specific letter of
// their choice and ensures that the user enters a valid starting character and a valid word. It
// covers these learning outcomes:
//		validating a letter character,
//		validating the starting letter of a string,
//		while loops,
//		looping forever for easy testing.
// Instruction files: 
//		https://bhcc.digication.com/cit120all_master_delta/Inpout_validation_lab_word_that_starts_with_a_spec
// Title: Input Validation - Word That Starts With A Specific Letter - Version 2
// Programmer: C. Ho
// Last Modified: Wed. Dec. 13, 2023 @ 3:56 PM

// PREPROCESSOR DIRECTIVE SECTION
#include <iostream>
#include <string>
using namespace std;

// FUNCTION DECLARATION SECTION, INCLUDING FUNCTION PROTOTYPES - N/A IN THIS LAB

// MAIN SECTION
int main()
{
	// SET UP SECTION
	// System function call to change text in title bar
	system("title .     \"While\" Validation Loops In-Class Exercise     by C. Ho");

	// System function call to change the color of the cmp window (background, foreground)
	system("color E1");

	// Centered banner using the WYSIWYG approach
	cout << "\n"
		<< "\t           Validate the starting letter of a string,           \n"
		<< "\t                     while validation loop,                    \n"
		<< "\tuses the conditional operator for the customized error message,\n"
		<< "\t            as well looping forever for easy testing           \n"
		<< "\t                  Optional Lab #5 - Version 2                  \n"
		<< "\t                            by C. Ho                           \n\n";

	// VARIABLE DECLARATION SECTION
	// const char desiredStartingChar;	// This causes an error
	char desiredStartingChar;
	string userWord;

	// INPUT SECTION
	// Prompt user to enter a letter that they want words to start with.
	cout << "What letter do you want the word to start with? ";

	// Get user's starting letter.
	cin >> desiredStartingChar;
	cin.ignore(1000, '\n');

	// Validate the user's starting character.
	// While the user's starting character is not a letter...
	while (!(desiredStartingChar > 'A' && desiredStartingChar < 'Z' ||
		desiredStartingChar > 'a' && desiredStartingChar <= 'z'))
	{
		// If user's starting character is a special character...  // no majic numbers the ASCII values may change 
		// don't expect people to know the ASCII values so your code as it is, it is hard to debgug
		if (desiredStartingChar >= static_cast<char>(33) && desiredStartingChar <= static_cast<char>(47) ||
//			desiredStartingChar >= static_cast<char>(33) && desiredStartingChar <= static_cast<char>(47) ||
			desiredStartingChar >= static_cast<char>(58) && desiredStartingChar <= static_cast<char>(64) ||
			desiredStartingChar >= static_cast<char>(91) && desiredStartingChar <= static_cast<char>(96) ||
			userWord[0] >= static_cast<char>(123) && userWord[0] <= static_cast<char>(127))
			// ...print detailed error message & prompt user to re-enter.
			cout << "  \'" << desiredStartingChar << "\' is NOT a letter. It is a special character.\n"
				<< "      Try again: ";
		else  // instead do the digit first and it if is NOT a digit then it is special character
			// ...print detailed error message & prompt user to re-enter.
			cout << "  \'" << desiredStartingChar << "\' is NOT a letter. It is a digit.\n"
			<< "      Try again: ";

		// Get user's starting letter again.
		cin >> desiredStartingChar;
		cin.ignore(1000, '\n');
	}

	// Confirm user's starting letter.
	cout << "\nOK, we are looking for a word that starts with \'" << desiredStartingChar << "\'.\n\n";

	// Start forced infinite loop for continuous testing.
	while (true)
	{
		while (desiredStartingChar > 'A' && desiredStartingChar < 'Z' ||
			desiredStartingChar > 'a' && desiredStartingChar <= 'z')
		{
			cout << "Please enter a SINGLE WORD that starts with \'" << desiredStartingChar
				<< "\' (case sensitive): ";

			// Get user's word.
			cin >> userWord;
			cin.ignore(1000, '\n');


			// Validate user input - While user's word does not begin with user's starting character...
			while (userWord[0] != desiredStartingChar)
			{
				// ...display error message/detailed input hint to user.
				cout << "     Your word \"" << userWord << "\" starts with the letter \'" << userWord[0]
					<< "\'.\n     You need to have a word that starts with \'" << desiredStartingChar << "\'.\n";
				
				// Prompt user to enter a valid word.
				cout << "     Please enter an appropriate word: ";
				cin >> userWord;
				cin.ignore(1000, '\n');
			}

			// Display confirmation message.
			cout << "\n"
				<< "Thank you for providing the string \"" << userWord << "\", which starts with the letter \'"
				<< desiredStartingChar << "\'.\n"
				<< "Now let's do it again!\n\n";

			cout << "     *****************\n\n";
		}
	// End forced infinite loop for continuous testing.
	}
		// PROCESSING SECTION 

		// OUTPUT SECTION

		// CLEAN UP SECTION
		system("pause");	// Hold screen so user will see the final message.
		return 0;			// End program.
// MAIN ENDS
}