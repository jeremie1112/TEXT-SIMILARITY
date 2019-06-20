#include <iostream>
#include <ostream>
#include <fstream>
#include "Sentences.h"

using namespace std;

int main() {

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"                        TEXT SIMILARITY                          "<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<">                                                               <"<<endl;
    cout<<">                Programming Assignment 2019                    <"<<endl;
    cout<<">_______________________________________________________________<"<<endl;
    cout<<">                      : WORKING TEAM :                         <"<<endl;
    cout<<">_______________________________________________________________<"<<endl;
    cout<<">STUDENT1: JEREMIE DANIEL                                       <"<<endl;
    cout<<">STUDENT2: GEESHAM HOSANEE                                      <"<<endl;
    cout<<">_______________________________________________________________<"<<endl;
    cout<<">ID      : 1812415 && 1812260                                   <"<<endl;
    cout<<">_______________________________________________________________<"<<endl;
    cout<<">                                                               <"<<endl;
    cout<<">Faculty of Information, Communication and Digital Technologies,<"<<endl;
    cout<<">      Department of Information Communication Technology,      <"<<endl;
    cout<<">                  Computer Science Year 1                      <"<<endl;
    cout<<">                  UNIVERSITY OF MAURITIUS                      <"<<endl;
    cout<<">_______________________________________________________________<"<<endl;
    cout<<">                                                               <"<<endl;




    ///SENTENCES
    ///1st vector variable to store the individual words in one sentence
    vector<string> wordsFromSentence1;

    ///2nd vector variable to store the individual words in one sentence
    vector<string> wordsFromSentence2;

    ///1st vector variable to store all the sentences from the dataset
    vector<string> allSentences;

    ///temporary string variable to store each sentence from the dataset
    string sentenceFromFile;

    ///integer variable to count the number of 1st lines/sentences in the dataset
    int countSentence = 0;

    ///codes to load the sentences dataset from a text file into 1st vector
    ifstream infile;
  	infile.open ("datasetSentences.txt");
    while(!infile.eof()) {
        getline(infile,sentenceFromFile);
        allSentences.push_back(sentenceFromFile);
        countSentence++;
    }
	  infile.close();

    ///creating a vector of objects of type sentences
    vector<Sentences> s1(countSentence);

    ///creating a vector of objects of type sentences
    vector<Sentences> s2(countSentence);

    ///assign each extracted sentence (from dataset) to one Sentence object
    for(int i=0; i<countSentence; i++){
        s1[i].setSentence(allSentences[i]);
        s2[i].setSentence(allSentences[i]);
    }



    ///GJ means the percentage of similarity. Example enter 0.5
    float GJ = 0.0;
    cout<<">     Input the percentage of similarity[0 to 1]                <"<<endl;
    cout<<"> :";
    cin>>GJ;

    if (GJ > 1 || GJ < 0){
      cout<<"  Error as percentage is either more than 1 or less than 0     "<<endl;
      return -1;
    }

    cout<<">                                                               <"<<endl;
    cout<<">                                                               <"<<endl;
    cout<<">          This may take time as it is a big dataset            <"<<endl;
    cout<<">                     Please be patient                         <"<<endl;
    cout<<">                        Loading...                             <"<<endl;
    cout<<">                                                               <"<<endl;
    cout<<">                                                               <"<<endl;

    ///initializing AnB where A is word[a],
    ///                       B is word[b],
    ///                       n is intersection,
    ///                       u is union
    ///AnB returns the number of similar words in a text
    ///AuB return the number of the 2 sentence minus AnB
    float AnB;
    float AuB;


    ///for loop 1 for the dataset
    for(int i=0; i<countSentence; i++){
       ///for loop 2 for the same dataset
       ///!(i==j) i must not equal to j as it will always give 1 as score.
       for(int j=0; j<countSentence && !(i==j) ; j++){
            cout<<endl<<"1st. THIS IS SENTENCE No "<<i+1<<" : ";
            cout<<endl<<s1[i].getSentence()<<endl;
            cout<<endl;
            cout<<endl<<"2nd. THIS IS SENTENCE No "<<j+1<<" : ";
            cout<<endl<<s2[j].getSentence()<<endl;


            ///assigning words from sentence[i] into wordsFromSentence1
            ///assigning words from sentence[j] into wordsFromSentence2
            wordsFromSentence1 = s1[i].getWords();
            wordsFromSentence2 = s2[j].getWords();

            ///comparing word[a] in sentence[i] == word[b] in sentence[j]
            for(int a=0; a<wordsFromSentence1.size(); a++){
               for(int b=0; b<wordsFromSentence2.size(); b++){

                   string one = wordsFromSentence1[a];
                   string two = wordsFromSentence2[b];

                   ///dont forget that it is case sensitive
                   ///example:
                   /// this != This
                   /// thus it wont count
                   /// need to convert the first letter in first word into lower case
                   /// convert A to a is +32

                   if (isupper(one[0])){
                       one[0] = one[0] + 32;
                   }
                   if (isupper(two[0])){
                       two[0] = two[0] + 32;
                   }

                   //This piece of code is written as these words cannot be taken for account as they logically 
                   //sentences with these words cannot be similar
                   if (one == "is" || one == "a" || two == "is" || two == "a"){
                       continue;
                   }

                   ///testing if word[a] == word[b]
                   if (one == two){
                          ///if true then add one to the counter AnB
                          AnB++;
                   }
               }
            }
            ///to get AuB, number of words in sentence[i] + number of words in sentence[j] - AnB
            AuB = (s1[i].getNumWords()+s2[j].getNumWords()-AnB);
            cout<<endl;


            ///initialize score which returns the score of AnB/AuB
            float score = 0.0;

            score = AnB/AuB;
 
            //logically if AnB is > AuB, the score must be one
            if (AnB > AuB){
                score = 1.0;
                AnB = s1[i].getNumWords();
                AuB = s1[i].getNumWords();
            }
            cout<<"AuB is: "<<AuB<<endl;
            cout<<"AnB is: "<<AnB<<endl;

            ///if the score is more than GJ then they are similar, else they are not
            if (score > GJ){
              cout<<"The sentence "<<i+1<<" and "<<j+1<<" are similar with a score of : "<<score<<endl;
            }
            else{
              cout<<"The sentence "<<i+1<<" and "<<j+1<<" are not similar with a score of : "<<score<<endl;
            }
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

            ///initializing again so that it dont keep adding previous values
            AuB = 0.0;
            AnB = 0.0;
       }
     }
     cout<<endl;
     cout<<endl;
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
     cout<<"                       PROGRAM ENDS HERE                         "<<endl;
     cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

}
