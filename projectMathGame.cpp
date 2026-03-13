#include <iostream>
#include <random>
#include <cstdlib>  
#include <string>
#include <Windows.h>
#include <thread>  
#include <chrono>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int color)
{
	SetConsoleTextAttribute(hConsole, color);
}
class Question {

private:
	int _number1;
	int _number2;

public:
	int num1() const {
		return this->_number1;
	}

	int num2() const {
		return this->_number2;
	}

	// Ask user how many questions he wants (1 - 100)
	int HowManyQuestion() {
		int number;
		cout << "How many questions do you want (max 100) in this game ?  " << endl;
		cout << "Questions: ";
		cin >> number;
		while (number < 1 || number >100) {

			setColor(12);
			cout << "Error: must enter a number from 1 to 100:\n";
			cin >> number;
			setColor(7);

		}
		return  number;
	}

	enum level
	{
		easy,
		Medium,
		Hard,
		mix

	};

	enum Operation {
		Plus,
		Sub,
		Mul,
		Divide,
		Mix
	};

	int _CounterRightQuestion = 0;

	int WhatALevel() {
		int level = -1;

		while (level < 0 || level > 3) {
			cout << "What level do you want (Easy=0 ,Medium =1 , Hard =2 , Mix =3) ?\n";
			cout << "Level: ";
			cin >> level;

		}
		return  level;

	}

	int WhatOperator() {
		int operate = -1;

		while (operate < 0 || operate >4) {
			cout << "Which operator do you want (Plus :0, Sub: 1, Mul :2 , Divide : 3  Mix : 4) ?\n";
			cout << "Operator: ";
			cin >> operate;
		}
		return  operate;
	}

	// Generate random number using modern C++ random library
	int randomNumber(int start, int end)
	{

		static random_device rd;

		static mt19937 gen(rd());

		uniform_int_distribution<> dis(start, end);

		return dis(gen);

	}

	// Generate numbers based on difficulty level
	void NumberOneAndTwoAndLevel(int level) {

		switch (level) {
		case 0:
			_number1 = randomNumber(1, 10);
			_number2 = randomNumber(1, 10);
			break;

		case 1:
			_number1 = randomNumber(11, 100);
			_number2 = randomNumber(2, 20);
			break;

		case 2:
			_number1 = randomNumber(100, 1000);
			_number2 = randomNumber(11, 100);
			break;
		}

	}

	// Calculate the correct answer depending on the selected operation
	int  Result(int num1, int num2, int operate) {
		switch (operate) {

		case Operation::Plus:
			return num1 + num2;

		case Operation::Sub:
			return num1 - num2;

		case Operation::Mul:
			return num1 * num2;

		case Operation::Divide:
			if (num2 == 0) {
				return 0;
			}
			else
				return num1 / num2;

		default:
			return 0;

		}
	
	}

	// If user selects Mix operation choose a random operator
	void FilterOperator(int& operate)
	{
		if (operate == Operation::Mix) {
			operate = randomNumber(0, 3);
		}
	}

	string Operator(int operatorType) {
		switch (operatorType) {
		case Operation::Plus:
			return "+";

		case Operation::Sub:
			return "-";

		case Operation::Mul:
			return "*";

		case Operation::Divide:
			return "/";

		case Operation::Mix:
			return "Mix";

		default:
			return "";
		}
		
	}

	// If level is mix choose random level
	void FilterLevel(int& LEVEL) {
		if (LEVEL == level::mix) {
			LEVEL = randomNumber(0, 2);
		}
	}

	string LevelType(int lvl) {
		switch (lvl) {
		case level::easy:
			return "Easy";

		case level::Medium:
			return "Medium";

		case level::Hard:
			return "Hard";

		case level::mix:
			return "Mix";
		}
		return "";
	}

	// Display the question and check user's answer
	void showQuestion(int numberOfQuestion, int allQuestions, int& userInput, int num1, int num2, string operate, int result) {
		cout << "Question ( " << numberOfQuestion << " / " << allQuestions <<" ) " << endl;
		cout << num1 << " " << operate << " " << num2 << " =  ";
		cin >> userInput;

		if (userInput == result) {
			setColor(10); // green
			cout << "Right Answer\n";
			setColor(7);  
			
			cout << "\n----------------------------\n";
		}
		else {
			setColor(12); // red
			cout << "Wrong Answer\n";
			setColor(7);
			
			cout << "\n----------------------------\n";
		}

	}

};

