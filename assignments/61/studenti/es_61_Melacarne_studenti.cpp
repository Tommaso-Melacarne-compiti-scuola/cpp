#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

constexpr int MAX_VOTE = 10;
constexpr int STUDENT_VOTES = 5;
constexpr int STUDENTS = 10;
constexpr int MAX_NAME_LENGTH = 10;
constexpr int PRECISON_FACTOR = 100;
constexpr int YEAR_PARTS = 2;

const array<string, 8> SUBJECTS = {"Matematica", "Fisica", "Chimica", "Biologia", "Storia", "Geografia", "Letteratura",
                                   "Arte"};

// A vote with a value
typedef struct {
    float value;
} Vote;

// A subject with a name and a vector of votes
typedef struct {
    string name;
    vector<Vote> votes;
} Subject;

typedef struct {
    vector<Subject> subjects;
} YearPart;

// A student with a name, a surname and a vector of subjects
typedef struct {
    string name;
    string surname;
    vector<YearPart> yearParts;
} Student;

// Returns a random vote with a maximum value of maxValue
Vote getRandomVote(float maxValue) {
    Vote vote{
            .value = (float) (rand() % (int) (maxValue * PRECISON_FACTOR) / (float) PRECISON_FACTOR)
    };
    return vote;
}

// Returns a vector of n random votes with a maximum value of maxValue
vector<Vote> getRandomVotes(int n, float maxValue) {
    vector<Vote> votes;
    votes.reserve(n);
    for (int i = 0; i < n; i++) {
        votes.push_back(getRandomVote(maxValue));
    }
    return votes;
}

// Returns a subject with a specific name, n random votes and a maximum value of maxValue
Subject getRandomSubject(string name, int nVotes, float maxValue) {
    Subject subject{
            .name = std::move(name),
            .votes = getRandomVotes(nVotes, maxValue)
    };
    return subject;
}

// Returns a vector of subjects with random n votes in each subject, with a maximum value of maxValue
vector<Subject> getRandomSubjects(int nVotes, float maxValue) {
    vector<Subject> subjects;

    subjects.reserve(SUBJECTS.size());

    for (const string &subject: SUBJECTS) {
        subjects.push_back(getRandomSubject(subject, nVotes, maxValue));
    }

    return subjects;
}

// Returns a vector of n year parts with random subjects
vector<YearPart> getRandomYearParts(int n) {
    vector<YearPart> yearParts;
    yearParts.reserve(n);
    for (int i = 0; i < n; i++) {
        YearPart yearPart{
                .subjects = getRandomSubjects(STUDENT_VOTES, MAX_VOTE)
        };
        yearParts.push_back(yearPart);
    }
    return yearParts;
}

// Returns a random string of length n
string getRandomString(int length) {
    constexpr int ALPHABET_START = 26;
    constexpr int ALPHABET_END = 97;

    string str;
    str.reserve(length);
    for (int i = 0; i < length; i++) {
        str.push_back((char) (rand() % ALPHABET_START + ALPHABET_END));
    }
    return str;
}

// Returns a vector of n random students
vector<Student> getRandomStudent(int n) {
    vector<Student> students;
    students.reserve(n);
    for (int i = 0; i < n; i++) {
        Student student{
                .name = getRandomString(MAX_NAME_LENGTH),
                .surname = getRandomString(MAX_NAME_LENGTH),
                .yearParts = getRandomYearParts(YEAR_PARTS)
        };

        students.push_back(student);
    }
    return students;
}

// Returns the average of the votes in a subject
float getSubjectAverage(const Subject &subject) {
    float sum = 0;
    for (const auto &vote: subject.votes) {
        sum += vote.value;
    }
    return sum / (float) subject.votes.size();
}

float getYearPartAverage(const YearPart &yearPart) {
    float sum = 0;
    for (const auto &subject: yearPart.subjects) {
        sum += getSubjectAverage(subject);
    }
    return sum / (float) yearPart.subjects.size();
}

// Returns the average of the votes of a student
float getStudentAverage(const Student &student) {
    float sum = 0;
    for (const auto &yearPart: student.yearParts) {
        sum += getYearPartAverage(yearPart);
    }
    return sum / (float) student.yearParts.size();
}

// Returns the student with the highest average
Student getStudentWithMaxAverage(const vector<Student> &students) {
    Student maxStudent = students[0];
    float maxAverage = getStudentAverage(maxStudent);

    for (const auto &student: students) {
        float average = getStudentAverage(student);
        if (average > maxAverage) {
            maxAverage = average;
            maxStudent = student;
        }
    }

    return maxStudent;
}

// Prints all the student's  information
void printStudent(const Student &student) {
    cout << "Nome: " << student.name << "\n";
    cout << "Cognome: " << student.surname << "\n";
    cout << "Voti: \n";
    for (const auto &yearPart: student.yearParts) {
        for (const auto &subject: yearPart.subjects) {
            cout << subject.name << ": ";
            for (const auto &vote: subject.votes) {
                cout << vote.value << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    vector<Student> students = getRandomStudent(STUDENTS);

    Student maxStudent = getStudentWithMaxAverage(students);

    cout << "Studente con la media più alta: " << endl;
    printStudent(maxStudent);

    return 0;
}