#include <iostream>
#include "fraction.h"

/**
  @mainpage Laboratorium 1 - ułamki

  Tresc zadan dla Panstwa (aktualniejsza jest w `README.md`)
  --------
Zadanie 0: absolutnie obowiazkowe, chociaz bez punktow
1. Pierwsza rzecza jest poprawa bledow kompilacji,
   czyli wpisanie poprawnych Panstwa danych w pliku: @ref main.cpp
2. Oddanne zadanie musi sie bezwzglednie kompilowac na systemie Linux:
   - Jesli sie nie skompiluje to jest to 0 punktow za zadanie!
   - Oczywiscie w razie problemow z kompilacja prosze się zgłaszać/pisać.
   - Dobrze, jesli nie byloby warningow kompilacji, ale za to nie obnizam punktow.
   - Aby się upewnić, że się kompiluje można skorzystać z [narzędzia Bobot](https://gitlab.com/agh-courses/bobot)
3. Oddane zadanie nie powinno crashować na żadnym teście,
   jeśli crashuje proszę zrobic implementacje -fake, ktora nie dopusci do crasha nawet jesli test bedzie failowal,
   ale za to testy nie beda sie crashowaly.
   W przypadku crasha biorę pod uwagę tylko tyle testów, ile przejdzie do czasu crasha!
4. Mam program antyplagiatowy, dlatego prosze pracowac samodzielnie!
   - Osoby ktore udostepniaja swoje rozwiazania rowniez beda mialy kare!
   - Na ukaranie prowadzący ma czas 2 tygodnie po terminie oddania,
      czyli nawet jak ktoś otrzyma punkty wcześniej ma pewność, że za oszustwa/łatwowierność dosięgnie go
      niewidzialna ręka sprawiedliwości.
5. Zadanie z zalozenia bedzie sprawdzane automatycznie, przez testy jednostkowe dostepne w pliku: @ref fractionTests.cpp,
6. *Dobrze jakby nie bylo warningow kompilacji (flagi: `-Wall -Wextra -pedantic -Werror`, a dla hardcorów jeszcze:  `-Weffc++`)
7. Punkty beda odejmowane za wycieki pamieci (jest podpiety `valgrind`)
8. Niewykluczone jest sprawdzanie reczne - zaleznie od prowadzacego dana grupe.

Tresc do implementacji - szukaj w plikach *.h
**/

constexpr const char* const FIRSTNAME = "Łukasz";
constexpr const char* const SURNAME   = "Kolber";
constexpr const char* const MAIL    = "410566@student.agh.edu.pl";
constexpr const char* const BOOK_ID = "410566";
constexpr const char* const TEACHER_MAIL = "bemaj@agh.edu.pl";

void validateStudentsInfo();


int main()
{
    std::cout << "Hello " << FIRSTNAME << " " << SURNAME << "!" << '\n'
              << "make Your teacher: " << TEACHER_MAIL << " proud of you!" << std::endl;
              
    validateStudentsInfo();
}


constexpr inline size_t compileTimeStrlen(const char* text) noexcept
{
    size_t len = 0;

    while (text[len] != '\0')
        len++;

    return len;
}

constexpr inline size_t compileTimeCountFirstDigits(const char* text) noexcept
{
    return (*text && ('0'<=*text && *text<='9') ? 1+compileTimeCountFirstDigits(text+1) : 0);
}

constexpr inline bool compileTimeIsDigit(const char* text) noexcept
{
    return compileTimeStrlen(text) == compileTimeCountFirstDigits(text);
}

constexpr inline bool compileTimeContains(const char* text, char letter) noexcept
{
    if ('\n' == *text)
        return false;

    return *text == letter ? 1 : compileTimeContains(text+1, letter);
}

void validateStudentsInfo()
{
    static_assert(compileTimeStrlen(FIRSTNAME) > 2, "You must input your first name!");
    static_assert(compileTimeStrlen(SURNAME) > 2, "You must input your surname!");

    static_assert(compileTimeStrlen(BOOK_ID) > 1, "You must input your student book id!");
    static_assert(compileTimeIsDigit(BOOK_ID), "You student book id should consist only digits, shouldn't it?!");

    static_assert(compileTimeStrlen(MAIL) > 3, "You must input your mail (preferred AGH mail)!");
    static_assert(compileTimeContains(MAIL, '@'), "Invalid mail! It should contain '@'!");
    static_assert(compileTimeContains(MAIL, '.'), "Invalid mail! It should contain '.'!");
}