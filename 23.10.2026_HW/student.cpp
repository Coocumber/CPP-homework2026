#include <iostream>

#include "student.h"

Student::Student(std::string name, std::string group)
    : name_(std::move(name)), group_(std::move(group)), averageScore_(0)
{
}

Student::Student(std::string name, std::string group, std::vector<int> marks)
    : name_(std::move(name)), group_(std::move(group)), marks_(std::move(marks))
{
    makeAverageScore();
}

Student::Student(const Student &other)
{
    name_ = other.name_;
    group_ = other.group_;
    marks_ = other.marks_;
    averageScore_ = other.averageScore_;
}

Student::Student(Student &&other)
{
    name_ = std::move(other.name_);
    group_ = std::move(other.group_);
    marks_ = std::move(other.marks_);
    averageScore_ = other.averageScore_;

    averageScore_ = 0.0;
}

Student Student::operator=(const Student &other)
{
    name_ = other.name_;
    group_ = other.group_;
    marks_ = other.marks_;
    averageScore_ = other.averageScore_;

    return *this;
}

Student Student::operator=(Student &&other)
{
    name_ = std::move(other.name_);
    group_ = std::move(other.group_);
    marks_ = std::move(other.marks_);
    averageScore_ = other.averageScore_;

    averageScore_ = 0.0;

    return *this;
}

void Student::addMark(int mark)
{
    marks_.push_back(mark);
    makeAverageScore();
}

void Student::makeAverageScore()
{
    averageScore_ = 0;

    for (const int &mark : marks_)
    {
        averageScore_ += mark;
    }
    averageScore_ /= marks_.size();
}

std::vector<int> Student::getMarks() const
{
    return marks_;
}

double Student::getAverageScore() const
{
    return averageScore_;
}

std::ostream &operator<<(std::ostream &stream, const Student &rhs)
{
    stream << "Name: " << rhs.name_;
    stream << " Group: " << rhs.group_;
    stream << " Marks: ";
    for (const int &elem : rhs.marks_)
    {
        stream << elem << " ";
    }
    stream << " Average score_: " << rhs.averageScore_;
    return stream;
}

bool operator>(const Student &lhs, const Student &rhs)
{
    return rhs < lhs;
}

bool operator<(const Student &lhs, const Student &rhs)
{
    return lhs.averageScore_ < rhs.averageScore_;
}