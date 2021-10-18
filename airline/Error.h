#ifndef ERROR_H
#define ERROR_H

#include<string>
using namespace std;

enum ErrorCode
{
	WrongDate,
	EmptyFlightsList,
	IdxOutsideLimit,
	MaxSizeReached
};

class Error
{
private:
	ErrorCode code;
public:
	Error(ErrorCode code);
	string ToString();
};

#endif // !ERROR_H

