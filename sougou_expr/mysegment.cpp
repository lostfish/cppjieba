#include <iostream>
#include <fstream>
#include <vector>

#define LOGGER_LEVEL LL_WARN

#include "../src/MixSegment.hpp"

using namespace CppJieba;

const char * const JIEBA_DICT_FILE = "../dict/jieba.dict.utf8";
const char * const HMM_DICT_FILE = "../dict/hmm_model.utf8";
const char * const USER_DICT_FILE = "../test/testdata/userdict.utf8";

void cut(const ISegment& seg, const char * const filePath)
{
    ifstream ifile(filePath);
    vector<string> words;
    string line;
    string res;
	string s(filePath);
	s += ".seg";
	ofstream outfile(s.c_str());
    while(getline(ifile, line))
    {
        if(!line.empty())
        {
            words.clear();
            seg.cut(line, words);
            join(words.begin(), words.end(), res, " ");
            //cout<< res <<endl;
			outfile << res;
        }
    }
}

void get_file_list(const char *file_name, vector<string> &file_vec){
	ifstream infile(file_name);
	if (!infile) {
		cout << "Open file error:" << file_name << endl;
		exit(-1);
	}
	string line;
	while (getline(infile, line)) {
		file_vec.push_back(line);
	}
}

int main(int argc, char ** argv)
{
	if (argc < 2) {
		cout << "Usage: ./segment [infile]" << endl;
		cout << "Each line of [infile] is a file path" << endl;
		exit(-1);
	}
	vector<string> file_vec;
    MixSegment seg(JIEBA_DICT_FILE, HMM_DICT_FILE, USER_DICT_FILE);
	get_file_list(argv[1], file_vec);
	vector<string>::iterator itr =  file_vec.begin();
	for (; itr != file_vec.end(); ++itr) {
		cout << *itr << endl;
		cut(seg, itr->c_str());
	}
    return EXIT_SUCCESS;
}
