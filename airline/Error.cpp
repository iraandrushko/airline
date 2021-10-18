#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::ToString()
{
	switch (code)
	{
	case EmptyFlightsList:
		return "The flight list is empty";
	case WrongDate:
		return "The date is wrong";
	case IdxOutsideLimit:
		return "Index is outside the limit";
	case MaxSizeReached:
		return "Max size reached";
	default:
		return "";
	}
}