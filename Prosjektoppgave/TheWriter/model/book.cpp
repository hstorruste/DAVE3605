#include "book.h"

Book::Book() :
    name{"John Doe"}, pageGoal{350}, totalWordsWritten(MAX_QUALITY,0), wordsThisHour(MAX_QUALITY,0)
{

}

Book::Book(std::string bookName) :
    name{bookName}, pageGoal{350}, totalWordsWritten(MAX_QUALITY,0), wordsThisHour(MAX_QUALITY,0)
{

}

Book::Book(std::string name_,
           int pageGoal_,
           std::vector<int> &words_written_this_hour_,
           std::vector<int> &words_total_) :
    name{name_}, pageGoal{pageGoal_}
{

    wordsThisHour = words_written_this_hour_;
    totalWordsWritten = words_total_;
}

void Book::insertwords(int count, int wordQuality)
{
    if(wordQuality < 1)
        wordQuality=1;
    if(wordQuality > MAX_QUALITY)
        wordQuality=MAX_QUALITY;

    wordsThisHour[wordQuality-1]+=count;
    totalWordsWritten[wordQuality-1]+=count;

}

std::vector<int> *Book::getWordsThisHour()
{
    return &wordsThisHour;
}

void Book::resetHour()
{
    for(int i{0}; i < MAX_QUALITY; ++i)
        wordsThisHour[i]=0;
}

bool Book::finished()
{
    return getNumberOfPages() == pageGoal;
}

// Getter klasser
std::string Book::getName() const
{
    return name;
}
std::string Book::getString(){
    return "Title: "+name;
}

int Book::getPageGoal() const
{
    return pageGoal;
}

std::vector<int> *Book::getWordsWritten()
{
    return &totalWordsWritten;
}


int Book::getWordsPrPage() const
{
    return wordsPrPage;
}

double Book::getQuality()
{
    int wrds= getNumberOfWords();
    if(wrds > 0)
        return getTotalQuality()/wrds;
    else
        return 0.0;
}

double Book::getTotalQuality() const
{
    double quality{0};
    for(int i{0}; i < MAX_QUALITY; ++i)
    {
        quality+=(double)totalWordsWritten[i]*(i+1);
    }

    return quality;
}



int Book::getNumberOfWords()
{
    int numWrds{0};
    for(int i{0}; i < MAX_QUALITY; ++i)
    {
        numWrds+=totalWordsWritten[i];
    }
    return numWrds;
}

int Book::getNumberOfPages()
{
    return getNumberOfWords()/wordsPrPage;
}




std::string Book::toStr(){
    return name;
}

Book::~Book()
{

}

