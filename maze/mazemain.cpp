#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void getdata(istream&, int&, int&);
void Path(int, int);

int main(int argc, char* argv[])
{
// maze.in (.txt)�� �о����
// maze�� �̷����� ����
// Path�Լ��� �̷��� ��θ� ã�� -> ���


	int m, p;
	// m by p �̷�
	
	if (argc == 1)
		// ...?
		cerr << "Usage : " << argv[0] << "maze_data_file" << endl;
	
	else{
		ifstream is(argv[1]);
		// argv[1] = maze.in (���ϸ�)
		if (!is){cerr << argv[1] << "does not exist \n";exit(1);}
		cout << "For maze datafile (" << argv[1] << ")\n";
		getdata(is, m, p);
		is.close();
		Path(m, p);
	}
}