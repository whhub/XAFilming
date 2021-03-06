#include "XAFilmingSerializer.h"
#include "XAFilmingLogger.h"

#include "CommunicationCommandID.h"
#include <sstream>
#include "XAFilmingMacro.h"

using namespace  std;

template<class T>
string serialize(const vector<T>& collection, const string& separator)
{
    auto size = collection.size();
    if(size <= 0) {return XA_FILMING_EMPTY_STRING;}

	auto iter = collection.begin();
	stringstream ss;
	ss << *iter++;
	for (; iter != collection.end(); ++iter)
	{
		ss << separator << *iter;
	}
	return ss.str();;
}

template<class T>
string serialize(const vector<T>& collection)
{
    return serialize<T>(collection, PARAMETER_LIST_SEPARATOR);
}

string serialize(const vector<int>& collection)
{
    return serialize<int>(collection);
}

string serialize(const vector<string>& collection)
{
    return serialize<string>(collection);
}

int string_to_int(const string& numberInStringType)
{
	LOG_INFO_XA_FILMING << "converting [" << numberInStringType << "] to int" << LOG_END;
	stringstream ss;
	ss << numberInStringType;
	int result;
	ss >> result;
	LOG_INFO_XA_FILMING << "result : [" << result << "]" << LOG_END;
	return result;
}

string int_to_string(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

bool string_to_bool(const std::string& boolInStringType)
{
	stringstream ss;
	ss << boolInStringType;
	bool result = false;
	ss >> result;

	return result;
}

string bool_to_string(bool b)
{
	stringstream ss;
	ss << b;
	return ss.str();
}

int double_to_percentage(double d)
{
	return static_cast<int>(d*100);
}

void split(const string serializedString, const string& separator, vector<string> & splitStringVector)
{
	LOG_INFO_XA_FILMING << "Spliting [" << serializedString << "] with separator [" << separator << "]" << LOG_END;

	size_t begin = 0;
	size_t end = serializedString.find(separator, begin);
		
	while(string::npos != end)
	{
		string item = serializedString.substr(begin, end-begin);
		splitStringVector.push_back(item);
		
		begin = end + separator.size();
		end = serializedString.find(separator, begin);
	}

	string lastItem = serializedString.substr(begin);
	splitStringVector.push_back(lastItem);
}

void join(const vector<string>& stringVector, const string& separator, string& joinedString)
{
	LOG_INFO_XA_FILMING << "Joinning series with separator [" << separator << "]" << LOG_END;

    joinedString = serialize<string>(stringVector, separator);
}

void serializeStrings(const vector<string>& stringVector, string& serializedString)
{
	LOG_INFO_XA_FILMING << "serializing strings " << LOG_END;
	join(stringVector, PARAMETER_LIST_SEPARATOR, serializedString);
}

void deserializeStrings(const string& serializedString, vector<string>& splitStringVector)
{
	LOG_INFO_XA_FILMING << "Deserializing [" << serializedString << "]" <<  LOG_END;
	split(serializedString, PARAMETER_LIST_SEPARATOR, splitStringVector);
}


