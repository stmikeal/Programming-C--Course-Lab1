#include "iostream"
#include "string"
#include <fstream>
#include <filesystem>
#include <map>
#include <regex>

using namespace std;
using namespace std::filesystem;

std::string input_path {"./sample/input/"}, 
			template_path {"./sample/template/"};



int generate_tests(string input_path, string template_path) {
	string line;
	map<string, string> macro_table;

	ifstream farg(input_path);
	if (farg.is_open()) {
		farg >> macro_table["type1"] >> macro_table["type2"] >> macro_table["value1"] >> macro_table["value2"];
		macro_table["sample_name"] = input_path.substr(input_path.find("input/") + 6);
	} else {
		return 1;
	}
	farg.close();

	ifstream fin(template_path);
	ofstream fout(regex_replace(input_path, regex("input"), "output") + 
				template_path.substr(template_path.find("_")));

	while(fin.is_open() && fout.is_open() && getline(fin,line)) {
		for (const auto& [macro, value] : macro_table) {
			line = regex_replace(line, regex(macro), value);
		}
		fout << line << endl;
	}

	fin.close();
	fout.close();
	return 0;
}

int main(int argc, char* argv[]){
    for (auto &ip : directory_iterator(input_path)) {
		for (auto &tp : directory_iterator(template_path)) {
        	generate_tests(ip.path(), tp.path());
		}
	}
	return 0;
}
