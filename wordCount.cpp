#include <iostream> 
#include <fstream> //operate on files 
#include <sstream> //needed for stringstream, which is needed for tokenizing the file
#include <string>
using namespace std;

// takes a .txt file in folder running this code and returns its word count 
// case sensitive (upper and lower case words won't be counted only as one word)

int main () {
    string filename;
    cout << "Enter the name of the text file" << endl;
    cin >> filename;
    
    ifstream inputFile; //input stream for files
    inputFile.open(filename);

    if (!inputFile) {
        cerr << "Error: Could not open or file doesn't exist" << endl;
        // cerr prints error messages (using cerr, you can later change the error stream 
        // to write the errors to a file)
        return 1;
    }
    int count = 0;
    string line;
    
    while (getline(inputFile,line)) {
        //getline takes into account spaces between words, so a whole line with spaces
        // 
        stringstream tokenizer(line); //used to make a tokenizer
        string word;

        while (tokenizer >> word) {
            count++;
        }
        // In the context of the program using stringstream, the statement while 
        // (tokenizer >> word) is a loop that extracts words from the stringstream  
        // object tokenizer, and stores each word in the string variable word. The 
        // loop continues until there are no more words left in the stringstream.
    }
    cout << "The file " << filename << " contains " << count << " words." <<  endl;
    return 0;
}