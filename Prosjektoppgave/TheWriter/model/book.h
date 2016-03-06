#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book
{

public:
    Book();
    Book(std::string bookName);
    Book(std::string name_,
         int pageGoal_,
         std::vector<int> &words_written_this_hour_,
         std::vector<int> &words_total_);
    std::string getString();
    ~Book();

    std::string getName() const;
    /** Returns the number of pages that is set as a goal for this book*/
    int getPageGoal() const;

    /** Returns a pointer to the vector of total words in this book */
    std::vector<int>* getWordsWritten();

    /** Inserts words with pageQuality into the book between 1 and MAX_QUALITY.*/
    void insertwords(int count, int wordQuality);

    /** Returns a pointer to the vector of wordsThisHour */
    std::vector<int>* getWordsThisHour();

    /** Has to be called at the end of an hour. It saves all words the last hour to totalWordsWritten,
     * updates words statistics, and empties the vector*/
    void resetHour();

    /** Returns number of words written */
    int getNumberOfWords();

    /** Returns the number of pages required for each page */
    int getWordsPrPage() const;

    /** Returns the quality of the book so far. Ranged from 1.0 to MAX_QUALITY.
     * (0.0 if there is no pages) */
    double getQuality();

    /** Returns true if pageGoal is reached */
    bool finished();

    /** Returns number of pages written */
    int getNumberOfPages();

    std::string toStr();

private:
    std::string name;
    int pageGoal;
    const int wordsPrPage{259};
    const int MAX_QUALITY = 10;

    /** A vector containing the number of pages of each quality,
     *  from 1(index 0) to MAX_QUALITY(index MAX_QUALITY-1)*/
    std::vector<int> totalWordsWritten; //Contains every word written
    std::vector<int> wordsThisHour; //Words the last hour - statistical use

    /** Returns a number <= MAX_QUALITY*pageGoal */
    double getTotalQuality() const;

};

#endif // BOOK_H
