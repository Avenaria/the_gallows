#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
class EncryptedWordsReader {
public:
    EncryptedWordsReader(const string& fileName) : m_fileName(".../file.txt") {}

    string getDecryptedWords() {
        // Открыть файл
        ifstream inFile(m_fileName);

        // Проверить, открылся ли файл успешно
        if (!inFile) {
            cout << "Ошибка открытия файла " << m_fileName << endl;
            return "";
        }

        // Считать данные в переменную
        string encryptedWords;
        getline(inFile, encryptedWords);

        // Закрыть файл
        inFile.close();

        // Расшифровать данные
        string decryptedWords;
        for (char c : encryptedWords) {
            decryptedWords += decryptChar(c);
        }

        // Разбить расшифрованные слова на отдельные слова
        vector<string> wordsVec;
        istringstream iss(decryptedWords);
        string word;
        while (iss >> word) {
            wordsVec.push_back(word);
        }

        // Соединить слова в строку и вернуть ее
        ostringstream oss;
        copy(wordsVec.begin(), wordsVec.end(), ostream_iterator<string>(oss, " "));
        return oss.str();
    }

private:
    const string m_fileName;

    char decryptChar(char c) {
        // Ваш код для расшифровки символа
        return c - 1;
    }
};
int main() {

}