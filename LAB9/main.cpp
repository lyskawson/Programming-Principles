#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>



// task2
void changeNewlineForSpace(std::string& str)
{
    //std::replace(str.begin(), str.end(), '\n', ' ');
    for(int i; i<str.size(); i++)
    {
        if(str[i]='\n')
            str[i]=' '; // deosnt work 
    }
}

// task3
int countWords(const std::string& str)
{
    int count = 0;
    bool inWord = false;

    for (char c : str)
    {
        if (!std::isspace(c))
        {
            if (!inWord)
            {
                inWord = true;
                ++count;
            }
        }
        else
        {
            inWord = false;
        }
    }

    return count;
}

//task4 I method
bool czyPalindrome1(const std::string& str)
{
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

//task4 II method
bool isPalindrome2(const std::string& str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1])
            return false;
    }

    return true;
}


// task5
int stringToNum(const std::string& str)
{
    int result = 0;
    for (char c : str)
    {
        if (std::isdigit(c))
        {
            result = result * 10 + (c - '0');
        }
    }
    return result;
}


std::string numToString(int num)
{
    std::string result;
    if (num == 0)
    {
        result = "0";
    }
    else
    {
        while (num > 0)
        {
            result = static_cast<char>((num % 10) + '0') + result;
            num /= 10;
        }
    }
    return result;
}

// Task 6
std::vector<int> countLetters(const std::string& str)
{
    std::vector<int> hist(26, 0);  // Indeksy 0-25 reprezentują litery od a do z
    for (char c : str)
    {
        if (std::isalpha(c))
        {
            hist[std::tolower(c) - 'a']++; //a' - 'a' = 0, 'b' - 'a' = 1, and so on
        }
    }

    return hist;
}

// Zadanie 7
int biggestNumber(const std::string& str)
{
    int maxNumber = 0;
    int currentNumber = 0;

    for (char c : str)
    {
        if (std::isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        }
        else
        {
            maxNumber = std::max(maxNumber, currentNumber);
            currentNumber = 0;
        }
    }

    return std::max(maxNumber, currentNumber);
}

// task8
bool areAnagrams(std::string &str1, std::string &str2)
{

    int l1 = str1.length();
    int l2 = str2.length();

    if (l1 != l2)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < l1; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}


int main() {


    std::string str1 = "Ala ma kota";

    std::string str2 = "W książce jest 10 rozdziałów po 21 stron";

    std::string str3 = "W Szczebrzeszynie\nChrzaszcz\nBrzmi W Trzcinie";

    std::string str4 = "radar";

    std::string str5 = "    ";

    std::string str6 = "   wyraz   ";

    std::string str7 = "listen";
    std::string str8 = "silent";

    //task2
    changeNewlineForSpace(str3);
    std::cout << "After changing new line to space:\n" << str3 << std::endl;

    //task3
    std::cout << "Num of words in str1: " << countWords("Ala ma kota") << std::endl;
    std::cout << "Num of words in str2: " << countWords("W książce jest 10 rozdziałów po 21 stron") << std::endl;
    std::cout << "Num of words in str3: " << countWords("W Szczebrzeszynie\nChrzaszcz\nBrzmi W Trzcinie") << std::endl;

    //task4
    std::cout << "Is str4 an palindrone? " << std::boolalpha << isPalindrome2(str4) << std::endl;

    //task5
    std::cout << "String to num: " << stringToNum("12345") << std::endl;
    std::cout << "Number to string : " << numToString(6789) << std::endl;

    //task6
    std::vector<int> hist = countLetters("str1");
    std::cout << "Histogram of leters:\n";
    for (int i = 0; i < 26; i++)
    {
        char letter = 'a' + i;
        std::cout << letter << ": " << hist[i] << " ";
    }
    std::cout << std::endl;

    //task7
    std::cout << "Biggest number in str2': " << biggestNumber(str2) << std::endl;

    //task8
    std::cout << "Czy 'listen' i 'silent' to anagramy? " << std::boolalpha << areAnagrams(str7, str8) << std::endl;

    return 0;


}
