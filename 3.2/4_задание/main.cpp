#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <windows.h>
#include <fstream>


void ReadFile(std::ifstream& file, std::set<std::string>& all_fish, std::set<std::string>& fisherman_1, std::set<std::string>& fisherman_2, std::set<std::string>& fisherman_3) {
    std::string string, delims = " ", word;
    int32_t i = 0;
    while (std::getline(file, string))
    {
        size_t BegInd, EndInd;
        BegInd = string.find_first_not_of(delims);
        while (BegInd != std::string::npos)
        {
            EndInd = string.find_first_of(delims, BegInd);
            if (EndInd == std::string::npos)
                EndInd = string.length();
            word = string.substr(BegInd, EndInd - BegInd);
            switch (i)
            {
            case 0:
                all_fish.insert(word);
                break;
            case 1:
                fisherman_1.insert(word);
                break;
            case 2:
                fisherman_2.insert(word);
                break;
            case 3:
                fisherman_3.insert(word);
                break;
            default:
                throw std::invalid_argument("Слишком много строк во входном файле\n");
            }
            BegInd = string.find_first_not_of(delims, EndInd);
        }
        ++i;
    }
    if (i < 3)
        throw std::invalid_argument("Слишком мало строк во входном файле\n");
}

void CheckFile(std::ifstream& file)
{
    if (!file)
        throw std::invalid_argument("Входной файл не существует");
    if (!file.is_open())
        throw std::invalid_argument("Входной файл не открыт");
    if (file.peek() == EOF)
        throw std::invalid_argument("Входной файл пустой");
}

void CheckFile(std::ofstream& file)
{
    if (!file)
        throw std::invalid_argument("Выходной файл не существует");
    if (!file.is_open())
        throw std::invalid_argument("Выходной файл не открыт");
}

void PrintSet(const std::set<std::string>& set, const std::string& message, std::ofstream& file) {
    file << message << ": ";
    if (set.begin() == set.end())
    {
        file << "Отсутствуют";
    }
    for (auto i = set.begin(); i != set.end(); ++i) {
        file << *i << " ";
    }
    file << '\n';
}

std::set<std::string> Union(const std::set<std::string>& set1, const std::set<std::string>& set2) {
    std::set<std::string> result;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));
    return result;
}


std::set<std::string> Difference(const std::set<std::string>& set1, const std::set<std::string>& set2) {
    std::set<std::string> result;
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));
    return result;
}

std::set<std::string> SymmetricDifference(const std::set<std::string>& set1, const std::set<std::string>& set2) {
    std::set<std::string> result;
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(result, result.begin()));
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream ifile("Input.txt");
    std::ofstream outfile("Output.txt");
    try
    {
        CheckFile(ifile);
        CheckFile(outfile);
        std::set<std::string> fisherman_1;
        std::set<std::string> fisherman_2;
        std::set<std::string> fisherman_3;
        std::set<std::string> all_fish;

        ReadFile(ifile, all_fish, fisherman_1, fisherman_2, fisherman_3);
        
        PrintSet(fisherman_1, "Рыбы, пойманные рыбаком 1", outfile);
        PrintSet(fisherman_2, "Рыбы, пойманные рыбаком 2", outfile);
        PrintSet(fisherman_3, "Рыбы, пойманные рыбаком 3", outfile);
        std::set<std::string> CaughtFishByAnybody = Union(Union(fisherman_1, fisherman_2), fisherman_3);
        PrintSet(CaughtFishByAnybody, "Рыбы, пойманные хотя бы одним рыбаком", outfile);
        std::set<std::string> fishNotCaught = Difference(all_fish, CaughtFishByAnybody);
        PrintSet(fishNotCaught, "Рыбы в озере, не пойманные ни одним рыбаком", outfile);
        std::set<std::string> fishCaughtByOnlyOne = SymmetricDifference(fisherman_1, SymmetricDifference(fisherman_2, fisherman_3));
        PrintSet(fishCaughtByOnlyOne, "Рыбы, пойманные только одним рыбаком", outfile);
    }
    catch (std::invalid_argument& mistake) { std::cout << mistake.what(); }
    std::cout << "Программа завершила работу\n";
    ifile.close();
    outfile.close();
    return 0;
}

