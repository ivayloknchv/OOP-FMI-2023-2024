#include <iostream>

namespace constraints 
{
	constexpr int MAX_SIZE = 51;
	
	constexpr int MAX_QUESTIONS = 5;

	constexpr int MAX_ANSWERS = 4;
}

enum class Answers
{
	A,
	B,
	C,
	D
};

enum class ErrorMessage {
	OK,
	invalidAnswer
};

struct Question 
{
	char answers[constraints::MAX_ANSWERS][constraints::MAX_SIZE];
	char title[constraints::MAX_SIZE];
	Answers answer;
	int points;
};

struct FinalResult
{
	ErrorMessage error;
	int points;
};

struct Test 
{
	int questionCount;
	Question allQuestions[constraints::MAX_QUESTIONS];
};


void printQuestion(const Question& question)
{
	std::cout << question.title<<std::endl;

	char answerLetter = 'a';

	for (int i = 0; i < constraints::MAX_ANSWERS; i++)
	{
		answerLetter = 'A' + i;
		std::cout << answerLetter << ") " << question.answers[i]<<std::endl;
	}
}

Answers getAnswer(const char ch)
{
	switch (ch)
	{
	case 'a':
	case 'A':
		return Answers::A;
		break;
	case 'b':
	case 'B':
		return Answers::B;
		break;
	case 'c':
	case 'C':
		return Answers::C;
		break;
	case 'd':
	case 'D':
		return Answers::D;
		break;
	default: return Answers::D; break;
	}
}

bool checkAnswer(const Question& question, const char ch)
{
	return (getAnswer(ch) == question.answer);
}

bool checkIfValidAnswer(const char ch)
{
	return (ch >= 'a' && ch <= 'd') || (ch >= 'A' && ch <= 'D');
}

FinalResult getTotalPoints(const Test& test)
{
	int total = 0;
	char answer = 'a';

	for (int i = 0; i < test.questionCount; i++)
	{
		printQuestion(test.allQuestions[i]);

		std::cin >> answer;

		if (checkIfValidAnswer(answer) == false)
		{
			return { ErrorMessage::invalidAnswer, total };
		}

		if (checkAnswer(test.allQuestions[i], answer))
		{
			total += test.allQuestions[i].points;
		}
	}

	return {ErrorMessage::OK, total};
}

int main()
{
	Question q1 = { {"Sofia","Ivanoskow","Solun","Zarigrad"}, "What is the capital of Old Disciplinia?", Answers::B, 20 };
	Question q2 = { {"Kyroan","Riebenport","Berlein","Kanzstadt"}, "What is the capital of Deirroren Kanzlernd?", Answers::A, 40 };

	Test t;

	t.allQuestions[0] = q1;

	t.allQuestions[1] = q2;

	t.questionCount = 2;

	FinalResult result = getTotalPoints(t);
	if (result.error == ErrorMessage::OK)
	{
		std::cout << "Total points: "<< result.points << std::endl;
	}

	else
	{
		std::cout << "You have entered wrong symbol!" << std::endl;
	}
	return 0;
}
