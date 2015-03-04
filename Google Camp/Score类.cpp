#include <iostream>
#include <cstring>
using namespace std;
class Score {
public:
	Score(char* name_, int score_);    // Constructs an object with its name and score
	Score(Score &obj);    // Constructs an object with another object
	~Score();    // Destructs the object
	void print();    // Output the name and the score
private:
	char* name;    // The name of the student
	int score;    // The score of the student
};

Score::Score(char* name_, int score_) {
    name = new char[strlen(name_)];
    strcpy(name, name_);
    score = score_;
}

Score::Score(Score &obj) {
    name = new char[strlen(obj.name)];
    strcpy(name, obj.name);
    score = obj.score;
}

Score::~Score() {
    delete name;
}

void Score::print() {
	cout << this->name << ':' << this->score << endl;
}
