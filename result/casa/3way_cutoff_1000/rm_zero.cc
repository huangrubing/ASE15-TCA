// =====================================================================================
//
//       Filename:  rm_zero.cc
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年04月27日 09时58分48秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jinkun Lin, jkunlin@gmail.com
//   Organization:  School of EECS, Peking University
//
// =====================================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>
#include <cmath>


using namespace std;

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "./stat <in_file> <out_file>" << endl;
	}
	ifstream in_file(argv[1]);
	if (!in_file.is_open()) {
		cout << "in_file error: " << argv[1] << endl;
		return 1;
	}
	ofstream out_file(argv[2]);
	if (!out_file.is_open()) {
		cout << "out_file error" << argv[2] << endl;
		return 1;
	}
	string line;
	while (getline(in_file, line)) {
		istringstream is(line);
		double run_time, sys_time;
		char ch;
		double size;
		is >> run_time >> ch >> sys_time >> size;
		if (run_time > 1000 || sys_time > 1000) {
			cout << "cutoff time met: " << argv[1] << endl;
			abort();
		}
		if (size == 0) {
			cout << "with end : " << argv[1] << endl;
			return 0;
		}
		out_file << run_time << ch << sys_time << '\t' << size << endl;
	}
	return 0;
}
