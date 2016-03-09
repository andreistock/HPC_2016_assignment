#include<iostream>
#include<vector>
#include<random> 
#include<cstdlib>
#include<math.h>
#include<algorithm>
double square(double k)
{
	k=pow(k,2);
	return k;
}
void print(double i)
{
	std::cout<<i<<"\n";
}
bool compareFunction(double i,double j)
{
	return i<j;
}
int main() 
{
	
	const int vSize = 50;
	std::vector<double> vVector(vSize,0);
	double vMatrix[vSize][vSize];
	for (unsigned int i = 0; i < vSize; ++i) {
		for (unsigned int j = 0; j < vSize; ++j) {
			vMatrix[i][j] = i + j;
		}
	}
	std::cout<<vMatrix[23][26]<<"\n";
	for (unsigned int j = 0; j < vSize;++j)
	{
		//Accessing vector
		vVector[j]=sin(j);
		std::cout<<vVector[j]<<"\n";
	}

	for_each(vVector.begin(),vVector.end(),square);   //use of for_each algorithm with square function
	for_each(vVector.begin(),vVector.end(),print);
	sort(vVector.begin(),vVector.end(),compareFunction);
	for_each(vVector.begin(),vVector.end(),print);
	if(binary_search(vVector.begin(),vVector.end(),
		0,compareFunction))
	{
		std::cout<<"Found it \n";
	}
	std::cout<<vVector[4]<<"\n";
//	std::cout<<vVector.size()<<"\n";
}