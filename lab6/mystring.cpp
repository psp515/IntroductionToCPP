//
// Created by psp515 on 07.04.2023.
//

#include "mystring.h"
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

MyString::MyString(): buffer(string()), size_(buffer.size()), capacity_(initialBufferSize_ + buffer.capacity())
{
    buffer.reserve(initialBufferSize_);
}
MyString::MyString(const char string[]) : buffer(string), size_(buffer.size()), capacity_(initialBufferSize_ + buffer.capacity())
{
    buffer.reserve(initialBufferSize_);
}
MyString::MyString(const MyString &string) : buffer(string.buffer), size_(buffer.size()), capacity_(initialBufferSize_ + buffer.capacity()) {}
MyString::MyString(const string &string) : buffer(string), size_(buffer.size()), capacity_(initialBufferSize_ + buffer.capacity()) {}

size_t MyString::size() const {
    return size_;
}
size_t MyString::capacity() const {
    return capacity_;
}
bool MyString::empty() const {
    return size_ == 0;
}

MyString MyString::join(const vector<MyString> &vector) const {

    MyString string;

    std::copy(vector.begin(), vector.end(), std::back_inserter(string));

    return string;
}

set<MyString> MyString::getUniqueWords() const{
    auto wordSet = set<MyString>();

    auto map = countWordsUsageIgnoringCases();

    std::set<MyString> tmpSet;

    transform(map.cbegin(), map.cend(), inserter(tmpSet, tmpSet.begin()),
              [](const pair<MyString, int>& value)
              {
                return value.first;
              });

    return tmpSet;
}
map<MyString, size_t> MyString::countWordsUsageIgnoringCases() const{

    auto wordMap = map<MyString, size_t>();

    auto is_space = [](char c) { return std::isspace(c); };
    auto it = buffer.begin();
    auto jit = buffer.begin();

    while (it != buffer.end()) {
        it = std::find_if_not(it, buffer.end(), is_space);
        jit = std::find_if(it, buffer.end(), is_space);

        auto d1 = it - buffer.begin();
        auto d2 = jit - buffer.begin();
        std::string word = buffer.substr(d1, d2 - d1);


        MyString my_string_word(word);
        my_string_word.toLower();
        my_string_word.trimAndOnlyAlpha();

        if (wordMap.find(my_string_word) == wordMap.end())
            wordMap.insert(std::pair<MyString, size_t>(my_string_word, 1));
        else
            wordMap.find(my_string_word)->second++;
        it = jit;
    }

    return wordMap;
}

bool MyString::startsWith(const char *text) const {
    MyString str_text = MyString(text);
    return std::search(cbegin(), cend(), str_text.cbegin(), str_text.cend()) == cbegin();
}
bool MyString::endsWith(const char *text) const {
    MyString str_text = MyString(text);
    return std::search(cbegin(), cend(), str_text.cbegin(), str_text.cend()) == (cend() - str_text.size());
}
bool MyString::all_of(int (*predicate)(int)) const {
    return std::all_of(cbegin(), cend(), predicate);
}

void MyString::clear() {
    buffer.clear();
    size_ = 0;
    capacity_ = 0;
}
void MyString::trim() {

    auto wsfront=std::find_if_not(buffer.begin(),buffer.end(),[](int c)
    {
        return std::isspace(c);
    });
    auto wsback=std::find_if_not(buffer.rbegin(),buffer.rend(),[](int c)
    {
        return std::isspace(c);
    }).base();

    buffer = wsback<=wsfront ? std::string() : std::string(wsfront,wsback);

    size_ = buffer.size();
    size_ = buffer.capacity();
}
void MyString::trimAndOnlyAlpha() {
    trim();

    auto wsfront=std::find_if_not(buffer.begin(),buffer.end(),[](int c)
    {
        return !std::isalpha(c);
    });
    auto wsback=std::find_if_not(buffer.rbegin(),buffer.rend(),[](int c)
    {
        return !std::isalpha(c);
    }).base();

    buffer = wsback<=wsfront ? std::string() : std::string(wsfront,wsback);

    size_ = buffer.size();
    size_ = buffer.capacity();

}

void MyString::toLower() {
    transform(cbegin(), cend(), begin(), [](char element)
    {
        return tolower(element);
    });
}

string::const_iterator MyString::cbegin() const {
    return buffer.cbegin();
}
string::const_iterator MyString::cend() const {
    return buffer.cend();
}
string::iterator MyString::begin() {
    return buffer.begin();
}
string::iterator MyString::end() {
    return buffer.end();
}

char MyString::operator[](size_t i) const {

    if(i >= size_)
        throw out_of_range("Invalid index.");

    return buffer[i];
}
MyString &MyString::operator+=(char element) {
    buffer += element;
    size_++;
    capacity_ = buffer.capacity();
    return *this;
}
bool MyString::operator==(const MyString &string) const {
    if (size() != string.size_)
        return false;

    auto output = std::mismatch(cbegin(), cend(), string.cbegin(), string.cend());
    return output.first == cend() && output.second == string.cend();
}
bool MyString::operator<(const MyString &string) const {
    return buffer.compare(string.buffer) < 0;
}
bool MyString::operator!=(const MyString &string) const {
    if (size() != string.size_)
        return true;

    auto output = std::mismatch(cbegin(), cend(), string.cbegin(), string.cend());
    return !(output.first == cend()) || !(output.second == string.cend());
}

ostream &operator<<(ostream &stream, const MyString &string) {
    stream << string.buffer;
    return stream;
}
istream &operator>>(istream &stream, MyString &string) {
    std::string tmp;

    while(stream >> tmp)
        string.buffer.append(tmp + " ");

    string.size_ = string.buffer.size();
    string.size_ = string.buffer.capacity();

    return stream;
}

MyString MyString::generateRandomWord(size_t wordSize) {
    string buff(wordSize, ' ');

    for(size_t i = 0; i < wordSize; i++)
    {
        size_t random_char = firstLetterInAscii + (rand() % lettersInAlphabet);

        if (rand() % 2)
            random_char += 32;


        buff[i] = (char) random_char;
    }

    return MyString(buff);
}


MyString::operator std::string() const {
    return buffer;
}

void MyString::push_back(MyString element) {

    if (size_ == 0)
        buffer += element.buffer;
    else
        buffer += ", " + element.buffer;

    size_ = buffer.size();
    capacity_ = buffer.capacity();
}

