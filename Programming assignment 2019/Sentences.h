#ifndef SENTENCES_H_INCLUDED
#define SENTENCES_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

class Sentences {

    private:
        //string variable to store one sentence
        string sentence;
        //integer variable to store the number of words in one sentence
        int numWords;
        //vector of type string to store the words in a sentence
        vector<string> words;

    public:
        //Constructor
        Sentences();
        //get and set method to retrieve a sentence and to change it
        string getSentence();
        void setSentence(string s);
        //method to return the number of words in a sentence
        int getNumWords();
        //method to return all the words in a sentence (as a vector)
        vector<string> getWords();
        //Deconstructor
        ~Sentences();
};

#endif // SENTENCES_H_INCLUDED
