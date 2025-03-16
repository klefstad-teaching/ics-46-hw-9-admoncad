
#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg){
    cout << word1 << " and " << word2 << " " << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    /*
    int counter = 0;
    int length = str1.length();
    for(int i = 0; i < length; ++i){
        if(str1[i] != str2[i])
            counter += 1;
        if(counter > d)
            return false;
    }
    return true;*/
    int word1len = str1.length();
    int word2len = str2.length();
    int compare = word1len - word2len;
    if(compare < 0)
        compare *= -1;
    if(compare > 1){
        return false;}
    if(compare == 1){
        int longer = (word1len > word2len) ? 1: 2;
        for(int i = 0; i < min(word1len, word2len); ++i){
            if(str2[i] != str1[i]){
                string copy;
                if(longer == 1){
                    copy = str1;
                    copy.erase(i, 1);
                   // cout << copy << endl;
                    return edit_distance_within(copy, str2, 0);
                }
                else if (longer == 2){
                    copy = str2;
                    copy.erase(i, 1);
                    //cout << copy << endl;
                    return edit_distance_within(str1, copy, 0);
                }
            }
        }
        if(longer == 1)
            return edit_distance_within(str1.substr(0, word1len - 1), str2, 0);
        return edit_distance_within(str1, str2.substr(0, word2len -1), 0);
    }
    int counter = 0;
    int length = str1.length();
    for(int i = 0; i < length; ++i){
        if(str1[i] != str2[i])
            counter += 1;
        if(counter > d)
            return false;
    }
    return true;
}
bool is_adjacent(const string& word1, const string& word2){
    /*
    int word1len = word1.length();
    int word2len = word2.length();
    int compare = word1len - word2len;
    if(compare < 0)
        compare *= -1;
    if(compare > 1){
        return false;}
    if(compare == 1){
        int longer = (word1len > word2len) ? 1: 2;
        for(int i = 0; i < min(word1len, word2len); ++i){
            if(word1[i] != word2[i]){
                string copy;
                if(longer == 1){
                    copy = word1;
                    copy.erase(i, 1);
                   // cout << copy << endl;
                    return edit_distance_within(copy, word2, 0);
                }
                else if (longer == 2){
                    copy = word2;
                    copy.erase(i, 1);
                    //cout << copy << endl;
                    return edit_distance_within(word1, copy, 0);
                }
            }
        }
        if(longer == 1)
            return edit_distance_within(word1.substr(0, word1len - 1), word2, 0);
        return edit_distance_within(word1, word2.substr(0, word2len -1), 0);
    }
    return edit_distance_within(word1, word2, 1);
    */

    return edit_distance_within(word1, word2, 1);

}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    if (begin_word == end_word) {
        error(begin_word, end_word, "Error: Same word");
        return {};
    }
    if (word_list.find(end_word) == word_list.end()) {
        error(begin_word, end_word, "Error: end_word not in word list");
        return {};
    }

    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last = ladder.back();
        for(string word : word_list){
            if(is_adjacent(last, word)){
                if(visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream file;
    file.open(file_name);
    if(!file){
        error("file", "error", "cant open");
}
    else{
        string word;
        while(getline(file, word)){
            word_list.insert(word);
        }
    }
}
void print_word_ladder(const vector<string>& ladder){
    if(ladder.size() == 0){
        cout << "No word ladder found." << endl;
    } 
    else{
        cout << "Word ladder found: ";
        for(string word : ladder){
            cout << word << " ";
        }
        cout << endl;
    }
}
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    //print_word_ladder(generate_word_ladder("apple", "bapple", word_list));
    //my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    //my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    //my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}