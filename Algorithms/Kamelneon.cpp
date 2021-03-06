// Kamelneon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int check_depth(vector<vector<int>*>* m_vec)
{
	int temp, row, result;
	bool flag;
	m_vec->emplace_back(new vector<int>);
	
	for (int i = 1; i < m_vec->at(0)->size(); i++)
	{
		flag = true;

		for (int j = 0; j < m_vec->at(0)->size(); j++)
		{
			row = m_vec->at(i - 1)->at(j);
			temp = m_vec->at(0)->at(row - 1);
			m_vec->at(i)->push_back(temp);
		}

		for (int k = 0; k < m_vec->at(0)->size() - 1; k++)
		{
			if (m_vec->at(i)->at(k) > m_vec->at(i)->at(k + 1))
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			result = i;
			break;
		}

		m_vec->emplace_back(new vector<int>);
	}

	return result + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int colours, n_of_questions;
	int depth;
	int row, verse, iterations;
	int temp;

	cin >> colours;

	vector<vector<int>*> array_of_colours(1, new vector<int>);

	for (int i = 0; i < colours; i++)
	{
		cin >> temp;
		array_of_colours[0]->push_back(temp);
	}

	depth = check_depth(&array_of_colours);

	cin >> n_of_questions;

	while (n_of_questions--)
	{
		cin >> row >> iterations;

		if (iterations > 0)
		{
			verse = (iterations % depth) - 1;

			if(verse < 0)
				cout << row << "\n";
			else
				cout << array_of_colours.at(verse)->at(row - 1) << "\n";
		}
		else
			cout << row << "\n";
	}

    return 0;
}

