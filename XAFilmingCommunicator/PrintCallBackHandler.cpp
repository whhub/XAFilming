#include "PrintCallbackHandler.h"
#include <XAFilmingLogger.h>
#include "XAFilmingSerializer.h"

using namespace std;

int PrintCallbackHandler::HandleReply(const MCSF_NAMESPACE_FOR_XA::IAsyncResult* pAsyncResult)
{
	string result = pAsyncResult->GetMarshalObject();
	LOG_INFO_XA_FILMING << "Print Command Result : [" << result << "],  Call Result: [" << pAsyncResult->GetCallResult() << "]" << LOG_END;

	for (auto iter = _printStatusObservers.begin(); iter != _printStatusObservers.end(); iter++)
	{
		IPrintResultObserver* pObserver = *iter;
		pObserver->NotifyPrintResult(result);		
	}

	return 0;
}

void PrintCallbackHandler::Register(IPrintResultObserver* pObserver)
{
	LOG_INFO_XA_FILMING << "Register a print status observer" << LOG_END;
	_printStatusObservers.push_back(pObserver);
}

PrintCallbackHandler::~PrintCallbackHandler()
{
	_printStatusObservers.clear();
}
