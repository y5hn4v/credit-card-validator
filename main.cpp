/*
* A  simple credit card validator using the Luhn Algorithm
* The user enters a card number and the program checks if it is valid or not
*/

#include<iostream>
#include<string>


//Function to validate the card using the Luhn Algorithm
//We are using long long as the number of digits can go upto 11 or even more

bool validate( long long card) {
	std::string card_string = std::to_string(card); // Conversion into string
	int i{}, sum{ 0 };
	bool is_sec = false;
	for (i = card_string.length() - 1; i >= 0; i--) {
		int d = card_string[i] - '0';
		if (is_sec) { //Checking if the value is a second digit from the right side (Eg : 12345 , the numbers 4 and 2 are second digits)
			d *= 2;
			if (d > 9) { //Checking if the double of that number is a two digit
				//The below operations finds the sum of the two digits in 'd'
				sum += (d / 10);
				sum += (d % 10);
			}
			else sum += d;
		}
		else sum += d;
		is_sec = !is_sec; // Changing the value to its opposite
	}
	return(sum % 10 == 0); // Checking if the sum ends with a 0 i.e. is a multiple of 10

}

int main() {
	std::cout << "Enter the card number to validate : ";
	long long card{};
	std::cin >> card;
	if (validate(card)) std::cout << "The card is valid";
	else std::cout << "The card is invalid";
	return 0;
}