#ifndef REPOSITORY_H
#define REPOSITORY_H

#include"Error.h"
#include<iostream>
#include<fstream>
using namespace std;

template <class T>
class Repository {
	T* entities;
	int maxCapacity;
	int currentCapacity;

public:
	Repository(int maxCapacity = 100)
	{
		entities = new T[maxCapacity];
		this->maxCapacity = maxCapacity;
		currentCapacity = 0;
		LoadFlightsFromFile();
	}

	~Repository()
	{
		delete[] entities;
	}

	void Add(T& item)
	{
		if (currentCapacity >= maxCapacity)
			throw Error(ErrorCode::MaxSizeReached);

		entities[currentCapacity++] = item;

	}

	void Remove(int idx)
	{
		if (idx < 0 || idx >= currentCapacity)
			throw Error(ErrorCode::IdxOutsideLimit);

		for (int i = idx; i < (currentCapacity - 1); i++)
			entities[i] = entities[i + 1];

		currentCapacity--;
	}

	void Print()
	{
		cout << GetTitle() << endl;
		for (int i = 0; i < currentCapacity; i++)
		{
			cout << i << " | " + (*this)[i]  + " | " << endl;
		}

	}

	void ShowTheLongestByDurationFlight()
	{
		if (currentCapacity == 0)
		{
			throw Error(ErrorCode::EmptyFlightsList);
		}

		T* longestFlight = &entities[0];
		for (int i = 0; i < currentCapacity; i++)
		{
			if (entities[i] > *longestFlight)
			{
				longestFlight = &entities[i];
			}
		}
		cout << *longestFlight;

	}

protected:
	virtual string GetTitle() { return ""; }
	virtual string GetFileName() { return ""; }
	virtual void LoadFlightsFromFile() { return; }
	
	void WriteFlightsToFile()
	{
		ofstream fout(GetFileName());
		for (int i = 0; i < currentCapacity; i++)
		{
			fout << entities[i].ToCsvString() << endl;
		}
		fout.close();
	}

	T& operator[](int idx)
	{
		return this->entities[idx];
	}

	
};
#endif // !REPOSITORY

