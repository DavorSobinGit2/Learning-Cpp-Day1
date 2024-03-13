#include <iostream>
#include "myFuncs.h"
#include <vector>
#include <fstream> // filestream library that will read our files inside of our program

class Student
{
private:
	std::string m_first = "";   // m_variables are private variables of this class
	std::string m_last  = "";
	int    m_sid   =  0;
	int    m_grade =  0;

public:
	
	// Creating a constructor
	Student()
	{

	}

	Student(const std::string & first, 
			const std::string  & last, 
			int sid, 
			int grade)

		:m_first (first)
		,m_last   (last)
		,m_sid     (sid)
		,m_grade (grade)
	{
		std::cout << "Constructor\n";
	}



	std::string getFirstName()
	{
		return m_first;
	}

	std::string getLastName()
	{
		return m_last;
	}

	int	getStudentId()
	{
		return m_sid;
	}

	int	getStudentGrade()
	{
		return m_grade;
	}

	void printInfo()
	{
		std::cout << m_first << " " << m_last << " " << m_sid << " " << m_grade << std::endl;
	}

};

class Course
{
	std::vector<Student> m_students;
	std::string          m_name;

public:

	Course(const std::string & name)
		: m_name(name)
	{
	}

	void addStudent(const Student & s)
	{
		m_students.push_back(s);
	}

	const std::vector<Student> & getStudents()
	{
		return m_students;
	}

	void print()
	{
		for (auto & s : m_students)
		{
			s.printInfo();
		}
	}

	void addStudentsFromFile(const std::string& filename)
	{
		std::ifstream fileIn(filename); // our file reader
		
		std::string first, last;
		int id, grade;

		while (fileIn >> first)
		{
			fileIn >> last >> id >> grade;

			addStudent(Student(first, last, id, grade));

		}

	}
};

int main(int argc, char* argv[])
{
	Course c("COMP4500");
	
	c.addStudentsFromFile("students.txt");

	c.print();

	return 0;
}