//
// Created by psp515 on 07.04.2023.
//

#ifndef LAB6_MYSTRING_MYSTRING_H
#define LAB6_MYSTRING_MYSTRING_H


#include <string>
#include <ostream>
#include <istream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class MyString {
public:
    typedef MyString value_type;

    MyString();
    MyString(const char *string);
    MyString(const MyString &text);
    explicit MyString(const string &text);

    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t capacity() const;

    [[nodiscard]] MyString join(const vector<MyString> &) const;

    [[nodiscard]] set<MyString> getUniqueWords() const;
    [[nodiscard]] map<MyString, size_t> countWordsUsageIgnoringCases() const;

    bool startsWith(const char *text) const;
    bool endsWith(const char *text) const;
    bool all_of(int predicate(int)) const;

    void clear();
    void trim();
    void trimAndOnlyAlpha();
    void toLower();
    void push_back(MyString c);

    //Iterators

    [[nodiscard]] string::const_iterator cbegin() const;
    [[nodiscard]] string::const_iterator cend() const;

    [[nodiscard]] string::iterator begin();
    [[nodiscard]] string::iterator end();

    // Op

    char operator[](size_t i) const;
    MyString &operator+=(char element);
    bool operator==(const MyString &string) const;
    bool operator<(const MyString &string) const;
    bool operator!=(const MyString &) const;
    explicit operator std::string() const;

    //Friend Op

    friend ostream& operator<<(ostream& stream, const MyString &string);
    friend istream& operator>>(istream& stream, MyString &string);

    // static
    static MyString generateRandomWord(size_t);
    static const size_t initialBufferSize_ = 20;
    static const size_t firstLetterInAscii = 65;
    static const size_t smallToLargeLetterSpanAscii = 32;
    static const size_t lettersInAlphabet = 26;
private:
    string buffer;
    size_t size_ = 0;
    size_t capacity_ = 0;

};


#endif //LAB6_MYSTRING_MYSTRING_H