class Math_Game
{

private:
	
	int _NumberOfQuestion;
	int _level;
	int _operate;
	int _Games;
	int _CounterGamesCorrect = 0;
	int _counterDraw = 0;
	int StartOperator;
	int StartLevel;

	int result_computer;
	int user;

	int HowManyGames() {

		int number=-1;

		cout << "How many Games do you want to play (1 to 10)?  " << endl;
		while (number < 1 || number >10) {
			cout << "Games: ";
			cin >> number;

		}

		return  number ;
	}

	Question question;

	void CounterRightQuestion(int User, int trueResult) {

		if (User == trueResult) {
			question._CounterRightQuestion++;
		}

	}

	void showGameResult()
	{
		this_thread::sleep_for(chrono::seconds(2));
		system("cls");

		cout << "\n========== Match Result ==========\n";

		cout << "Number of Questions : " << _NumberOfQuestion << endl;
		cout << "Operation Type      : " << question.Operator(StartOperator) << endl;
		cout << "Level               : " << question.LevelType(StartLevel) << endl;
		cout << "Correct Answers     : " << question._CounterRightQuestion << endl;

		cout << "----------------------------------\n";

		if (question._CounterRightQuestion > _NumberOfQuestion / 2)

		{
			_CounterGamesCorrect++;
			setColor(10);
			cout << "Result: PASS ✅\n";
			setColor(7);
			
			cout << "Advice: Good job! Keep practicing to become faster and more accurate.\n";

		}
		else if (question._CounterRightQuestion == _NumberOfQuestion / 2  && _NumberOfQuestion / 2 !=0) {
			 _counterDraw++;
			setColor(14); // yellow
			cout << "Result: Draw\n";
			setColor(7);
		}
		else
		{
			setColor(12);
			cout << "Result: FAIL ❌\n";
			setColor(7);
			cout << "Advice: Don't worry. Practice more and review the basics.\n";
		}

		cout << "==================================\n";
	}

	void showGames()
	{
		int gameLose = _Games - (_CounterGamesCorrect + _counterDraw);
		this_thread::sleep_for(chrono::seconds(3));
		int final_score = gameLose * -1 + _CounterGamesCorrect;
		
		system("cls");

		cout << "\n========== Games ==========\n";

		cout << " \nNumber of games :" << _Games << endl;

		cout << "You win     : " << _CounterGamesCorrect << endl;
		cout << "You draw     : " << _counterDraw << endl;
		cout << "You Lose    : " << gameLose<< endl;

		cout << "----------------------------------\n";

		if (final_score >=1 )
		{
			
			setColor(10);
			cout << "Result: PASS ✅\n";
			setColor(7);
			
		}
		else if (final_score==0) {
			setColor(14); // yellow
			cout << "Result: The match ended in a draw \n";
			setColor(7);
			
		}
		else
		{
			setColor(12);
			cout << "Result: FAIL ❌\n";
			setColor(7);
			
		}

		cout << "==================================\n";
	}

public:

	void start()

	{
		cout << "====================================\n";
		cout << "        WELCOME TO MATH GAME        \n";
		cout << "====================================\n";

		this_thread::sleep_for(chrono::seconds(1));
		
	
		_Games = HowManyGames();
		_CounterGamesCorrect = 0;

		for (int game = 0; game < _Games; game++)
		{
			cout << "\nGame " << game + 1 << endl;
			question._CounterRightQuestion = 0;

			_NumberOfQuestion = question.HowManyQuestion();

			_level = question.WhatALevel();

			_operate = question.WhatOperator();

			StartOperator = _operate;
			StartLevel = _level;

			for (int i = 0; i < _NumberOfQuestion; i++) {

				int currentLevel = _level;
				int currentOperator = _operate;

				question.FilterLevel(currentLevel);

				question.FilterOperator(currentOperator);

				question.NumberOneAndTwoAndLevel(currentLevel);

				result_computer = question.Result(question.num1(), question.num2(), currentOperator);

				question.showQuestion(i + 1, _NumberOfQuestion, user,
					question.num1(), question.num2(),
					question.Operator(currentOperator),
					result_computer);

				CounterRightQuestion(user, result_computer);
			}

			showGameResult();

		}

		showGames();

	}

};

int main() {

	Math_Game Math1;

	Math1.start();

}