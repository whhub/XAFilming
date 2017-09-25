#pragma once

#include "McsfNetBase/mcsf_netbase_interface.h"

#include "XAFilmingMacro.h"
using namespace MCSF_NAMESPACE_FOR_XA;


class XAFilmingServiceCommandHandler : public ICommandHandler
{
public:


	XAFilmingServiceCommandHandler()
	{
	}

	virtual int HandleCommand(const CommandContext* pContext, std::string* pReplyObject);

private:
	XA_FILMING_DISALLOW_COPY_AND_ASSIGN(XAFilmingServiceCommandHandler)
};