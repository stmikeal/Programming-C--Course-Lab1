#include "iostream"
#include "string"
#include <fstream>

using namespace std;

int generate_file(string pre_path) {
	ifstream fin(("sample/input/" + pre_path).c_str());
	ofstream fout(("sample/output/" + pre_path).c_str());

	string type1, type2;
	fin >> type1;
	fin >> type2;

	cout << "Sample: " << pre_path << ", types: " << type1 << ' and ' << type2  << endl;
	
	fout << "#include <iostream>" << endl;
	fout << "int f(void) {"<< endl;
	fout << type1 << " var1 = 1;"<< endl;
	fout << type1 << " var2 {3};"<< endl;
	fout << "std::cout << var1 + var2 << std::endl;"<< endl;
	fout << "return 0;" << endl;
	fout << "}" << endl;
	fout.close();
}

int main(int argc, char* argv[]){
	if (argc > 1) {
		for(int arg_index = 1; arg_index < argc; arg_index++) {
			generate_file(string(argv[arg_index]));
		}
	} else {
		string path;
		cout << "Enter sample name: "  << endl;
		cin >> path;
		generate_file(path);
	}
	return 0;
}
