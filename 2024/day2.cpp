#include<bits/stdc++.h>
#include <string>

bool IsSafe(const std::vector<int>& row)
{
	for (int i = 1; i < row.size(); i++)
	{
		const bool isLastIteration = i == row.size() - 1;

		const int difference = row[i - 1] - row[i];
		const bool direction = row[i - 1] > row[i];

		if (abs(difference) > 3 || abs(difference) == 0)
			return false;

		if (!isLastIteration)
		{
			const bool nextDirection = row[i] > row[i + 1];

			if (nextDirection != direction)
				return false;


			const int nextDifference = row[i] - row[i + 1];
			if (abs(nextDifference) > 3 || abs(nextDifference) == 0)
				return false;
		}
	}

	return true;
}

int NumSafeReports(const std::vector < std::vector<int>>& data)
{
	int numSafeReports = 0;
	for (auto row : data)
	{
		numSafeReports += IsSafe(row);
	}

	return numSafeReports;
}

int NumSafeReportsWithProblemDampener(const std::vector < std::vector<int>>& data)
{
	int numSafeReports = 0;
	int rowIdx=0;
	for (auto row : data)
	{
		bool isSafe = false;
		rowIdx++;

		IsSafe(row);
		for (size_t i = 0; i < row.size(); i++)
		{
			std::vector<int> correctedRow = row;
			correctedRow.erase(correctedRow.begin() + i);

			if (IsSafe(correctedRow))
			{
				isSafe = true;
				break;
			}
		}

		if (isSafe) {
			numSafeReports++;
			std::cout<<rowIdx<<std::endl;
		}
	}

	return numSafeReports;
}

