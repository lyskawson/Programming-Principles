#include <iostream>
#include <fstream>

struct Student{
    std::string firstName;
    std::string lastName;
    std::string gender;
    std::string pesel;
    int id;
};

void display_student(const Student& student)
{
    std::cout << "First name: " << student.firstName << std::endl;
    std::cout << "Last name: " << student.lastName << std::endl;
    std::cout << "Gender: " << student.gender << std::endl;
    std::cout << "PESEL: " << student.pesel << std::endl;
    std::cout << "Index number: " << student.id << std::endl;
    std::cout << "====================================="<<std::endl;
}

Student read_student_data() {
    Student s;
    std::cout << "Enter first name: ";
    std::getline(std::cin, s.firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, s.lastName);
    std::cout << "Enter gender: ";
    std::cin >> s.gender;
    std::cout << "Eneter PESEL: ";
    std::cin >> s.pesel;
    std::cout << "Enter index number: ";
    std::cin >> s.id;
    return s;
}

void display_all_students(const std::vector<Student> &students)
{
    for (const auto& student : students)
    {
        display_student(student);
    }
};

int find_student(const std::vector<Student> &students, int id)
{
    for (size_t i=0; i < students.size();i++)
    {
        if(students[i].id == id)
            return i;
    }
    return -1;
}

void add_student(std::vector<Student>& students, const Student& newStudent)
{
    students.push_back(newStudent);
}

void remove_student(std::vector<Student>& students, int id)
{
    int index = find_student(students, id);
    if (id != -1)
    {
        students.erase(students.begin() + index);
        std::cout << "Student with id  " << id <<   " has been deleted." << std::endl;
    }
    else
        std::cout << "Student not found." << std::endl;
}

void save_students(const std::vector<Student>& students, const std::string &filename)
{
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students)
        {
            file << student.firstName << " " << student.lastName << " " << student.gender << " " << student.pesel << " "<< student.id << std::endl;
        }
        file.close();
        std::cout << "Data saved" << std::endl;
    }
    else
        std::cout << "Cannot open file" << std::endl;
}

void load_students(std::vector<Student>& students, const std::string& filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        students.clear();
        Student s;
        while (file >> s.firstName >> s.lastName >> s.gender >> s.pesel >> s.id)
        {
            students.push_back(s);
        }
        file.close();
        std::cout << "Data loaded" << std::endl;
    }
    else
        std::cout << "Cannot read file" << std::endl;
}

int main()
{
    std::vector<Student> students;

    Student s1{"Brad", "Pitt", "male","1234", 123456 };
    Student s2{"Scarlett", "Johansson", "female", "5678", 345678};
    Student s3{"Bill", "Murray", "male", "3762", 234567};
    //add_student(students, s1);
    //add_student(students, s2);
    //add_student(students, s3);
    //add_student(students, read_student_data());

    //remove_student(students, 123456 );

    //save_students(students, "students.txt");
    load_students(students, "students.txt");

    display_all_students(students);

    return 0;
}
