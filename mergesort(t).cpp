#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Docu {

    int fRst;
public:
    Docu(int fRst);
    Docu();
    friend bool operator< (const Docu &l, const Docu &r);
    friend bool operator> (const Docu &l, const Docu &r);
};

Docu::Docu(){
    fRst = 0;
}

Docu::Docu(int f){
    fRst = f;
}

bool operator< (const Docu &left, const Docu &right)
{
    return left.fRst < right.fRst;
}

bool operator> (const Docu &left, const Docu &right) {
    return left.fRst > right.fRst;
}

template <class T>
void ComB (vector <T> & a, vector<T> & x, int MiD,int s , int e){
	
	int i = s;

	int j = MiD + 1;

	int k = 0;

	while(i <= MiD && j <= e){

		if(a[i] < a[j]){

			x[k] = a[i];
			k++;
			i++;
		}

		else{
			x[k] = a[j];
			k++;
			j++;
		}
	}

	while(i <= MiD){
 		x[k] = a[i];
                k++;
                i++;
	}

	while(j <= e){
		x[k] = a[j];
                k++;
                j++;
	}

	for (i = s; i <= e; i++){
		a[i] = x[i - s];
	}
		
}

template <class T>
void msort(vector<T> & a, vector<T> & x, int s, int e) {
	
	if (s >= e) return;

	int MiD = (s + e) / 2; 

	msort(a, x, s, MiD);

	msort(a, x, MiD + 1, e);

	ComB (a, x, MiD, s, e);
}

template <class T>
void mergesort(vector<T> & a, int n) {

	int x = n.size();
	vector<T> x(n);
	msort(a, x, 0, n - 1);
}

template <class T>
bool sorted(vector<T> & a){

	for (int i = 0; i < a.size() - 1; ++i) {

		if (a[i] > a[i + 1]) return false;
	}
	return true;
}//*/

int main(int argc, char * args[]) {

	vector<int> a(1000);

	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a);	
	assert(sorted(a));

	vector<int> b(1001);
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b);
	assert(sorted(b));

	vector<int> c(1, 2);
	mergesort(c);
	assert(sorted(c));

	vector<int>  d(5);
	for (int i = 1; i <= d.size(); i++) d[i] = i;
	mergesort(d);
	assert(sorted(d));

//*/

	cout << "All tests passed." << endl;
}
