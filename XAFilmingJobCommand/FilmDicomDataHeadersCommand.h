#pragma once
#include "xafilmingjobcommandbase.h"
class FilmDicomDataheadersCommand :
	public XAFilmingJobCommandBase
{
public:
	virtual void Excute(const std::string& serializedParameters);
	virtual ~FilmDicomDataheadersCommand() {};
};
