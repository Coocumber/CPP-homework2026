#pragma once

#include <string>
#include <vector>

class Student
{
private:
    std::string name_;
    std::string group_;
    std::vector<int> marks_;
    double averageScore_;

    void makeAverageScore();

public:
    Student(std::string name, std::string group);
    Student(std::string name, std::string group, std::vector<int> marks);
    ~Student() = default;
    Student(const Student &other);
    Student(Student &&other);
    Student &operator=(const Student &other);
    Student &operator=(Student &&other);

    void addMark(int mark);
    std::vector<int> getMarks() const;
    double getAverageScore() const;

    friend bool operator<(const Student &lhs, const Student &rhs);
    friend bool operator>(const Student &lhs, const Student &rhs);
    friend std::ostream &operator<<(std::ostream &stream, const Student &rhs);
};