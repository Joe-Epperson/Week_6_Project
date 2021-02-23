// Joe Epperson, IV
// jee4cf@umsystem.edu
// 2/23/2021
// CS201L Lab 06

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

double CalcDistance(double x1, double x2, double y1, double y2, double z1, double z2);

void SortValues(vector<double>& distanceValues);

int main() {

	vector<double> returnVals;
	vector<double> xVal1;
	vector<double> xVal2;
	vector<double> yVal1;
	vector<double> yVal2;
	vector<double> zVal1;
	vector<double> zVal2;
	ifstream fin;
	ofstream fout;

	int r = 0;
	fin.open("input.txt");
	//Runs until the file has no more values
	while (fin.good())
	{
		double xSub1;
		double xSub2;
		double ySub1;
		double ySub2;
		double zSub1;
		double zSub2;
		double tempNum;

		//putting the values from the file into temporary variables and then inserting those values in to the correct vector
		fin >> xSub1 >> xSub2 >> ySub1 >> ySub2 >> zSub1 >> zSub2;
		xVal1.push_back(xSub1);
		xVal2.push_back(xSub2);
		yVal1.push_back(ySub1);
		yVal2.push_back(ySub2);
		zVal1.push_back(zSub1);
		zVal2.push_back(zSub2);

		//Calculating the distance based on the values at location r in each variable and storing them in the return vector for later use
		tempNum = CalcDistance(xVal1.at(r), xVal2.at(r), yVal1.at(r), yVal2.at(r), zVal1.at(r), zVal2.at(r));
		returnVals.push_back(tempNum);

		r += 1;
	}
	fin.close();

	//Sorting the distance values
	SortValues(returnVals);

	fout.open("output_sorted.txt");
	//Input the return values into the text file for all values within the return vector
	for (int w = 0; w < returnVals.size(); ++w)
	{
		fout << returnVals.at(w) << ' ';
	}
	fout.close();

	return 0;
}

double CalcDistance(double x1, double x2, double y1, double y2, double z1, double z2)
{
	double xVal;
	double yVal;
	double zVal;
	double total;

	//Calculating the distance
	xVal = x1 - x2;
	xVal = xVal * xVal;

	yVal = y1 - y2;
	yVal = yVal * yVal;

	zVal = z1 - z2;
	zVal = zVal * zVal;

	total = xVal + yVal + zVal;
	total = sqrt(total);

	return total;
}

void SortValues(vector<double>& distanceValues)
{
	int indexSmallest;
	int tempNum;
	for (int i = 0; i < distanceValues.size() - 1; ++i)
	{
		//Function to locate the lowest value within the vector
		indexSmallest = i;
		for (int j = i + 1; j < distanceValues.size(); ++j)
		{
			if (distanceValues.at(j) < distanceValues.at(indexSmallest))
			{
				indexSmallest = j;
			}
		}

		//Swap the smallest value with the current value at location i
		tempNum = distanceValues.at(i);
		distanceValues.at(i) = distanceValues.at(indexSmallest);
		distanceValues.at(indexSmallest) = tempNum;
	}
}